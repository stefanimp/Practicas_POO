//
// Created by stefan on 08/05/2023.
//

#include "Bloque.h"

#include <sstream>

Bloque::Bloque()
        :Bloque(1){
}

Bloque::Bloque(int cuantos)
        :ItemApilable(cuantos){
}

Bloque::Bloque(const Bloque& orig)
        :ItemApilable(orig){
}

Bloque::~Bloque() {
}

std::string Bloque::getDescripcion() {
    std::stringstream ss;

    ss << "Bloque de tierra ("
       << getNumElementos() << ") ";


    return ss.str();
}