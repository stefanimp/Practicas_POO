/** 
 * @file    ContenedorItems.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Item.h"
#include <string>

#ifndef ContenedorItems_H
#define ContenedorItems_H

class ContenedorItems{
public:
    ContenedorItems();
    ContenedorItems(int cuantosCaben);
    ContenedorItems(const ContenedorItems& orig);
    virtual ~ContenedorItems();
    int cuantosCaben();
    int cuantosHay() const;
    virtual void mete(Item *item);
    Item& consulta(int cual);
    Item* saca(int cual);
private:
    int _maxItems = 27; ///< Tamaño del vector de punteros
    Item* *_items = nullptr; ///< Vector de punteros creado dinámicamente
    int _numItems = 0; ///< Primeras posiciones del vector ocupadas (máximo maxItems)
};

#endif /* ContenedorItems_H */

