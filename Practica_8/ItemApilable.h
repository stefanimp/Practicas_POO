//
// Created by stefan on 27/04/2023.
//

#ifndef PRUEBA_ITEMAPILABLE_H
#define PRUEBA_ITEMAPILABLE_H

#include "Item.h"
#include <stdexcept>

class ItemApilable: public Item{
private:
    int num_elementos = MIN_ELEMENTOS;
public:
    //Constantes
    int MIN_ELEMENTOS = 1;
    int MAX_ELEMENTOS = 64;
    //Constructores y destructores
    ItemApilable() = default;
    ItemApilable(unsigned int num_elmentos);
    virtual ~ItemApilable();
    //Getters y Setters
    int getNumElmentos() const;
    //Otros métodos
    virtual std::string getDescripcion() const = 0;
    void incrementaNumElementos(unsigned int cantidad);
    void decrementanumElementos(unsigned int cantidad);
};

#endif //PRUEBA_ITEMAPILABLE_H
