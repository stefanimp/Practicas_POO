/**
 * @file main.cpp
 * @author ujapoo
 */
#include <iostream>
#include "Generador.h"
#include "Dispositivo.h"
#include "DataCenter.h"
#include "RackServidores.h"
#include "RackAlmacenamiento.h"

void visualiza(Dispositivo &d) {
    std::cout << "Información del dispositivo" << std::endl
              << "=============" << std::endl
              <<  d.getDescripcion() << std::endl
              <<  "Consumo: " << d.getConsumo() << std::endl
              << (d.isActivo()?"Está":"No está")<< " activo" << std::endl;

    /* Ejercicio 6.- Adaptar para visualizar los datos específicos del dispositivo según su tipo*/
    RackServidores *prueba = dynamic_cast <RackServidores*>(&d);
    if (prueba){
        std::cout<<"Total servidores: " <<prueba->getTotalServidores()<<std::endl
        <<"Servidores Operativos: " <<prueba->getServidoresOperativos() <<std::endl;
    }
    RackAlamacenamiento *prueba2 = dynamic_cast <RackAlamacenamiento*>(&d);
    if(prueba2){
        std::cout<<"Capacidad Total: "<<prueba2->getCapacidadTotal() <<std::endl;
    }

}

int main () {

    DataCenter dc1("Campus Las Lagunillas",20);
    dc1.setTecnicos(2);

    Generador gen1("Power POO Gen v1",1100);
    dc1.setFuente(gen1);

    /* Prueba 1: Crear dos Racks de servidores: el primero con 1000W de consumo máximo y 10 servidores en total, el segundo con 2000W y 20 servidores.
     * Crear dos Racks de almacenamiento con consumos de 800W y 1500W, y capacidades de 10 y 100 Terabytes respectivamente.
     * Reducir el número de servidores activos del primer rack a 9 y visualizar su descripción y consumo.
     * Capturar y mostrar cualquier excepción que pudiera ocurrir durante las operaciones realizadas*/
    RackServidores *racks1 = new RackServidores("Rack de servidores 1",1000, 10);
    RackServidores *racks2 = new RackServidores("Rack de servidores 2",2000,20);
    RackAlamacenamiento *racka1 = new RackAlamacenamiento("RAck de almacenamiento 1",800,10);
    RackAlamacenamiento *racka2 = new RackAlamacenamiento("Rack de almacenamiento 2",1500,100);

    try{
        racks1->setServidoresOperativo(9);
    }catch (std::out_of_range &e){
        e.what();
    }
    try{
        dc1.instala(*racks2);
    }catch (DataCenterExcepcion &e){
        std::cout<<e.what() << "Potencia disponible en el DataCenter: " <<dc1.getPotenciaDisponible();
    }catch (std::out_of_range &e){
        std::cout<<e.what();
    }


    /* Prueba 2: Asignar al segundo rack de servidores creado el primero de ellos.
     * Instalar en el DataCenter el segundo rack de servidores y los dos racks de almacenamiento.
     * Capturar, usando polimorfismo, cualquier excepción que pudiera generarse en el proceso.
     * Si la excepción capturada es de tipo DataCenterException, además del motivo debe mostrarse la potencia disponible del DataCenter en ese momento*/

    *racks2 = *racks1;  //Importante utilizar los punteros para igualar, ya que si no no estaremos usando el operador de asignación sobrecargado, si no que estaremos diciceindo que el segundo servidor apunte al primero(si no hubiesemos creado los servidores como punteros no harían faltas estos para aplicar el operador de asignación=

    /**Prueba 3. En main, localizar el dispositivo con mayor consumo del DataCenter
     * y, si existe, visualiza sus datos con la función del ejercicio 6 */

    Dispositivo *mayorconsumo = dc1.mayorConsumo();
    if(mayorconsumo){
        visualiza(*mayorconsumo);
    };


    return 0;
}