#include <iostream>

#include <iostream>
#include <string>
#include <stdexcept>

#include "Factura.h"

int main() {

    //Declarar un vector de tres clientes inializados con distintos datos(Alguno sin su nombre o direccion)
    Cliente **clientes = new Cliente * [3];
    for (int i = 0; i < 2; ++i) {
        clientes[i] = new Cliente("mew", "calle");
    }
    clientes[2] = new Cliente();

    //Declarar una factura con la fecha actual y asignarle un cliente válido de los disponibles
    Factura factura1(230327);

    try{
        factura1.setCliente(clientes[0]);
    }catch (std::invalid_argument &e){
        std::cerr<<e.what();
    }

    //Añadir tres articulos
    try {
        factura1.agnadirArticulos("Pera", 0.45);
    } catch (std::out_of_range &e){
        std::cerr<<e.what();
    }

    try {
        factura1.agnadirArticulos("Limones",2.32);
    }catch (std::out_of_range &e){
        std::cerr<<e.what();
    }
    try {
        factura1.agnadirArticulos("Dulces",1);
    }catch (std::out_of_range &e){
        std::cerr<<e.what();
    }

    //Crear una copia de factura
    Factura factura2(factura1);

    //Asignnar a la nueva factura articulos adicionales de forma que se supere el limite permitito y capturar la excepcion
    try {
        factura2.agnadirArticulos("Flores",23.3);
        factura2.agnadirArticulos("Hamburguesas",5.99);
        factura2.agnadirArticulos("Salsa gaucha",1.99);
    }catch (std::out_of_range &e){
        std::cerr<<e.what();
    }

    //Mostrar el nombre del cliente de la segunda factura y su importe total
    std::cout<<factura2.getNombreCliente() <<std::endl;
    factura2.importe();
    clientes[2]->setNombre("dadaddad");
    std::cout<<clientes[2]->getNombre();
    //Liberar los recursos necesarios
    for (int i = 0; i < 3; ++i) {
        if(clientes[i] != nullptr) {
            delete clientes[i];
            clientes[i] = nullptr;
        }
    }
    delete[] clientes;
    clientes = nullptr;

    return 0;
}
