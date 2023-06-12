//
// Created by stefan on 22/02/2023.
//

#include    "Fecha.h"
#include <iostream>
#include <ctime>

/**
 * @brief   Constructor por defecto de la clase Fecha
 * @details Hace uso de la libreria ctime para saber la fecha actual y darle esos valores a los atributos de la clase Fecha
 * @post    Crea un nuevo objeto con la fecha actual
 * */
Fecha::Fecha(){
    // COn esto obtenermos la fecha actual en segundos
    std::time_t ahora = std::time(nullptr);
    //Llamamos al constructor localTime pasandole la variable ahora para que alacene en esta la fecha actual y hacemos que el putero tiempo_local apunte a la dirección de memoria de ahora
    std::tm* tiempo_local = std::localtime(&ahora);
    //Asigamos de esta forma los valores a los atributos de la clase Fecha
    this->dia = tiempo_local->tm_mday;
    this->mes = tiempo_local->tm_mon + 1;
    this->agno = tiempo_local->tm_year + 1900;
}

/**
 * @brief   Constructor parametrizado de la Clase Fecha
 * @param dia   dia que se le asiganrá a la fecha
 * @param mes   mes que se le asignará a la fecha
 * @param agno  agno que se le asignará a la fecha
 * @post    Crea un nuevo objeto con los valores indicados
 * */
Fecha::Fecha(int dia, int mes, int agno):
dia(dia),
mes(mes),
agno(agno){
};

/**
 * @brief   Constructor por copia de la clase Fecha
 * @param original  objeto del cual queremos copiar los datos
 * @post    Se crea un nuevo objeto copiando los valores desde el objeto original
 * */
Fecha::Fecha(const Fecha &original):
dia(original.dia),
mes(original.mes),
agno(original.agno){
}

/**
 * @brief   Desctructor
 * @post    Destruye el objeto
 * */
Fecha::~Fecha() {
    std::cout<<"El objeto ha sido destruido" <<std::endl;
}
/**
 * @brief   Modifica el valor del atributo dia
 * @param dia   Nuevo valor para el atributo
 * @post    El valor del atribuo queda modificado
 * */
void Fecha::setDia(int dia) {
    this->dia = dia;
}

/**
 * @brief   Modifica el valor del atributo mes
 * @param mes   Nuevo valor para el atributoo
 * @post    El valor del atributo queda modificado
 * */
void Fecha::setMes(int mes) {
    this->mes = mes;
}

/**
 * @brief   Modifica el valor del atributo agno
 * @param ango  Nuevo valor para el atributo
 * @post    El valor del atributo queda modificado
 * */
void Fecha::setAgno(int ango) {
    this->agno = agno;
}

/**
 * @brief   Devuelve el valor del atrbuto dia
 * @post    Devuelve el valor del atrbuto dia
 * */
int Fecha::getDia() const {
    return dia;
}

/**
 * @brief   Devuelve el valor del atrbuto mes
 * @post    Devuelve el valor del atrbuto mes
 * */
int Fecha::getMes() const {
    return  mes;
}

/**
 * @brief   Devuelve el valor del atrbuto agno
 * @post    Devuelve el valor del atrbuto agno
 * */
int Fecha::getAgno() const {
    return agno;
}

/**
 * @brief   Compara si una fecha es menor que otra
 * @param fecha Fecha con la que se va a comparar
 * @post    Devuelve true si la fecha desde la que se está usando el operador(fecha de la derecha) es menor
 * @post    Devuelve false si la fecha desde la que se está usando el operador(fecha de la derecha) es mayor o igual
 * */
bool Fecha::operator <(const Fecha &fecha){
    return ((agno*10000 + mes*100 + dia) < (fecha.agno*10000 + fecha.mes*100 + fecha.dia))? true:false;
}

/**
 * @brief   Compara si dos fechas son iguales
 * @param fecha Fecha con la que se va a comparar
 * @post    Devuelve true si ambas fechas son iguales
 * @post    Devuelve false si las dos fechas no son iguales
 * */
bool Fecha::operator==(const Fecha &fecha) {
    return ((agno*10000 + mes*100 + dia) == (fecha.agno*10000 + fecha.mes*100 + fecha.dia))? true:false;
}

/**
 * @brief   Compara si una fecha es menor o igual que otra
 * @param fecha Fecha con la que se va a comparar
 * @post    Devuelve true si la fecha desde la que se está usando el operador(fecha de la derecha) es menor o igual que la segunda fecha
 * @post    Devuelve false si la fecha desde la que se está usando el operador(fecha de la derecha) es mayor que la seguda fecha
 * */
bool Fecha::operator<=(const Fecha &fecha) {
    return ((this->operator<(fecha)) || (this->operator==(fecha)))? true:false;
}

/**
 * @brief   Compara si una fecha es mayor o igual que otra
 * @param fecha Fecha con la que se va a comparar
 * @post    Devuelve true si la fecha desde la que se está usando el operador(fecha de la derecha) es mayor o igual que la segunda fecha
 * @post    Devuelve false si la fecha desde la que se está usando el operador(fecha de la derecha) es menor que la segunda fecha
 * */
bool Fecha::operator>=(const Fecha &fecha) {
    return (!(this->operator<(fecha)) || (this->operator==(fecha)))? true:false;
}

/**
 * @brief   Compara si una fecha es mayor que otra
 * @param fecha Fecha con la que se va a comparar
 * @post    Devuelve true si la fecha desde la que se está usando el operador(fecha de la derecha) es mayor
 * @post    Devuelve false si la fecha desde la que se está usando el operador(fecha de la derecha) es menor o igual
 * */
bool Fecha::operator>(const Fecha &fecha) {
    return (!(this->operator<(fecha)) && !(this->operator==(fecha)))? true:false;
}

/**
 * @brief   Compara si dos fechas son iguales
 * @param fecha Fecha con la que se va a comparar
 * @post    Devuelve true si las dos fechas no son iguales
 * @post    Devuelve false si ambas fechas son iguales
 * */
bool Fecha::operator!=(const Fecha &fecha) {
    return (!(this->operator==(fecha)))? true:false;
}

/**
 * @brief   Operador de asignación
 * @post    Asigna los atributos de una fecha a otra
 * @post    Deveulve un mensaje diciendo que ambas fechas son iguales y no se realiza la asignación
 * */
void Fecha::operator=(const Fecha &fecha) {
    if(this->operator==(fecha)){
        std::cout<<"Las fechas son iguales";
    } else{
        this->dia = fecha.dia;
        this->mes = fecha.mes;
        this->agno = fecha.agno;
    }
}