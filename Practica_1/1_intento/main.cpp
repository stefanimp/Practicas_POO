#include <iostream>

#include "vehiculo.h"

int main() {

    int tamagno_vec;
    vehiculo::Vehiculo *vehiculos = nullptr;
    std::cout <<"Introduzca el tamagno deseado: ";
    std::cin>> tamagno_vec;

    vehiculos = new vehiculo::Vehiculo[tamagno_vec];

    try {
        vehiculo::rellenarVector(vehiculos, tamagno_vec);
        //El cout solo se  ejecutará si la función rellenarVector se ejecuta de forma normal y sin lanzar errores, de los contrario, salará al catch
    }catch(const std::string &e) {
        //Capturamos la excepción e informamos
        std::cout<<"El dato no se ha leido: " <<e <<std::endl;
    }

    vehiculo::muestraEnPantalla(vehiculos, tamagno_vec);

    int pos_vehiculo = vehiculo::maxPrecio(vehiculos, tamagno_vec);

    vehiculo::muestraEnPantalla(vehiculos[pos_vehiculo]);

    std::string matricula;
    std::cout <<"Introduca la matricula del vehiculo que desea modiicar: ";
    std::cin>>matricula;

    pos_vehiculo = vehiculo::buscarPorMatricula(vehiculos,tamagno_vec, matricula);

    vehiculo::leePorTeclado(vehiculos[pos_vehiculo]);



    float porcentaje;
    std::cout <<"Introduzca un porcetaje para el precoi del vehiculo: ";
    std::cin >>porcentaje;

    try {
        vehiculo::incrementaPrecio(vehiculo::buscaMatricula(vehiculos, tamagno_vec, matricula), porcentaje);
    }catch(const std::string &e) {
        std::cout <<"No se ha podido incrementar el precio del vehiculo: " <<e;
    }

    

    delete[] vehiculos;
    vehiculos = nullptr;


    return 0;
}
