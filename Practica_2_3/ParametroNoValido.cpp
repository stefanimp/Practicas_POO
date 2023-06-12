//
// Created by stefan on 22/02/2023.
//

#include "ParametroNoValido.h"
#include <iostream>

/**
 * @brief   Constructor parametrizado de la clase ParametroNoValido
 * @param origen    Origen del programa
 * @param descripcion   Descripción del problema
 * @post    Crea un nuevo objeto con los valores indicados
 * */
ParametroNoValido::ParametroNoValido(std::string origen, std::string descripcion):
origen(origen),
descripcion(descripcion){
}

/**
 * @brief   Destructor de la clase ParametroNoValido
 * @post    Destruye el objeto
 * */
ParametroNoValido::~ParametroNoValido() {
    std::cout<<"El objeto ha sido destruido" <<std::endl;
}

/**
 * @brief   Devuelve los atributos del objeto
 * @post    Devuelve en una sola cadena de caracteres los atributos  origen y descripción de la clase ParametroNoValido
 * */
std::string ParametroNoValido::queOcurre() const {
    return (origen + " " + descripcion);
}
