/**
 * @file Datacenter.h
 * @author ujapoo
 */

#include <stdexcept>
#include "DataCenter.h"

DataCenter::DataCenter(const std::string &ubicacion, float superficie)
    : ubicacion(ubicacion), superficie(superficie), tecnicos(1),
    numDispositivos(0), fuente(nullptr) {

    for (int i = 0; i < MAX_DISPOSITIVOS; ++i) {
        dispositivos[i]=nullptr;
    }
}

DataCenter::DataCenter(const DataCenter &orig)
        :ubicacion(orig.ubicacion),superficie(orig.superficie),
        tecnicos(orig.tecnicos),numDispositivos(orig.numDispositivos),
        fuente(nullptr) {

    if (orig.fuente) {
        fuente= new Generador(*orig.fuente);
    }
    for (int i = 0; i < numDispositivos; ++i) {
        dispositivos[i]=orig.dispositivos[i];
    }
}

int DataCenter::getTecnicos() const {
    return tecnicos;
}

void DataCenter::setTecnicos(int tecnicos) {
    if (tecnicos<1 || tecnicos >4) {
        throw std::out_of_range("[DataCenter::setTecnicos] número de técnicos no válido");
    }
    this->tecnicos = tecnicos;
}

void DataCenter::setFuente(const Generador &g) {
    if (this->fuente!= nullptr) {
        throw std::invalid_argument("[DataCenter::setFuente] El DataCenter ya tiene un generador");
    }
    this->fuente = new Generador(g);
}

float DataCenter::getPotenciaDisponible() const {
    float potenciaDisponible=0;
    
    if (this->fuente!=nullptr) {
        potenciaDisponible=this->fuente->getPotencia();
    }
    return potenciaDisponible;
}

DataCenter::~DataCenter() {
    delete fuente;
    fuente= nullptr;
    numDispositivos=0;
}

/** Añade un dispositivo a un DataCenter
 * @param d Dispositivo que se agregará
 * @post agrega una referencia del dispositivo a los disponibles en el DataCenter
 * @throws std::out_of_range si se supera el máximo de dispositivos permitidos
 * @throws std::out_of_range si el DataCenter no dispone de un generador
 */
void DataCenter::instala(Dispositivo &d) {

    if (fuente== nullptr) {
        throw std::out_of_range("[DataCenter::instalaDispositivos] El DataCenter no dispone de generador");
    }
    if (numDispositivos==MAX_DISPOSITIVOS) {
     throw std::out_of_range ("[DataCenter::instalaDispositivos] No se admiten más dispositivos");
    }
    dispositivos[numDispositivos]= &d;
    numDispositivos++;
}

Dispositivo &DataCenter::getDispositivo(int cual) {
    if (cual<1 || cual>numDispositivos) {
        throw std::out_of_range ("[DataCenter::getDispositivo] No se encuentra el dispositivo");
    }
    return *dispositivos[cual-1];
}

int DataCenter::getNumDispositivos() const {
    return numDispositivos;
}

float DataCenter::consumoActual() const {
    float consumo=0;
    for (int i = 0; i < numDispositivos; ++i) {
        if (dispositivos[i]->isActivo()) {
            consumo+=dispositivos[i]->getConsumo();
        }
    }
    return consumo;
}

