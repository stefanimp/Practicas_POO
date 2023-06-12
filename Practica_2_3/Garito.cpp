//
// Created by stefan on 22/02/2023.
//

#include "Garito.h"
#include "ParametroNoValido.h"
#include <iostream>

/**
 * @brief   Constructor parametrizado de la clase Garito
 * @param nombre    Nombre del garito
 * @param direccion Dirección del garito
 * @param aforo     Aforo del garito
 * @post    Crea un nuevo objeto con los valores indicados
 * */
Garito::Garito(std::string nombre, std::string direccion, int aforo):
nombre(nombre),
direccion(direccion),
aforo(aforo){
    if(aforo < AFORO_MIN){
        throw ParametroNoValido("[Garito::Garito]:", "el aforo no puede ser menor que 1");
    }
}

/**
 * @brief   Constructor por copia
 * @param original  Objeto del cual se van a copiar los datos
 * @post    Crea un nuevo objeto copiando los valores desde el objeto original
 * */
Garito::Garito(const Garito &original):
nombre(original.nombre),
direccion(original.direccion),
aforo(original.aforo){
};

/**
 * @brief   Destructor
 * @post    Destruye el objeto
 * */
Garito::~Garito() {
    std::cout<<"El objeto ha sido destruido" <<std::endl;
}

/**
 * @brief   Modifica el valor del atributo nombre
 * @param nombre    Nuevo valor para el atributo
 * @post    Si la cadena no está vacia el valor del atributo queda moficado
 * @post    Si la cadena está vacia se lanza una excepción de tipo ParametroNoValido
 * */
void Garito::setNombre(const std::string nombre) {
    if(nombre == ""){
        // Lanzamos una excepción de tipo ParametroNoValido utilizanod el contructor parametrizado de la clase ParametroNoValido
        throw ParametroNoValido("[Garito::SetNombre]:", "el nuevo nombre no puede ser una cadena vacia");
        //!!! al escribir el catch devemos recordadr que el error que recoga será de tipo ParametroNoValido
    }
    this->nombre = nombre;
}

/**
 * @brief   Modifica el valor del atributo direccion
 * @param direccion Nuevo valor para el atributo
 * @post    Si la cadena no está vacia el valor del atributo queda moficado
 * @post    Si la cadena está vacia se lanza una excepción de tipo ParametroNoValido
 * */
void Garito::setDireccion(const std::string direccion) {
    if(direccion == ""){
        // Lanzamos una excepción de tipo ParametroNoValido utilizanod el contructor parametrizado de la clase ParametroNoValido
        throw ParametroNoValido("[Garito::SetDireccion]:", "la nueva direccion no puede ser una cadena vacia");
        //!!! al escribir el catch devemos recordadr que el error que recoga será de tipo ParametroNoValido
    }
    this->direccion = direccion;
}

/**
 * @brief   Modifica el valor del atributo aforo
 * @param aforo Nuevo valor para el atributo
 * @post    el valor del atributo queda modificado
 * */
void Garito::setAforo(int aforo) {
    this->aforo = aforo;
}

/**
 * @brief   Devuelve el valor del atributo nombre
 * @post    Devuelve el valor del atributo nombre
 * */
std::string Garito::getNombre() const {
    return nombre;
}

/**
 * @brief   Devuelve el valor del atributo direccion
 * @post    Devuelve el valor del atributo direccion
 * */
std::string Garito::getDireccion() const {
    return direccion;
}

/**
 * @brief   Devuelve el valor del atributo aforo
 * @post    Devuelve el valor del atributo aforo
 * */
int Garito::getAforo() const {
    return aforo;
}

/**
 * @brief   Comprueba si dos garitos son iguales por su nombre
 * @param otro  Garito cuyos datos se quieren comprobar
 * @post    devuelve true si los nombre son iguales y false si no lo son
 * */
bool Garito::operator==(const Garito &otro) {
    return (nombre == otro.nombre);
}
