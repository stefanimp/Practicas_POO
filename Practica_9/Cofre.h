//
// Created by stefan on 04/05/2023.
//

#ifndef PRUEBA_COFRE_H
#define PRUEBA_COFRE_H

#include "ContenedorItems.h"

class Cofre:public ContenedorItems, public Item{
public:
    Cofre();
    Cofre(int cuantosCaben);
    Cofre(const Cofre& orig);
    virtual ~Cofre();
    virtual std::string getDescripcion() const override;
};

#endif //PRUEBA_COFRE_H
