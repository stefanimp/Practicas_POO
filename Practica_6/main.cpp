/**
 * @file main.cpp
 * @author 
 *
 */

#include <iostream>
#include <fstream>
#include "EquipoMutante.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza( Mutante& m) {
    std::cout << "MUTANTE: " 
              << m.toCSV() << std::endl;
    std::cout << "  Poderes : " << std::endl;
    //ToDo, Mostrar los poderes del mutante
    for (int i = 0; i < m.getNumPoderes(); ++i) {
        std::cout<<m.mostrarPoder(i);
        std::cout<<endl;
    }
}
/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza( EquipoMutante& eq) {
    std::cout << "EQUIPO: " << eq.getNombre() 
              << " (Base: " << eq.getBase()<< ")" <<std::endl
              << "============================"
              << std::endl;
    //ToDo, Mostrar los mutantes del equipo (usar función anterior)
    for (int i = 0; i < eq.getNumMiembros(); ++i) {
        visualiza(*eq.getMutante(i));
    }
}

//ToDo, Método para almacenar un vector de punteros a mutantes (HECHO)
//!!!!!IMPORTANTE¡¡¡¡¡¡ El archivo se está creando dentro de la carpeta cmake build debug
void almacenaMutantesCSV(Mutante *mutantes[], int tamv, std::string nomArch){
    std::ofstream archivo;
    archivo.open(nomArch.c_str());  //Creamos el archivo con el nombre almacenado en nomArch
    if(archivo.good()){                 //Si se ha creado con éxito entonces comienza el bucle para escribir los datos en el
        for (int i = 0; i < tamv; ++i) {
            archivo<<mutantes[i]->toCSV()<<std::endl;
        }
        archivo.close();
        std::cout<<"Los datos se han escrito correctamente en el archivo."<<std::endl;
    }else{
        std::cout<<"El archivo no se ha abierto correctamente";
    }
}


int main(int argc, char** argv) {

    
   // Crea un array de 5 punteros a mutantes, asignándoles los valores a sus
   // atributos directamente en el código fuente
   Mutante **mutantes = new Mutante * [5];
   mutantes[0] = new Mutante("Manolo", "Amador Rivas",19990101,"Español");
   mutantes[1] = new Mutante("Andrea","chiqui",18672332,"Marroquí");
   mutantes[2] = new Mutante("adolfo", "Wolverine",13001312, "Japonnes");
   mutantes[3] = new Mutante("Muso","ChairWheel",8971102,"Desconocida");
   mutantes[4] = new Mutante("Maik","Tormenta",18670216,"Americana");

    
   // Crea dos equipos mutantes, asignando al primero los mutantes que ocupan
   // las posiciones pares del array, y al segundo los de las posiciones impares
   EquipoMutante equipo1;
   EquipoMutante equipo2;

   equipo1.addMutante(mutantes[0]);
   equipo1.addMutante(mutantes[2]);
   equipo1.addMutante(mutantes[4]);

   equipo2.addMutante(mutantes[1]);
   equipo2.addMutante(mutantes[3]);
    
    
   // Añade varios poderes a cada mutante, utilizando los métodos ya
   // implementados: usando datos o objetos de tipo Poder
   mutantes[0]->addPoder("Camelar","Camela a quien sea","Todos especialmente a los mas faltos de cariño",0);
   mutantes[1]->addPoder("Nada","No hace nada pero lo hace genial","A nada", 10);
   mutantes[2]->addPoder("Garras","Tiene unas garras hechas de un material practicamente indestructible","A cualquoera que le haga enfadar", 11);
   mutantes[3]->addPoder("Telequinesis","Teliquinesis y encima tactica","A todos los que esten espuestos a su alcance",623);
   mutantes[4]->addPoder("Rayos","Lanza buenos rayos","A todos en un rango de 11km",0);
   // Muestra por la consola la información de cada equipo mutante en formato CSV
    visualiza(equipo1);
    visualiza(equipo2);
    
   //Guardamos datos de mutantes en fichero CSV
   almacenaMutantesCSV(mutantes,5,"mutantes.csv");
   //Ejercicios de clase


   if((equipo1.getCapacidadDestructiva()) < (equipo2.getCapacidadDestructiva())){
       std::cout <<"El segundo equipo tiene mayor capacidad destructiva";
   } else{
       std::cout <<"El primer equipo tiene mayor capacidad destructiva";
   }
   // Destruye todos los objetos creados en memoria dinámica antes de la
   // finalización del programa
    for (int i = 0; i < 5; ++i) {
        delete mutantes[i];
        mutantes[i] = nullptr;
    }
    delete mutantes;
    mutantes = nullptr;

    
    
    return 0;
}

