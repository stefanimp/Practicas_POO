/**
 * @file Mutante.cpp
 * @author algarcia
 *
 */

#include <stdexcept>
#include <sstream>

#include "Mutante.h"

Mutante::Mutante(string nombre, string apodo, int fechaN, string nacionalidad)
    : _nombreReal(nombre),
      _apodo(apodo),
      _fechaDeNacimiento(fechaN),
      _nacionalidad(nacionalidad),
      num_poderes(0),
      poderes(nullptr)
      {
    
}

Mutante::Mutante(const Mutante& orig)
    : _nombreReal(orig._nombreReal),
    _apodo(orig._apodo),
    _fechaDeNacimiento(orig._fechaDeNacimiento),
    _nacionalidad(orig._nacionalidad),
    num_poderes(orig.num_poderes){
    poderes = new Poder * [num_poderes];
    for (int i = 0; i < num_poderes; ++i) {
        poderes[i] = new Poder(*orig.poderes[i]);
    }
}

Mutante::~Mutante() {
    for (int i = 0; i < num_poderes; ++i) {
        delete poderes[i];
        poderes[i] = nullptr;
    }
    delete[] poderes;
    poderes = nullptr;
}

void Mutante::setNombreReal(string nombreReal) {
    this->_nombreReal = nombreReal;
}

string Mutante::getNombreReal() const {
    return _nombreReal;
}

void Mutante::setNacionalidad(string nacionalidad) {
    this->_nacionalidad = nacionalidad;
}

string Mutante::getNacionalidad() const {
    return _nacionalidad;
}

void Mutante::setFechaDeNacimiento(int fechaDeNacimiento) {
    this->_fechaDeNacimiento = fechaDeNacimiento;
}

int Mutante::getFechaDeNacimiento() const {
    return _fechaDeNacimiento;
}

void Mutante::setApodo(string apodo) {
    this->_apodo = apodo;
}

string Mutante::getApodo() const {
    return _apodo;
}


/**@brief Representación CSV de un mutante
   @post  Genera la representación básica en CSV, sin incluir los poderes*/
string Mutante::toCSV() const{
    std::stringstream aux;
    aux << _nombreReal << ";"
            << _apodo << ";"
            << _fechaDeNacimiento << ";"
            << _nacionalidad;

    return aux.str();
}

Mutante& Mutante::operator=(const Mutante& orig) {
    if (this != &orig) {
        _nombreReal = orig._nombreReal;
        _apodo = orig._apodo;
        _fechaDeNacimiento = orig._fechaDeNacimiento;
        _nacionalidad = orig._nacionalidad;

    }

    return  *this;
}

void Mutante::addPoder(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva) {
    if(num_poderes == MAX_PODERES){
        throw std::length_error("Mutante::addPoder: se ha alcanzado el número máximo de poderes");
    }
    Poder **copia = new Poder * [++num_poderes];
    for (int i = 0; i < num_poderes - 1; ++i) {
        copia[i] = poderes[i];
        poderes[i] = nullptr;
    }
    delete[] poderes;

    copia[num_poderes-1] = new Poder(nombre, descripcion, afecta_a, capacidad_destructiva);

    poderes = copia;
}

void Mutante::desplazarPoderesIzquierda(int posicion) {
    for (int i = posicion; i < num_poderes-1; ++i) {
        poderes[i] = poderes[i+1];
    }
    poderes[num_poderes-1] = nullptr;
}

void Mutante::borrarPoder(int cual) {
    if(cual <= 0 || cual > MAX_PODERES){
        throw std::invalid_argument("Mutante::borrarPoder: no existe poder en la posición indicada");
    }
    this->desplazarPoderesIzquierda(cual);

    Poder **copia = new Poder * [--num_poderes];

    for (int i = 0; i < num_poderes; ++i) {
        copia[i] = poderes[i];
        poderes[i] = nullptr;
    }
    delete[] poderes;

    poderes = copia;
}

float Mutante::capacidadDestructivaTotal() const {
    float capacidad_d_total = 0;
    for (int i = 0; i < num_poderes; ++i) {
        capacidad_d_total += poderes[i]->getCapacidadDestructiva();
    }
    return capacidad_d_total;
}