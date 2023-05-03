//
// Created by stefan on 27/04/2023.
//

#ifndef PRUEBA_ESPADA_H
#define PRUEBA_ESPADA_H

#include "Item.h"

class Espada:public Item{
private:
    std::string descripcion = "";
public:
    //Constructores y destructores
    Espada() = default;
    Espada(std::string descripcion);
    virtual ~Espada();
    //Getters y setters
    virtual std::string getDescripcion() const override;
};

#endif //PRUEBA_ESPADA_H
