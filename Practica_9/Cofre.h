//
// Created by stefan on 04/05/2023.
//

#ifndef PRUEBA_COFRE_H
#define PRUEBA_COFRE_H

#include "Item.h"
#include "Contenedor.h"

class Cofre:public Contenedor{
public:
    Cofre();
    Cofre(int cuantosCaben);
    Cofre(const Cofre& orig);
    virtual ~Cofre();
};

#endif //PRUEBA_COFRE_H
