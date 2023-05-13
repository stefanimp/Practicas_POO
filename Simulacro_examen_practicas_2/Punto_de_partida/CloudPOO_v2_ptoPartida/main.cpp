/**
 * @file main.cpp
 * @author ujapoo
 */
#include <iostream>
#include "Generador.h"
#include "Dispositivo.h"
#include "DataCenter.h"

void visualiza(Dispositivo &d) {
    std::cout << "Información del dispositivo" << std::endl
              << "=============" << std::endl
              <<  d.getDescripcion() << std::endl
              <<  "Consumo: " << d.getConsumo() << std::endl
              << (d.isActivo()?"Está":"No está")<< " activo" << std::endl;

    /* Ejercicio 6.- Adaptar para visualizar los datos específicos del dispositivo según su tipo*/

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


    /* Prueba 2: Asignar al segundo rack de servidores creado el primero de ellos.
     * Instalar en el DataCenter el segundo rack de servidores y los dos racks de almacenamiento.
     * Capturar, usando polimorfismo, cualquier excepción que pudiera generarse en el proceso.
     * Si la excepción capturada es de tipo DataCenterException, además del motivo debe mostrarse la potencia disponible del DataCenter en ese momento*/


    /**Prueba 3. En main, localizar el dispositivo con mayor consumo del DataCenter
     * y, si existe, visualiza sus datos con la función del ejercicio 6 */


    return 0;
}