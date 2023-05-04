/** 
 * @file    Contenedor.cpp
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include "Contenedor.h"
#include "EmptyContainer.h"
#include <stdexcept>

Contenedor::Contenedor(): Contenedor(27)
{
}

Contenedor::Contenedor(int cuantosCaben)
    :_maxItems(cuantosCaben)
    ,_numItems(0) {
    
    _items=new Item*[cuantosCaben];
    for (int i = 0; i < cuantosCaben; i++) {
        _items[i]=nullptr;
    }
}

/**Crea un Contenedor vacío del mismo tamaño del original*/
Contenedor::Contenedor(const Contenedor& orig)
    :_maxItems(orig._maxItems)
    ,_numItems(orig._numItems) {

    _items=new Item*[_maxItems];
    for (int i = 0; i < _maxItems; i++) {
        _items[i]=nullptr;
    }
}

Contenedor::~Contenedor() {
    delete [] _items;
}

int Contenedor::cuantosHay() const {
    return _numItems;
}

int Contenedor::cuantosCaben() {
    return _maxItems;
}

void Contenedor::mete(Item* item) {
    if (!item) 
        throw std::invalid_argument ("[Contenedor::mete] Intento de asignar puntero 0");
    if (_numItems==_maxItems)
        throw std::out_of_range("[Contenedor::mete] No caben más elementos en el Contenedor");
    _items[_numItems++]=item;
}

/**@param cual nº orden del elemento a consultar
 * @return Referencia al objeto indicado del Contenedor
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el Contenedor está vacío*/
Item& Contenedor::consulta(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[Contenedor::consulta] El Contenedor está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Contenedor::consulta] El elemento indicado no existe");
    return *_items[cual-1];
}


/**@param cual nº orden del elemento a extraer
 * @return Extrae del Contenedor y devuelve el puntero al Item indicado
   @throw std::out_of_range si el elemento no existe
   @throw EmptyContainer si el Contenedor está vacío*/
Item* Contenedor::saca(int cual) {
    if (_numItems==0) 
        throw EmptyContainer("[Contenedor::saca] El Contenedor está vacío");
    if (cual<=0 || cual >_numItems)
        throw std::out_of_range("[Contenedor::mete] El elemento indicado no existe");
    Item* elemento = _items[cual-1];
    _numItems--;
    if (_numItems>0)
        _items[cual-1]=_items[_numItems];
    return elemento;
}
