#include <iostream>
#include <string>

const int MAX_VEHICULOS=100;

struct Vehiculo
{
    std::string marca;
    std::string modelo;
    std::string matricula;
    int anioFabricacion;
    float precio;

};


//funciones por referencia

/**
 * @brief Funcion que lee los datos de un vehículo por referencia
 * @param [in] vehiculo
 */
void leePorTeclado(Vehiculo &vehiculo)
{
    std::cout<<"Introduce la marca del vehiculo: "<<std::endl;
    std::cin>>vehiculo.marca;

    std::cout<<"Introduce la modelo del vehiculo: "<<std::endl;
    std::cin>>vehiculo.modelo;

    std::cout<<"Introduce la matricula del matricula: "<<std::endl;
    std::cin>>vehiculo.matricula;

    std::cout<<"Introduce el anio de fabricacion del vehiculo: "<<std::endl;
    std::cin>>vehiculo.anioFabricacion;

    std::cout<<"Introduce el precio del vehiculo: "<<std::endl;
    std::cin>>vehiculo.precio;

}

/**
 * @brief Funcion que muestra en pantalla los datos de la funcion anterior (por referencia)
 * @param vehiculo2
 */
void muestraEnPantalla(Vehiculo vehiculo2)
{
    std::cout<<std::endl;
    std::cout<<"La marca del vehiculo es: " << vehiculo2.marca << std::endl;
    std::cout<<"La modelo del vehiculo es: " << vehiculo2.modelo << std::endl;
    std::cout<<"La marca del matricula es: " << vehiculo2.matricula << std::endl;
    std::cout<<"El anio de fabricacion del vehiculo es: " << vehiculo2.anioFabricacion << std::endl;
    std::cout<<"El precio del vehiculo es: " << vehiculo2.precio<< std::endl;

    std::cout<<std::endl;

}


// funciones con punteros

/**
 * @brief Funcion que lee los datos de un vehículo por punteros
 * @param vehiculo
 */
void leePorTeclado(Vehiculo *vehiculoLeer)
{
    leePorTeclado(*(vehiculoLeer));
}

/**
 * @brief Funcion que muestra en pantalla los datos de la funcion anterior (por punteros)
 * @param vehiculo2
 */
void muestraEnPantallaPunt(Vehiculo &vehiculo2)
{
    std::cout<<"La marca del vehiculo es: " << vehiculo2.marca << std::endl;
    std::cout<<"La modelo del vehiculo es: " << vehiculo2.modelo << std::endl;
    std::cout<<"La marca del matricula es: " << vehiculo2.matricula << std::endl;
    std::cout<<"El anio de fabricacion del vehiculo es: " << vehiculo2.anioFabricacion << std::endl;
    std::cout<<"El precio del vehiculo es: " << vehiculo2.precio<< std::endl;

}

//Ejercicio 1 Práctica 0 - Clase

void incrementarPrecio (float increm,Vehiculo &vehiculoFuncion)
{
    vehiculoFuncion.precio+=increm;
}

Vehiculo *devolverPuntero(Vehiculo vectVehiculo[], const int tam, const std::string marcaDada)
{
    for (int i=0; i<tam; ++i)
    {
        if(marcaDada==vectVehiculo[i].marca)
        {
            return &vectVehiculo[i];
        }
    }

    return nullptr;
}



int main() {

    // declarar variables
    Vehiculo vehiculoMain;
    Vehiculo *vehiculoPunt;

    float incremento=0;
    char respuesta;
    std::string marcaPedida;

    Vehiculo vectorVehiculos[MAX_VEHICULOS];
    int numVehiculos=0; //tamaño ocupado del vector

    //pedir al usuario el numero de vehiculos
    std::cout<<"Introduce el numero de vehiculos quiere introducir: "<<std::endl;
    std::cin>>numVehiculos;

    /*
    // llamar a las funciones por referencia
    leePorTeclado(vehiculoMain);
    muestraEnPantalla(vehiculoMain);


    // llamar a las funciones por punteros
    leePorTeclado(*vehiculoPunt);
    muestraEnPantallaPunt(*vehiculoPunt);

    */




    //Ejercicio 5 Apartado 2
    for(int i=0; i<numVehiculos; ++i)
    {
        leePorTeclado(vehiculoMain);
        vectorVehiculos[i]=vehiculoMain;

        std::cout<<"Quiere incrementar el precio de algun vehiculo? (Introduce 'S' en caso afirmativo"<<std::endl;
        std::cin>>respuesta;

        if (respuesta=='S'||respuesta=='s') {

            std::cout << "Cuanto quiere incrementar el precio del vehiculo?" << std::endl;
            std::cin >> incremento;

            incrementarPrecio(incremento, vehiculoMain);

            std::cout << "El precio del vehiculo incrementado es: " << vehiculoMain.precio << std::endl;
        }
    }


    //Ejercicio 1 Práctica 0 - Clase

    std::cout<<"Quiere incrementar el precio de algun vehiculo? (Introduce 'S' en caso afirmativo"<<std::endl;
    std::cin>>respuesta;

    if (respuesta=='S'||respuesta=='s') {

        std::cout << "Cuanto quiere incrementar el precio del vehiculo?" << std::endl;
        std::cin >> incremento;

        incrementarPrecio(incremento, vehiculoMain);

        std::cout << "El precio del vehiculo incrementado es: " << vehiculoMain.precio << std::endl;
    }

    //Ejercicio 2 Practica 0 - Clase

    std::cout<<"Introduce una marca para buscar el vehiculo: "<<std::endl;
    std::cin>>marcaPedida;

    std::cout<<"El vehiculo encontrado es: "<<devolverPuntero(vectorVehiculos,numVehiculos,marcaPedida);




    return 0;
}
