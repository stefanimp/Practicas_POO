//
// Created by stefan on 27/04/2023.
//
#include "Espada.h"

Espada::Espada(std::string descripcion):descripcion(descripcion) {

}

Espada::~Espada() {
}

std::string Espada::getDescripcion() const {
    return ("Una espada: "+descripcion);
}