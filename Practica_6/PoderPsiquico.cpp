//
// Created by stefan on 10/04/2023.
//

#include "PoderPsiquico.h"

PoderPsiquico::PoderPsiquico():Poder() {
}

PoderPsiquico::PoderPsiquico(std::string nombre, std::string descripcion, std::string afecta_a,
                             float capacidad_destructiva): Poder(nombre, descripcion, afecta_a, capacidad_destructiva) {
}

PoderPsiquico::PoderPsiquico(const PoderPsiquico &original): Poder(original) {
}

PoderPsiquico::~PoderPsiquico() {
}

PoderPsiquico &PoderPsiquico::operator=(const PoderPsiquico &original) {
    if(this != &original){
        this->Poder::operator=(original);
    }
}