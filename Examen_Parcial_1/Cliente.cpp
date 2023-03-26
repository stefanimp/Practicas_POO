//
// Created by stefan on 27/03/2023.
//

#include "Cliente.h"

Cliente::Cliente(std::string nombre, std::string direccion):
nombre(nombre),
direccion(direccion){
}

Cliente::~Cliente() {}

void Cliente::setNombre(std::string nombre) {
    this->nombre = nombre;
}

void Cliente::setDireccion(std::string direccion) {
    this->direccion = direccion;
}


std::string Cliente::getNombre() const {
    return nombre;
}

std::string Cliente::getDireccion() const {
    return direccion;
}