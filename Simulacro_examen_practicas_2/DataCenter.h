/**
 * @file Datacenter.h
 * @author ujapoo
 */
#ifndef CLOUDPOO_DATACENTER_H
#define CLOUDPOO_DATACENTER_H

#include <string>
#include "Generador.h"
#include "Dispositivo.h"
#include "DataCenterException.h"

class DataCenter {
public:
    static const int MAX_DISPOSITIVOS = 10;
private:
    std::string ubicacion;
    float superficie;
    int tecnicos = 1;
    Generador* fuente = nullptr;
    Dispositivo* dispositivos[MAX_DISPOSITIVOS];
    int numDispositivos=0;
public:

    DataCenter(const std::string &ubicacion, float superficie);
    DataCenter(const DataCenter& orig);

    virtual ~DataCenter();

    int getTecnicos() const;
    void setTecnicos(int tecnicos);

    void setFuente(const Generador &g);
    float getPotenciaDisponible() const;

    void instala(Dispositivo& d);
    Dispositivo& getDispositivo(int cual);
    int getNumDispositivos() const;

    float consumoActual() const;
    //Métodos de los ejercicios
    Dispositivo* mayorConsumo();

};


#endif //CLOUDPOO_DATACENTER_H
