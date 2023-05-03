//
// Created by stefan on 02/05/2023.
//

#ifndef PRUEBA_FILETE_H
#define PRUEBA_FILETE_H

#include "Item.h"

class Filete:public Item{
private:
    std::string descripcion = "";
public:
    //Constructores y destructores
    Filete() = default;
    Filete(std::string descipcion);
    virtual ~Filete();
    //Getters y setters
    virtual std::string getDescripcion() const override;

};

#endif //PRUEBA_FILETE_H
