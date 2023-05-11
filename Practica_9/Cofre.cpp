//
// Created by stefan on 08/05/2023.
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

std::string Cofre::getDescripcion() {
    std::stringstream ss;
    ss<<"Hay "<<Contenedor::cuantosHay() <<" elementos";

}

void Cofre::mete(Item *item) {
    //Utilizamos el operador dynamic_cast para realizar una conversión dinámica de un objeto a un tipo
    // deseado y comprobar si la conversión fue exitosa. Si la conversión es exitosa, el operador devuelve
    // un puntero al objeto convertido. Si la conversión no es posible, devuelve un puntero nulo.
    Cofre *prueba = dynamic_cast<Cofre*>(item);
    if(prueba){
        throw std::invalid_argument("Cofre::mete: no puedes meter un cofre dentro de otro cofre");
    }

    Contenedor::mete(item);
}
