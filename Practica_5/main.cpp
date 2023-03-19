/** 
 * @file main.cpp
 * @author Casipro Gramo
 *
 * @date Fecha estelar 20160309
 */

#include "Piloto.h"
#include "Escuadron.h"


#include <cstdlib>
#include <string>
#include <iostream>

using namespace std;

/**
 * @todo Ver el enunciado del ejercicio 5 de la práctica
 */
int main ( int argc, char** argv )
{
    string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
                              "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
                              "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
                              "Chewbacca;Kashyyk;115;136786;---",
                              "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};

    //Ejercicio 6
    // Crea un array de 5 pilotos utilizando los datos de datosPilotos
    int num_pilotos = 5;
    Piloto **pilotos = new Piloto * [num_pilotos];
    for (int i = 0; i < num_pilotos; ++i) {
        pilotos[i] = new Piloto();
        pilotos[i]->fromCSV(datosPilotos[i]);
    }
    // Crea dos escuadrones
    Escuadron escuadron1("Escuadron 1","Base primera");
    Escuadron escuadron2("Escuadron 2","Base segunda");

    escuadron1.agnadirPiloto(pilotos[0]);
    escuadron1.agnadirPiloto(pilotos[1]);

    escuadron2.agnadirPiloto(pilotos[2]);
    escuadron2.agnadirPiloto(pilotos[3]);
    escuadron2.agnadirPiloto(pilotos[4]);
    //Muestra por consola el nombre y el promedio de misiones de cada escuadron
    std::cout<<"El nombre del primer escuadron es: " <<escuadron1.getNombre() <<" y  tiene un promedio de : " <<escuadron1.promedioMisiones() <<" misiones" <<std::endl;
    std::cout<<"El nombre del segundo escuadron es: " <<escuadron2.getNombre() <<" y  tiene un promedio de : " <<escuadron2.promedioMisiones() <<" misiones" <<std::endl;
    //Crea 2 starfighters, y añade 3 piezas a cada uno
    StarFighter nave1("VNM","4M");
    StarFighter nave2("Cedesmer","MGA");

    nave1.agnadirPieza("Peiza 1",23.4,"Pieza añadida desde el main");
    nave1.agnadirPieza("Pieza 2", 0.23,"Tornillo espacial");
    nave2.agnadirPieza("Pieza 3",3.2, "Parche gravitatorio");

    nave2.agnadirPieza("Peiza 1",23.4,"Pieza añadida desde el main");
    nave2.agnadirPieza("Pieza 2", 0.23,"Tornillo espacial");
    nave2.agnadirPieza("Pieza 3",3.2, "Parche gravitatorio");
    //Muestra por consola el peso de cada starfight
    std::cout<<"El peso de las peizas de la primera nave es de: " <<nave1.calculaPeso() <<std::endl;
    std::cout<<"El peso de las piezas de la segunda nave es de: " <<nave2.calculaPeso() <<std::endl;
    //Libera los recursos utilizados
    for (int i = 0; i < num_pilotos; ++i) {
        delete pilotos[i];
        pilotos[i] = nullptr;
    }
    delete[] pilotos;
    pilotos = nullptr;

    return 0;
}

