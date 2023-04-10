//
// Created by stefan on 10/04/2023.
//
#include "PoderFisico.h"
PoderFisico::PoderFisico():Poder() {
}

PoderFisico::PoderFisico(std::string nombre, std::string descripcion, std::string afecta_a,
                             float capacidad_destructiva): Poder(nombre, descripcion, afecta_a, capacidad_destructiva) {
}

PoderFisico::PoderFisico(const PoderFisico &original): Poder(original) {
}

PoderFisico::~PoderFisico() {
}

PoderFisico &PoderFisico::operator=(const PoderFisico &original) {
    if(this != &original){
        this->Poder::operator=(original);
    }
}