//
// Created by stefan on 13/05/2023.
//

#include "RackServidores.h"

RackServidores::RackServidores(std::string descripcion, float consumoTotal, int totalServidores): Dispositivo(descripcion,consumoTotal), totalServidores(totalServidores) {
}

RackServidores::~RackServidores() noexcept {
}

void RackServidores::setToatoalServidores(int totalServidores) {
    this->totalServidores = totalServidores;
}

int RackServidores::getTotalServidores() const {
    return totalServidores;
}

void RackServidores::setServidoresOperativo(int servidoresoperativos) {
    if(servidoresoperativos > totalServidores){
        throw std::out_of_range("RackServidores::setServidoresOperativo: el numero de servidores operativos no puede ser mayor al número total de servidores.");
    }
    this->servidoresOperativos = servidoresoperativos;
}

int RackServidores::getServidoresOperativos() const {
    return servidoresOperativos;
}

std::string RackServidores::getDescripcion() const {

}

float RackServidores::getConsumo() const {

}
