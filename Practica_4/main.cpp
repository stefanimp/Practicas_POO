#include <cstdlib>
#include <iostream>
#include "Piloto.h"

using namespace std;

/**
 * @todo Ver el enunciado del ejercicio 5 de la práctica // HECHO
 */
int main ( int argc, char** argv )
{

    string datosPilotos[5] = {"Dameron Poe;Jakku;100;123456;---",
                              "Anakin Skywalker;Tatooine;133;126756;Derribados 3 cazas enemigos",
                              "Han Solo;Corellia;247;126786;Impacto en motor izquierdo",
                              "Chewbacca;Kashyyk;115;136786;---",
                              "Leia Organa;Alderaan;3;126336;Derribados 10 cazas enemigos"};
    string datosNaves[5] = {"Kuat Systems;Delta-7;1",
                            "Kuat Systems;Delta-7B;1",
                            "Incom Corporation;T-65B X-wing;1",
                            "Koensayr Manufacturing;Y-wing;2",
                            "Kuat Systems;A-wing;1"};
    string datosDroides[5] = {"Industrial Automation;R2-D2",
                              "Industrial Automation;R2-KT",
                              "AccuTronics;R3-D3",
                              "AccuTronics;R3-KT",
                              "Arakyd Industries;C3PO"};

    // Ejemplo de encadenamiento de llamadas a métodos sobre un objeto
    Informe i1;
    i1.setIdPiloto (1)
            .setFechaEstelar (31521231)
            .setDatosInforme ("Sin novedad");

   //Apartado 7 práctica 4
   //   Crear un array de 5 pilotos
   Piloto **pv_pilotos = new Piloto*[5];
    for (int i = 0; i < 5; ++i) {
        pv_pilotos[i] = nullptr;            // Inicializamos todos a nulo para evitar problemas de acceso a memoria(siempre debemos hacerlos así amenos que diractamente incicialicemos todos)
    }

   //   Crear un array de 5 naves
    StarFighter **pv_naves = new StarFighter*[5];
    for (int i = 0; i < 5; ++i) {
        pv_naves[i] = nullptr;
    }

    //  Crear un arrat de 5 droides
    Droide **pv_droides = new Droide*[5];
    for (int i = 0; i < 5; ++i) {
        pv_droides[i] = nullptr;
    }

    //Utiliza los setters de la clase Piloto y los datos del array datosPilotos para cargar información en los objetos de clase Piloto. (No tienes que procesar las cadenas de texto; simplemente copia y pega los datos).
    // Importante inicializar primero los elementos del vector piloto, que aún no lo están y si tratamos de asignar valores a los atributos de cada uno de los pilotos obtendremos un error
    for (int i = 0; i < 5; ++i) {
        pv_pilotos[i] = new Piloto();
    }
    try{
        pv_pilotos[0]->setNombre("Dameron Poe")
                .setNacionalidad("Jakku")
                .setNumMisiones(100)
                .setFechaUltimaMision(123456)
                .setIncidenciasUltimaMision("---");
        pv_pilotos[1]->setNombre("Anakin Skywalker")
                .setNacionalidad("Tatooine")
                .setNumMisiones(133)
                .setFechaUltimaMision(126756)
                .setIncidenciasUltimaMision("Derribados 3 cazas enemigos");
        pv_pilotos[2]->setNombre("Han Solo")
                .setNacionalidad("Corellia")
                .setNumMisiones(30)
                .setFechaUltimaMision(126786)
                .setIncidenciasUltimaMision("Impacto en motor izquierdo");
        pv_pilotos[3]->setNombre("Chewbacca")
                .setNacionalidad("Kashyyk")
                .setNumMisiones(115)
                .setFechaUltimaMision(136786)
                .setIncidenciasUltimaMision("---");
        pv_pilotos[4]->setNombre("Leia Organa")
                .setNacionalidad("Alderaan")
                .setNumMisiones(3)
                .setFechaUltimaMision(126336)
                .setIncidenciasUltimaMision("Derribados 10 cazas enemigos");
    } catch (std::invalid_argument &e){
        std::cout<<e.what();
    }

    //Utiliza los setters de la clase StarFighter y los datos del array datosNaves para cargar información en los objetos de clase StarFighter. (No tienes que procesar las cadenas de
    //texto; simplemente copia y pega los datos). (Inicialmente, cada StarFighter tiene distancia recorrida 0).
    //Inicializamos los StarFighters para poder darle valores a los atributos de cada uno
    for (int i = 0; i < 5; ++i) {
        pv_naves[i] = new StarFighter();
    }
    try{
        pv_naves[0]->setMarca("Kuat Systems")
                .setModelo("Delta-7")
                .setNumPlazas(1);
        pv_naves[1]->setMarca("Kuat Systems")
                .setModelo("Delta-7B")
                .setNumPlazas(1);
        pv_naves[2]->setMarca("Incom Corporation")
                .setModelo("T-65B X-wing")
                .setNumPlazas(1);
        pv_naves[3]->setMarca("Koensayr Manufacturing")
                .setModelo("Y-wing")
                .setNumPlazas(2);
        pv_naves[4]->setMarca("Kuat Systems")
                .setModelo("A-wing")
                .setNumPlazas(1);
    } catch (std::invalid_argument &e){
        std::cout<<e.what();
    }

    //Utiliza los setters de la clase Droide y los datos del array datosDroides[] para cargar información en los objetos de clase Droide. (No tienes que procesar las cadenas de
    //texto; simplemente copia y pega los datos)
    //Primero inicializamos los driodes para poder darle valor a sus atributos
    for (int i = 0; i < 5; ++i) {
        pv_droides[i] = new Droide();
    }
    try {
        pv_droides[0]->setMarca("Industrial Automation")
                .setModelo("R2-D2");    
        pv_droides[1]->setMarca("Industrial Automation")
                .setModelo("R2-K2");
        pv_droides[2]->setMarca("AccuTronics")
                .setModelo("R3-D3");
        pv_droides[3]->setMarca("AccuTronics")
                .setModelo("R3-KT");
        pv_droides[4]->setMarca("Arakyd Industries")
                .setModelo("C3P0");

    }catch (std::invalid_argument &e){
        std::cout<<e.what();
    }

    //Asocia el primer piloto con el tercer droide y la segunda nave
    try{
        pv_pilotos[0]->setAuxiliar(pv_droides[2])
                .setNave(pv_naves[1]);
    } catch (std::invalid_argument &e){
        std::cout<<e.what();
    }

    //Asocia el segundo piloto con el primer droide y la cuarta nave
    try {
        pv_pilotos[1]->setAuxiliar(pv_droides[0])
                .setNave(pv_naves[3]);

    }catch (std::invalid_argument &e){
        std::cout<<e.what();
    }

    //Asocia el tercer piloto con el segundo droide y la primera nave
    try{
        pv_pilotos[2]->setAuxiliar(pv_droides[1]);
        pv_pilotos[2]->setNave(pv_naves[2]);
    } catch (std::invalid_argument &e){
        std::cout<<e.what();
    }

    //Genera dos informes con los datos de las ultimas misiones de los dos primeros pilotos
    Informe informe1 =  pv_pilotos[0]->generaInforme();
    Informe informe2 =  pv_pilotos[1]->generaInforme();

    //Mostrar por la terminal los datos de los informes en formato csv
    std::cout<<informe1.toCSV() <<std::endl;
    std::cout<<informe2.toCSV() <<std::endl;

    //EJERCICIO CLASE

    StarFighter nave_prueba;
    nave_prueba.setMarca("Incom Corporation");

    Piloto piloto_prueba;
    try {
        piloto_prueba.setNombre("miau")
                .setNacionalidad("dawda")
                .setNumMisiones(23)
                .setIncidenciasUltimaMision("dwadawda")
                .setFechaUltimaMision(13131)
                .setNave(&nave_prueba);
    }catch (std::invalid_argument &e){
        std::cout <<e.what();
    }

    //Liberamos los recursos ocupados
    for (int i = 0; i < 5; ++i) {
        if(pv_pilotos[i] != nullptr){
            delete pv_pilotos[i];
            pv_pilotos[i] = nullptr;
        }
    }
    delete []pv_pilotos;
    pv_pilotos = nullptr;

    for (int i = 0; i < 5; ++i) {
        if(pv_naves[i] != nullptr){
            delete pv_naves[i];
            pv_naves[i] = nullptr;
        }
    }
    delete []pv_naves;
    pv_naves = nullptr;

    for (int i = 0; i < 5; ++i) {
        if(pv_droides[i] != nullptr){
            delete pv_droides[i];
            pv_droides[i] = nullptr;
        }
    }
    delete []pv_droides;
    pv_droides = nullptr;

    return 0;
}
