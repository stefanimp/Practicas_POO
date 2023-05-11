//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_COFRE_H
#define PRACTICA_9_COFRE_H

#include "Contenedor.h"
#include "Item.h"

class Cofre:public Contenedor<Item>, public Item{
public:
    Cofre();
    Cofre(int cuantosCaben);
    Cofre(const Cofre& orig);
    virtual ~Cofre();
    virtual std::string getDescripcion() override;
    virtual void mete(Item *item) override;
};

#endif //PRACTICA_9_COFRE_H
