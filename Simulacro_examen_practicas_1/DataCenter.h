//
// Created by stefan on 22/03/2023.
//

#ifndef CLOUDPOO_PUML_DATACENTER_H
#define CLOUDPOO_PUML_DATACENTER_H

#include "Generador.h"
#include "Dispositivo.h"

#include <string>
#include <stdexcept>

const int MAX_TECNICOS = 4;
const int MIN_TECNICOS = 1;

const int MAX_DISPOSITIVOS = 10;
const int MIN_DISPOSITIVOS = 0;


class DataCenter{
private:
    std::string ubicacion = "";
    float superficie = 0;                       //Metros cuadrados
    int tecnicos = MIN_TECNICOS;                //Entre 1 y 4
    Generador *generador = nullptr;             //De 0 a 1
    int num_dispositivos = 0;
    Dispositivo **dispositivos = nullptr;       //De 0 a 10;
public:
    //Constructores y destructor
    DataCenter(std::string ubicacion, float superficie);
    DataCenter(const DataCenter &original);
    ~DataCenter();
    //Setters
    void setFuente(Generador *generador);
    void setTecnicos(int num_tecnicos);
    //Getters
    std::string getUbicacion() const;
    float getSuperficie() const;
    int getNunTecnicos() const;
    float getPotenciaDisponible() const;
    Dispositivo* getDispositivo(int pos) const;
    float ConsumoActual() const;
    int getNumDispositivos() const;
    //Otros metodos
    void instala(Dispositivo *dispositivo);
};

#endif //CLOUDPOO_PUML_DATACENTER_H
