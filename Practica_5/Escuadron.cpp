//
// Created by stefan on 19/03/2023.
//

#include "Escuadron.h"


Escuadron::Escuadron(std::string nombre, std::string base):
nombre(nombre),
num_pilotos(num_pilotos),
base(base){
    num_pilotos = 0;
    integrantes = nullptr;
}

Escuadron::Escuadron(std::string nombre, int num_pilotos, std::string base, Piloto **integrantes):
nombre(nombre),
num_pilotos(num_pilotos),
base(base),
integrantes(integrantes){
}

Escuadron::Escuadron(const Escuadron &original):
nombre(original.nombre),
num_pilotos(original.num_pilotos),
base(original.base),
integrantes(original.integrantes){
}

Escuadron::~Escuadron() {}

void Escuadron::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Escuadron::setBase(std::string base) {
    this->base = base;
}

void Escuadron::setIntegrantes(Piloto **integrantes, int num_integrantes) {
    this->num_pilotos = num_integrantes;
    this->integrantes = integrantes;
}

std::string Escuadron::getNombre() const {
    return nombre;
}

std::string Escuadron::getBase() const {
    return base;
}

int Escuadron::getNumPilotos() const {
    return num_pilotos;
}

Piloto **Escuadron::getIntegrantes() const {
    return integrantes;
}

void Escuadron::agnadirPiloto(Piloto *piloto) {
    if(num_pilotos == MAX_PILOTOS){
        throw std::invalid_argument("Escuadron::agnadirPiloto(): Se ha alcanzado el numero maximo de integrantes");
    }
    ++num_pilotos;
    Piloto **copia = new Piloto * [num_pilotos];
    for (int i = 0; i < num_pilotos - 1; ++i) {
        copia[i] = integrantes[i];
        integrantes[i] = nullptr;
    }
    delete[] integrantes;

    copia[num_pilotos - 1] = piloto;

    integrantes = copia;
}

void Escuadron::agnadirPiloto(std::string nombre) {
    if(num_pilotos == MAX_PILOTOS){
        throw std::length_error("Escuadron::agnadirPiloto(): Se ha alcanzado el numero maximo de integrantes");
    }
    ++num_pilotos;
    Piloto **copia = new Piloto * [num_pilotos];
    for (int i = 0; i < num_pilotos - 1; ++i) {
        copia[i] = integrantes[i];
        integrantes[i] = nullptr;
    }
    delete[] integrantes;

    copia[num_pilotos - 1] = new Piloto(nombre);

    integrantes = copia;
}

float Escuadron::promedioMisiones() {
    float total_misiones = 0;
    for (int i = 0; i < num_pilotos; ++i) {
        total_misiones += integrantes[i]->getNumMisiones();
    }
    return (total_misiones/num_pilotos);
}

void Escuadron::fromCSV(std::string valores) {
    std::stringstream ss;
    ss.str(valores);
    std::getline(ss,this->nombre,';');
    ss>> this->num_pilotos;
    ss.ignore(1);
    std::getline(ss, this->base,';');
}

bool Escuadron::piezaDefectuosa(std::string NombrePiezaDefectuosa) const {
    for (int i = 0; i < num_pilotos; ++i) {
        if (integrantes[i]->piezaDefectuosa(NombrePiezaDefectuosa)){
            return true;
        }
    }
    return false;
}
