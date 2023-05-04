//
// Created by stefan on 04/05/2023.
//

#include "Cofre.h"
#include "EmptyContainer.h"
#include <stdexcept>

Cofre::Cofre():Contenedor(){
}

Cofre::Cofre(int cuantosCaben): Contenedor(cuantosCaben){
}

/**Crea un Cofre vacío del mismo tamaño del original*/
Cofre::Cofre(const Cofre& orig): Contenedor(orig){
}

Cofre::~Cofre() {
}