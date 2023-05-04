//
// Created by stefan on 04/05/2023.
//

#include "Cofre.h"
#include "EmptyContainer.h"
#include <stdexcept>

Cofre::Cofre():ContenedorItems(){
}

Cofre::Cofre(int cuantosCaben): ContenedorItems(cuantosCaben){
}

/**Crea un Cofre vacío del mismo tamaño del original*/
Cofre::Cofre(const Cofre& orig): ContenedorItems(orig){
}

Cofre::~Cofre() {
}

std::string Cofre::getDescripcion() const {
    std::stringstream ss;
    ss<<"Hay "<<ContenedorItems::cuantosHay() <<" elementos";

}