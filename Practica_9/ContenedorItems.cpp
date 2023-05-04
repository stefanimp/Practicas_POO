/** 
 * @file    ContenedorItems.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "ContenedorItems.h"
#include "EmptyContainer.h"
#include <stdexcept>

ContenedorItems::ContenedorItems(): ContenedorItems(27){
}

ContenedorItems::ContenedorItems(int cuantosCaben)
    :_maxItems(cuantosCaben)
    ,_numItems(0) {
    
    _items=new Item*[cuantosCaben];
    for (int i = 0; i < cuantosCaben; i++) {
        _items[i]=nullptr;
    }
}

/**Crea un ContenedorItems vacío del mismo tamaño del original*/
ContenedorItems::ContenedorItems(const ContenedorItems& orig)
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    _items=new Item*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=nullptr;
    }
}

ContenedorItems::~ContenedorItems() {
    delete [] _items;
}

int ContenedorItems::cuantosHay() const {
    return _numItems;
}

int ContenedorItems::cuantosCaben() {
    return _maxItems;
}

void ContenedorItems::mete(Item* item) {
    if (!item) 
        throw std::invalid_argument ("[ContenedorItems::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[ContenedorItems::mete] No caben más elementos en el ContenedorItems");
    _items[_numItems++]=item;
}

/**@param cual nº orden del elemento a consultar
 * @return Referencia al objeto indicado del ContenedorItems
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el ContenedorItems está vacío*/
Item& ContenedorItems::consulta(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[ContenedorItems::consulta] El ContenedorItems está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[ContenedorItems::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}


/**@param cual nº orden del elemento a extraer
 * @return Extrae del ContenedorItems y devuelve el puntero al Item indicado
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el ContenedorItems está vacío*/
Item* ContenedorItems::saca(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[ContenedorItems::saca] El ContenedorItems está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[ContenedorItems::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}
