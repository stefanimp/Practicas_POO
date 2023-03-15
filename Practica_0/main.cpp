//
// Created by stefan on 13/02/2023.
//

#include <iostream>

using namespace std;

const int MIN_CARAC_MARCA = 3;
const int MAX_CARAC_MARCA = 30;
const int MAX_CARAC_MODELO = 20;
const int MIN_CARAC_MODELO = 1;
const int LONG_MATRICULA = 6;
const int MIN_PRECIO = 0;
const int MAX_VEHICULOS = 20;

struct Vehiculo{
    string marca, modelo, matricula;
    int agno_fabricacion;
    float precio;
};

string leeCadena(const int long_min, const int long_max){
    string cadena;
    do{
        cin>>cadena;
    }while(cadena.length() < long_min || cadena.length() > long_max);
    return cadena;
}

string leeCadena(const int num_caracteres){
    string cadena;
    do{
        cin>>cadena;
    }while(cadena.length() != num_caracteres);
    return cadena;
}

float leeNum(const float minimo){
    float numero;
    do{
        cin>>numero;
    } while(numero <= minimo);
    return numero;
}

void leePorTeclado(Vehiculo &vehiculo){
    cout <<"Introduzca la marca del vehiculo: ";
    vehiculo.marca = leeCadena(MIN_CARAC_MARCA, MAX_CARAC_MARCA);
    cout <<"Introduzca el modelo del vechiculo: ";
    vehiculo.modelo = leeCadena(MIN_CARAC_MODELO, MAX_CARAC_MODELO);
    cout <<"Introoduzca la matricula del vehiculo: ";
    vehiculo.matricula = leeCadena(LONG_MATRICULA);
    cout <<"Introduzca el agno de fabricacion: ";
    cin >>vehiculo.agno_fabricacion;
    cout <<"Introduzca el precio del vehiculo: ";
    vehiculo.precio = leeNum(MIN_PRECIO);
}

void leePorTeclado(Vehiculo *vehiculo){
    cout <<"Introduzca la marca del vehiculo: ";
    vehiculo->marca = leeCadena(MIN_CARAC_MARCA, MAX_CARAC_MARCA);
    cout <<"Introduzca el modelo del vechiculo: ";
    vehiculo->modelo = leeCadena(MIN_CARAC_MODELO, MAX_CARAC_MODELO);
    cout <<"Introoduzca la matricula del vehiculo: ";
    vehiculo->matricula = leeCadena(LONG_MATRICULA);
    cout <<"Introduzca el agno de fabricacion: ";
    cin >>vehiculo->agno_fabricacion;
    cout <<"Introduzca el precio del vehiculo: ";
    vehiculo->precio = leeNum(MIN_PRECIO);
}

void muestraEnPantalla(const Vehiculo& vehiculo){
    cout <<"Marca: " <<vehiculo.marca <<endl;
    cout <<"Modelo: "<<vehiculo.modelo <<endl;
    cout <<"Matricula: " <<vehiculo.matricula <<endl;
    cout <<"Agno de fabricacion: "<<vehiculo.agno_fabricacion <<endl;
    cout <<"Precio: " <<vehiculo.precio <<endl;
}

void definirVecVehiculos(Vehiculo vehiculos[], const int num_vehiculos){
    for(int i = 0; i < num_vehiculos; ++i){
        leePorTeclado(vehiculos[i]);
    }
}

void mostrarVecVehiculos(const Vehiculo vehiculos[], const int num_vehiculos){
    for(int i = 0; i < num_vehiculos; ++i){
        muestraEnPantalla(vehiculos[i]);
    }
}

Vehiculo* buscarMayorPrecio(const Vehiculo vehiculos[], const int num_vehiculos){
    float mayor_precio = vehiculos[0].precio;
    Vehiculo* vehiculo_mayor_precio = nullptr;
    for(int i = 0; i < num_vehiculos; ++i){
        if(vehiculos[i].precio > mayor_precio){
            mayor_precio = vehiculos[i].precio;
            *vehiculo_mayor_precio = vehiculos[i];
        }
    }
    return vehiculo_mayor_precio;
}

int main(){

    Vehiculo vehiculos[MAX_VEHICULOS] = {{"BMW", "Serie M3","BKG321",2019,100000.99}, {"Mercedes", "AMG", "JHB345", 2020, 200000.12}, {"Porsche", "Paramera", "HSU234", 2021, 500123.23}, {"BMW","M4","LJB962", 2011,150000.37}};
    int num_vehiculos = 3;
   /* cout <<"Cuantos vehiculos desea introducir: ";
    cin >>num_vehiculos;
    definirVecVehiculos(vehiculos, num_vehiculos);
    mostrarVecVehiculos(vehiculos, num_vehiculos);
    */
    cout <<&vehiculos[2]<<endl;
    Vehiculo *v1 = buscarMayorPrecio(vehiculos, num_vehiculos);
    cout <<v1 <<endl;



    return 0;
}
