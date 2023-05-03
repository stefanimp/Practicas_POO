//
// Created by stefan on 02/05/2023.
//

#include "Filete.h"

Filete::Filete(std::string descipcion):descripcion(descipcion) {
}

Filete::~Filete() {
}

std::string Filete::getDescripcion() const {
    return ("Filete: "+ descripcion);
}