/**
 * @file Dispositivo.cpp
 * @author ujapoo
 */

#include "Dispositivo.h"

Dispositivo::Dispositivo(const std::string &descripcion, float consumo)
    : descripcion(descripcion), consumo(consumo) {

}
const std::string &Dispositivo::getDescripcion() const {
    return descripcion;
}

float Dispositivo::getConsumo() const {
    return consumo;
}

bool Dispositivo::isActivo() const {
    return activo;
}

/** Cambia el estado de actividad del dispositivo
 */
void Dispositivo::conmutaEstado() {
    if (this->activo==false) {
        this->activo=true;
    } else {
        this->activo=false;
    }
}

