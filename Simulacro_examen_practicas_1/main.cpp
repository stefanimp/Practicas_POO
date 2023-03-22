/**
 * @file main.cpp
 * @author ujapoo
 */

#include "DataCenter.h"

#include <iostream>

int main() {
    /* Prueba 1: Crea un Datacenter con 2 técnicos asignados y tres Dispositivos con los siguientes datos:
     * Rack de servidores de 500W, RAID de discos de 750W, Unidad de backup de 250W*/

    /*Prueba 2: Crea dos Generadores de 1500W y trata de asignárselos al Datacenter.
     * Captura y muestra la información de posibles excepciones. Muestra la potencia del DataCenter*/

    /*Prueba 3: asigna los tres dispositivos al dataCenter, capturando cualquier excepción que pueda lanzar.*/

    /*Prueba 4: Crea un DataCenter que sea copia del que ya existe.
     Para la copia, enciende sus dos primeros dispositivos,
     visualiza el consumo actual del DataCenter y el número de dispositivos que tiene.*/

    //Prueba 1
    DataCenter centro1("Ubicacion1",300.34);
    try {
        centro1.setTecnicos(2);
    }catch (std::string &e){
        std::cerr<<e <<std::endl;
    }
    Dispositivo *dispositivo1 = new Dispositivo("Rack de servidores de 500W",500);
    Dispositivo *dispositivo2 = new Dispositivo("RAID de discos de 750W", 750);
    Dispositivo *dispositivo3 = new Dispositivo("Unidad de backup de 250W", 250);

    //Prueba 2
    Generador *generador1 = new Generador("Generador1",1500);
    Generador *generador2 = new Generador("Generador2",1500);

    try {
        centro1.setFuente(generador1);
    }catch (std::string &e){
        std::cerr<<e <<std::endl;
    }
    /*
    try {
        centro1.setFuente(generador2);
    }catch (std::string &e){
        std::cerr<<e <<std::endl;
    }
    */
    //Prueba 3
    try{
        centro1.instala(dispositivo1);
        centro1.instala(dispositivo2);
        centro1.instala(dispositivo3);
    } catch (std::string &e){
        std::cerr<<e <<std::endl;
    }

    //Prueba 4
    DataCenter centroCopia(centro1);
    dispositivo1->conmutaEstado();
    dispositivo2->conmutaEstado();
    std::cout<<centroCopia.ConsumoActual() <<std::endl;
    std::cout<<centroCopia.getNumDispositivos();
}
