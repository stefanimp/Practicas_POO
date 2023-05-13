/**
 * @file Generador.cpp
 * @author ujapoo
 */
#include "Generador.h"

Generador::Generador(const std::string &cadena, float potencia)
    : modelo(cadena), potencia(potencia) {

}

const std::string &Generador::getModelo() const {
    return modelo;
}

float Generador::getPotencia() const {
    return potencia;
}
