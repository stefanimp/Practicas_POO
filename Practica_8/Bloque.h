//
// Created by stefan on 02/05/2023.
//

#ifndef PRUEBA_BLOQUE_H
#define PRUEBA_BLOQUE_H

#include "ItemApilable.h"
#include <sstream>

class Bloque:public ItemApilable{
private:
    std::string descripcion;
public:
    //Constructores y destructores
    Bloque() = default;
    Bloque(std::string descripcion, int cantidad);
    virtual ~Bloque();
    //Getters y setters
    virtual std::string getDescripcion() const override;

};

#endif //PRUEBA_BLOQUE_H
