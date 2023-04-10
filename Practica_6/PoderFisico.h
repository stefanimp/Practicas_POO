//
// Created by stefan on 10/04/2023.
//

#ifndef PRUEBA_PODERFISICO_H
#define PRUEBA_PODERFISICO_H

#include "Poder.h"

class PoderFisico: public Poder{
public:
    //Constructores y destructores
    PoderFisico();
    PoderFisico(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva);
    PoderFisico(const PoderFisico &original);
    ~PoderFisico();
    //Operadores
    PoderFisico& operator=(const PoderFisico &original);
};

#endif //PRUEBA_PODERFISICO_H
