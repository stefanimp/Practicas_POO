//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_FILETE_H
#define PRACTICA_9_FILETE_H

#include "Item.h"

class Filete: public Item {
public:
    Filete() = default;
    Filete(const Filete& orig);
    virtual ~Filete();

    virtual std::string getDescripcion() override;

private:

};

#endif //PRACTICA_9_FILETE_H
