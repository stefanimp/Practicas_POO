//
// Created by stefan on 10/04/2023.
//

#ifndef PRUEBA_PODERPSIQUICO_H
#define PRUEBA_PODERPSIQUICO_H

#include "Poder.h"

class PoderPsiquico: public Poder{
public:
    //Constructores y destructores
    PoderPsiquico();
    PoderPsiquico(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva);
    PoderPsiquico(const PoderPsiquico &original);
    ~PoderPsiquico();
    //Operadores
    PoderPsiquico& operator=(const PoderPsiquico &original);
};

#endif //PRUEBA_PODERPSIQUICO_H
