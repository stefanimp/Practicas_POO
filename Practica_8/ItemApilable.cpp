//
// Created by stefan on 27/04/2023.
//

#include "ItemApilable.h"

ItemApilable::ItemApilable(unsigned int num_elmentos):num_elementos(num_elmentos) {
    if(num_elmentos == 0){
        throw std::out_of_range("[I""teemApilable] Error al crear un ItemApilable con ninguna unidad");
    }
    if(num_elmentos > MAX_ELEMENTOS){
        throw std::out_of_range("[I""teemApilable] Error al crear un ItemApilable con más de 64 unidades");
    }
}

ItemApilable::~ItemApilable() {
}

int ItemApilable::getNumElmentos() const {
    return num_elementos;
}

//FALTA IMPLEMENTAR LOS METODOS INCREMENTAR Y DECREMENTAR NUM ELEMENTOS

void ItemApilable::incrementaNumElementos(unsigned int cantidad) {
    if((cantidad + num_elementos) > MAX_ELEMENTOS){
        throw std::out_of_range("ItemApilable::incrementaNumElementos: no se puede incrementar tal numero de objetos");
    }
    num_elementos += cantidad;
}

void ItemApilable::decrementanumElementos(unsigned int cantidad) {
    if((cantidad - num_elementos) < MIN_ELEMENTOS){
        throw std::out_of_range("ItemApilable::decrementanumElementos: no se puede decrementar tal numero de objetos");
    }
    num_elementos -= cantidad;

}
