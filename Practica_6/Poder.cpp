//
// Created by stefan on 10/04/2023.
//
#include "Poder.h"

Poder::Poder(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva):
nombre(nombre),
descripcion(descripcion),
afecta_a(afecta_a),
capacidad_destructiva(capacidad_destructiva){
}

Poder::Poder(const Poder &original):nombre(original.nombre),
descripcion(original.descripcion),
afecta_a(original.afecta_a),
capacidad_destructiva(original.capacidad_destructiva){
}

Poder::~Poder() {
}

void Poder::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Poder::setDescripcion(std::string descripcion) {
    this->descripcion = descripcion;
}

void Poder::setAfecta(std::string afecta_a) {
    this->afecta_a = afecta_a;
}

void Poder::setCapacidadDestructiva(float capaciadad_destructiva) {
    this->capacidad_destructiva = capaciadad_destructiva;
}

std::string Poder::getNombre() const {
    return nombre;
}

std::string Poder::getDescripcion() const {
    return descripcion;
}

std::string Poder::getAfectaA() const {
    return afecta_a;
}

float Poder::getCapacidadDestructiva() const {
    return capacidad_destructiva;
}

Poder &Poder::operator=(const Poder &original) {
    if(this != &original){
        nombre = original.nombre;
        descripcion = original.descripcion;
        afecta_a = original.afecta_a;
        capacidad_destructiva = original.capacidad_destructiva;
    }
    return *this;
}

std::string Poder::toCSV() const {
    std::stringstream aux;
    aux<<"Nombre: " <<nombre <<" ; " <<"Descripcion: " <<descripcion <<" ; " << "Afecta a: " <<afecta_a <<" ; " <<"Capacidad destructiva: " <<capacidad_destructiva;

    return aux.str();
}