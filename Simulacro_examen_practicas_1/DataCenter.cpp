//
// Created by stefan on 22/03/2023.
//

#include "DataCenter.h"

DataCenter::DataCenter(std::string ubicacion, float superficie):
ubicacion(ubicacion),
superficie(superficie){
    generador = nullptr;
    dispositivos = nullptr;
    num_dispositivos = 0;
    tecnicos = 1;
}

DataCenter::DataCenter(const DataCenter &original):
ubicacion(original.ubicacion),
superficie(original.superficie),
tecnicos(original.tecnicos),
num_dispositivos(original.num_dispositivos){
    Dispositivo **copia = new Dispositivo * [num_dispositivos];
    for (int i = 0; i < num_dispositivos; ++i) {
        copia[i] = new Dispositivo(*original.dispositivos[i]);
    }
    dispositivos = copia;
    generador = new Generador(*original.generador);
}

DataCenter::~DataCenter() {
    if(generador != nullptr){
        delete generador;
        generador = nullptr;
    }

    if(dispositivos != nullptr){
        for (int i = 0; i < num_dispositivos; ++i) {
            dispositivos[i] = nullptr;
        }
        delete [] dispositivos;
        dispositivos = nullptr;
    }
}

void DataCenter::setFuente(Generador *generador) {
    if(this->generador != nullptr){
        throw std::invalid_argument("DataCenter::setFuente: solo se puede asignar el generador una vez");
    }
    this->generador = generador;
}

void DataCenter::setTecnicos(int num_tecnicos) {
    if(num_tecnicos > MAX_TECNICOS || num_tecnicos < MIN_TECNICOS){
        throw std::out_of_range("DataCenter::setTecnicos:solo puede haber de 1 a 4 tecnicos");
    }
}

std::string DataCenter::getUbicacion() const {
    return ubicacion;
}

float DataCenter::getSuperficie() const {
    return superficie;
}

int DataCenter::getNunTecnicos() const {
    return tecnicos;
}

float DataCenter::getPotenciaDisponible() const {
    return generador->getPotencia();
}

Dispositivo *DataCenter::getDispositivo(int pos) const {
    if(pos >= num_dispositivos || pos - 1 < MIN_DISPOSITIVOS){
        throw std::out_of_range("DataCenter::getDispositivo: no existe tal dispositivo");
    }
    return dispositivos[pos - 1];
}

float DataCenter::ConsumoActual() const {
    float consumo_total = 0;
    for (int i = 0; i < num_dispositivos; ++i) {
        if (dispositivos[i]->isActivo()){
            consumo_total += dispositivos[i]->getConsumo();
        }
    }
    return consumo_total;
}

int DataCenter::getNumDispositivos() const {
    return num_dispositivos;
}


/**
 * @brief   Instala un nuevo dispositivo en el DataCenter
 * @param dispositivo   Puntero al dispositivo que se quiere añadir
 * @post    Si no se ha alcanzado el número máximo de dispositivos el dispositivo quedad añadido
 * @post    Si se ha alcanzado el número máximo de dispositivos este no se añade y se lanza un a excepción
 * */
void DataCenter::instala(Dispositivo *dispositivo) {
    if(num_dispositivos == MAX_DISPOSITIVOS){
        throw std::length_error("DataCenter::instala(): se ha alcanzado el número máximo de dispositivos");
    }
    Dispositivo **copia = new Dispositivo * [++num_dispositivos];
    for (int i = 0; i < num_dispositivos - 1; ++i) {
        copia[i] = dispositivos[i];
        dispositivos[i] = nullptr;
    }
    delete[] dispositivos;

    copia[num_dispositivos - 1] = dispositivo;
    dispositivos = copia;
}
