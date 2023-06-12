//
// Created by stefan on 23/02/2023.
//

#include "djutils.h"
#include "ParametroNoValido.h"
#include <string>
#include <iostream>

/**
 * @brief   Define una cadena de caracteres
 * @param mensaje   Mensaje que se muestra para saber que cadena introducir
 * @return  Cadena de caracteres introducida por el usuario
 * @post    Devuelve la cadena de caracteres
 * */
std::string introducirString(const std::string mensaje){
    std::string cadena;
    std::cout<<mensaje;
    getline(std::cin,cadena);
    return cadena;
}

/**
 * @brief   Muestra los datos de un tema
 * @param temazo    objeto de la clase temazo
 * */
void mostrarDatosTemazo(const Temazo &temazo){
    std::cout<<"Titulo del tema: "<<temazo.getTitulo() <<std::endl;
    std::cout<<"Interprete del tema: " <<temazo.getInterprete() <<std::endl;
    std::cout<<"Duracion del tema: " <<temazo.getDuracion() <<std::endl;
    std::cout<<"Puntuacion del tema: " <<temazo.getPuntuacion() <<std::endl;
    std::cout<<"Nombre del ultimo garito: " <<temazo.getNombreUltimoGarito() <<std::endl;
    std::cout<<"Fecha ultimo uso: " <<std::endl;
    mostrarDatosFechas(temazo.getFechaUltimoUso());
    std::cout<<std::endl <<std::endl;
}

/**
 * @brief   Muestra los datos de un objeto de la clase Garito
 * @param garito    objeto de la clase Garito
 * */
void mostrarDatosGarito(const Garito &garito){
    std::cout<<"Nombre del garito: " <<garito.getNombre() <<std::endl;
    std::cout<<"Direccion del garito: " <<garito.getDireccion() <<std::endl <<std::endl;
}

/**
 * @brief   Muestra los datos de un objeto de la clase Garito
 * @param fecha objeto de la clase Fecha
 * */
void mostrarDatosFechas(const Fecha &fecha){
    std::cout<<"Dia: " <<fecha.getDia() <<std::endl;
    std::cout<<"Mes: " <<fecha.getMes() <<std::endl;
    std::cout<<"Agno: " <<fecha.getAgno() <<std::endl <<std::endl;
}

/**
 * @brief   Definir/modificar los atrobutos de un objeto de la clase Garito
 * @param garito    Objeto que se quiere definir/modificar
 * @post    El objeto queda modificado si no se lanza ninguna excepcion
 * @post    Se lanza una excepcón si alguno de los atributos es una cadena vacia
 * */
void definirGarito(Garito &garito){
    try {
        garito.setNombre(introducirString("Introduce el nombre del garito: "));
    } catch (ParametroNoValido &e){
        std::cerr<<e.queOcurre();
    }
    try {
        garito.setDireccion(introducirString("Introduce la direccion del garito: "));
    } catch (ParametroNoValido &e){
        std::cerr<<e.queOcurre();
    }
}
