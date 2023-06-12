//
// Created by stefan on 21/02/2023.
//
#include "Temazo.h"
#include <iostream>

/**
 * @brief   Constructor por defector de la clase temazo
 * @post    Crea el objeto con los valores por defecto
 * */
Temazo::Temazo():
        fechaUltimoUso(Fecha(0,0,0)){
}

/**
 * @brief   Constructor parametrizado de la clase temazo
 * @param titulo    Titulo del tema
 * @param interprete    Interprete del tema
 * @param duracion  Duración del tema
 * @post    Crea un nuevo objeto con los valores indicados
 * */
Temazo::Temazo(std::string titulo, std::string interprete, int duracion, std::string nombreUltimoGarito,const Fecha &fechaUltimoUso):
    titulo(titulo),
    interprete(interprete),
    duracion(duracion),
    nombreUltimoGarito(nombreUltimoGarito),
    fechaUltimoUso(fechaUltimoUso){
}

/**
 * @brief   Comstructor por copia
 * @param orignial Obeto del cual se van a copiar los datos
 * @post    crea un nuevo objeto copiando los valores desde el objeto orignial
 * */
Temazo::Temazo(const Temazo &orignial):
titulo(orignial.titulo),
interprete(orignial.interprete),
duracion(orignial.duracion),
puntuacion(orignial.puntuacion),
nombreUltimoGarito(orignial.nombreUltimoGarito),
fechaUltimoUso(orignial.fechaUltimoUso){
}

/**
 * @brief   Destructor
 * @post    Destruye el objeto
 * */
 Temazo::~Temazo() {
     std::cout<<"El objeto ha sido destruido" <<std::endl;
 }

 /**
  * @brief  modifica el valor del atributo titulo
  * @param titulo   nuevo valor para el atributo
  * @post   El valor del atributo queda modificado
  * */
 void Temazo::setTitulo(const std::string titulo){
     this->titulo = titulo;
 }

 /**
  * @brief  modifica el valor del atributo interprete
  * @param interprete   Nuevo valor para el atributo
  * @post   El valor del atributo queda modificado
  * */
void Temazo::setInterprete(const std::string interprete) {
    this->interprete = interprete;
 }

 /**
  * @brief  modifica el valor del atributo duracion
  * @param duracion Nuevo valor para el atributo
  * @post   El valor del atributo queda modificado
  * */
void Temazo::setDuracion(int duracion) {
    this->duracion = duracion;
}

/**
 * @brief   modifica el valor del atributo nombreUltimoGarito
 * @param nombreUltimoGarito    Nuevo valor para el atriuto
 * @post    El valor del atributo queda modificado
 * */
void Temazo::setNombreUltimoGarito(std::string nombreUltimoGarito) {
    this->nombreUltimoGarito = nombreUltimoGarito;
}

/**
 * @brief   Modifica el valor del atributo fechaUltimoUso
 * @param fechaUltimoUso    Nuevo valor para el atributo
 * @post    El valor del atributo queda modificado
 * */
void Temazo::setFechaUltimoUso(const Fecha &fechaUltimoUso) {
    this->fechaUltimoUso = fechaUltimoUso;
}

/**
 * @brief   Devuelve el valor del atributo minuto
 * @post    Devuelve el valor del atributo minuto
 * */
std::string Temazo::getTitulo() const {
    return titulo;
}

/**
 * @brief   Devuelve el valor del atributo interprete
 * @post    Devuelve el valor del atributo interprete
 * */
std::string Temazo::getInterprete() const {
    return interprete;
}

/**
 * @brief   Devuelve el valor del atributo duración
 * @post    Devuelve el valor del atributo duración
 * */
int Temazo::getDuracion() const {
    return duracion;
}

/**
 * @brief   Devuelve el valor del atributo puntuación
 * @post    Devuelve el valor del atributo puntuación
 * */
int Temazo::getPuntuacion() const {
    return puntuacion;
}

/**
 * @brief   Devuelve el valor del atributo nombreUlimoGarito
 * @post    Devuelve el valor del atributo nombreUlimoGarito
 * */
std::string Temazo::getNombreUltimoGarito() const {
    return nombreUltimoGarito;
}

/**
 * @brief   Devuelve el valor del atributo FechaUltimoUso
 * @post    Devuelve el valor del atributo FechaUltimoUso
 * */
const Fecha &Temazo::getFechaUltimoUso() const {
    return fechaUltimoUso;
}
