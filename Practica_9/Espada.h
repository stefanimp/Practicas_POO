//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_ESPADA_H
#define PRACTICA_9_ESPADA_H

#include "Item.h"

class Espada: public Item {
public:
    Espada() = default;
    Espada(const Espada& orig);
    virtual ~Espada();

    virtual std::string getDescripcion() override;

private:
};

#endif //PRACTICA_9_ESPADA_H
