//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_ITEMAPILABLE_H
#define PRACTICA_9_ITEMAPILABLE_H

#include "Item.h"

/**@brief Clase abstracta para objetos apilables
*/
class ItemApilable: public Item {
public:
    ItemApilable() = default;
    ItemApilable(unsigned int cuantos);
    ItemApilable(const ItemApilable& orig);
    virtual ~ItemApilable();
    void incrementaNumElementos(unsigned int cantidad);
    void decrementaNumElementos(unsigned int cantidad);
    unsigned int getNumElementos() const;

    //Heredada de Item pero implementable en derivadas
private:
    int _numElementos = 1;
};

#endif //PRACTICA_9_ITEMAPILABLE_H
