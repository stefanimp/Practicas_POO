//
// Created by stefan on 02/05/2023.
//

#include "Bloque.h"

Bloque::Bloque(std::string descripcion, int cantidad): ItemApilable(cantidad),descripcion(descripcion) {
}

Bloque::~Bloque() noexcept {
}

std::string Bloque::getDescripcion() const {
    //Para transformar el número de elementos en un string hacemos uso del stringstream
    std::stringstream ss;
    ss<<" "<<ItemApilable::getNumElmentos();

    return ("Bloque: " + descripcion + ss.str());
}