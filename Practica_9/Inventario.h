//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_INVENTARIO_H
#define PRACTICA_9_INVENTARIO_H

#include "Contenedor.h"
#include "Item.h"

class Inventario: public Contenedor<Item>{
public:
    Inventario() = default;
    ~Inventario();
};

#endif //PRACTICA_9_INVENTARIO_H
