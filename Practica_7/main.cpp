/**
 * @file main.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <iostream>
#include <fstream>
#include "EquipoMutante.h"
#include "ordena.h"

using namespace std;

/***@brief Visualiza la información completa de un mutante*/
void visualiza ( Mutante& m)
{
   std::cout << "MUTANTE: " 
             << m.toCSV() << std::endl;
   std::cout << "  Poderes : " << std::endl;
   for (int i = 0; i < m.getNumPoderes(); i++)
   {
      std::cout << "    - " << m.getPoder(i).toCSV()<<std::endl;
   }
}

/***@brief Visualiza los datos de todos los miembros de un equipo mutante*/
void visualiza ( EquipoMutante& eq )
{
   std::cout << "EQUIPO: " << eq.getNombre() 
             << " (Base: " << eq.getBase()<< ")" <<std::endl
             << "============================"
             << std::endl;
   for ( int i = 0; i < eq.getNumMiembros(); i++ )
   {
      visualiza ( *(eq.getMutante(i)) );
   }
}

//ToDo
/***@brief Visualiza un vector de mutantes en formato CSV*/
void visualiza (Mutante *mutantes[], int numMutantes){
    for (int i = 0; i < numMutantes; ++i) {
        std::cout<<mutantes[i]->toCSV() <<std::endl;
    }
}


/**@brief Almacena los mutantes de un vector en una archivo CSV 
   @param Mutante* v[], vector de punteros a objetos mutantes
   @param unsigned int tamv, número de mutantes almacenados en el vector
   @param string nomArchivo, archivo donde se almacenarán los mutantes. Si ya sobreescribirá.
   @post  Almacena los datos simples (sin poderes) de cada mutante en formato CSV en una línea diferente del Archivo indicado
 */
void almacenaMutantesCSV ( Mutante* v[], unsigned int tamv,
                           std::string nomArchivo){
   std::ofstream archivo;
   archivo.open ( nomArchivo.c_str() ); //c_str() no es necesario si compilador soporta >= C++11

   if ( archivo.good ( ) )
   {
      for ( unsigned int i = 0; i < tamv; i++ )
      {
         archivo << v[i]->toCSV() << std::endl;
      }
      
      archivo.close ( );
   }
}

//ToDo (HECHO)
/**@brief Recupera los mutantes de un fichero CSV en un vector
   @param Mutante* v[], vector de punteros a objetos mutantes
   @param unsigned int tamv, número máximo de mutantes que se pueden almacenar en v
   @param string nomArchivo, archivo de donde se recuperarán los mutantes en formato CSV
   @post  Las posiciones del vector se sobreescribirán
   @post  Recupera mutantes del fichero y los crea en memoria dinámica, asociando cada uno a una posición del vector
   @return número de mutantes leídos y creados (como máximo será tamv)
 */

int recuperaMutantesCSV ( Mutante* v[], unsigned int tamv, std::string nomArchivo){
    //Contador de cuantos mutantes recuperamos del archivo
    int num_mutantes = 0;
    //Instanciamos el flujo de entrada
    ifstream fe;

    std::string cad;
    //Asociamos el flujo con un archivo y lo abrimos
    fe.open(nomArchivo.c_str());
    //Si el archico se ha cargado correctamente y no hay banderas de error
    if(fe.good()){
        //Mientras no se haya llegado al final del archivo y el numero de mutantes almacenado no supere el límite
        while (!fe.eof() && num_mutantes < tamv){
            getline(fe,cad);    //Toma una linea del archivo
            if(cad != ""){              //Ignoramos líneas en blanco
                //Pasa la línea a uno de los objetos del array para que la procese y copie los datos que contiene en sus atributos
                v[num_mutantes++]->fromCSV(cad);
                cad=""; //Evitamos introducir dos veces la última línea
                //Como desde el formato csv no implementamos poderes deberemos borrar(en caso de que existan) los poderes que había en el anteriror mutante donde ahora está el del formato csv
                v[num_mutantes-1]->borraPoderes();
                v[num_mutantes-1]->setNumPoderes(0);
            }
        }
        //Cerramos el flujo de entrada
        fe.close();
    }
    return num_mutantes;

}

/**@brief inicializa vector de mutantes y crea algunos
   @pre v debe tener al menos tamv posiciones
   @post se inicializan todas las posiciones de v a 0 o a un nuevo mutante 
   @return número de muntantes creados en el vector*/
int inicializaMutantes ( Mutante* v[], int tamv )
{
   for ( int i = 0; i < tamv; i++ )
   {
      v[i]=0;
   }

   int creados = 0;
   v[creados++] = new Mutante("Logan", "Lobezno", 19320101, "Estadounidense");
   v[creados++] = new Mutante("Marie", "Rogue", 19700101, "Estadounidense");
   v[creados++] = new Mutante("Ororo", "Tormenta", 19500101, "Keniata");
   v[creados++] = new Mutante("Scott", "Cíclope", 19300101, "Estadounidense");
   v[creados++] = new Mutante("Charles", "Profesor X", 19200101, "Estadounidense");

   return creados;
}


int main ( int argc, char** argv )
{

   const int MAXMUTANTES = 5;
   Mutante* mutantes[MAXMUTANTES];
   int numMutantes = 0;
   std::string archivoMutantes="mutantes.csv";

   numMutantes = inicializaMutantes ( mutantes, MAXMUTANTES );
   //ToDo, recuperar mutantes del archivo (HECHO)

    recuperaMutantesCSV(mutantes,5,archivoMutantes);

   //ToDo, Visualizar vector de mutantes en formato CSV (HECHO)

    visualiza(mutantes,5);

   //Creación de los equipos y configuración de poderes
   EquipoMutante equipo1 ( "Patrulla X", "Mansión" );
   equipo1.addMutante ( mutantes[1] );
   equipo1.addMutante ( mutantes[3] );

   EquipoMutante equipo2 ( "Los malos", "Casa Magneto" );
   equipo2.addMutante ( mutantes[0] );
   equipo2.addMutante ( mutantes[2] );
   equipo2.addMutante ( mutantes[4] );

   //Diferentes formas de añadir poderes: usando datos o objetos de tipo Poder
   mutantes[0]->addPoder ( "longevidad", "vivir mucho", "su cuerpo", 1 );
   mutantes[1]->addPoder ( Poder( "absorción", "absorve poderes de otros mutantes",
                                  "cualquier mutante", 100 ) );
   mutantes[2]->addPoderFisico ( "clima", "puede manejar el clima", "atmósfera",
                                 151 );
   mutantes[3]->addPoder( PoderFisico ( "rayo", "expulsa láser por los ojos",
                                        "lo que pille por delante", 500 ) );
   mutantes[4]->addPoder ( PoderPsiquico ( "AtacaMente",
                                           "ataca la mente de su enemigo",
                                           "cualquiera", 150 ) );

   //Ejercicio 9.3
   PoderPsiquico asfixia("Asfixia","Pues asfixia xd","Oponentes biologicos",600);
   //Modificamos la lucidez
   asfixia.setLucidez(0.75);
   //Visualidamos la capacidad destructiva total del mutante antes de añadirle el poder asfixia
   std::cout <<"Capaciada destructiva total antes de agnadir asfixia: "<<mutantes[0]->capacidadDestructivaTotal() <<std::endl;
    mutantes[0]->addPoder(asfixia);
    //Visualidamos la capacidad destructiva total del mutante despues de añadirle el poder asfixia
    std::cout <<"Capaciada destructiva total despues de agnadir asfixia: "<<mutantes[0]->capacidadDestructivaTotal() <<std::endl;

    //Vemos que es importante colocar el para que la comparacíon se realice de manera correcta, sin esto no funcionará
    /*
    if(*mutantes[4] < *mutantes[1]){
        std::cout<<"Miauuuuuuuuuuuuuuuuuu";
    } else{
        std::cout<<"EEEEEEEEEEEEEE";
    }
     */

    //Ejercicio 9.4
    ordena(mutantes,5);
    for (int i = 0; i < MAXMUTANTES; ++i) {
        std::cout<<mutantes[i]->getNombreReal() <<std::endl;
    }

    //Ejercicio 9.5
    Poder *poderes[4];
    poderes[0] = new Poder("Poder 1","dawdw","A tu hermano",9669);
    poderes[1] = new PoderPsiquico("Poder 2","dadw","A tu padre",696969,0.5);
    poderes[2] = new PoderFisico("Poder 3","adawd","A tu prima",100);
    poderes[3] = new Poder("Poder 4","dawawd","a tu abuela",1);

    ordena(poderes,4);
    for (int i = 0; i < 4; ++i) {
        std::cout<<poderes[i]->getCapacidadDestructiva() <<std::endl;
    }

   visualiza ( equipo1 );
   visualiza ( equipo2 );

   //ToDo, Crear poder físico asfixia y añadir a Doctor X

   //ToDo, Ordenar y visualizar vector de mutantes con plantilla de método Ordena
   //Comprobar que DoctorX a mejorado su posición por que ha aumentado su capacidad
   //Destructiva

   almacenaMutantesCSV ( mutantes, 5, archivoMutantes );


   for ( int i = 0; i < MAXMUTANTES; i++ )
   {
      delete mutantes[i];
      mutantes[i] = nullptr;
   }

   return 0;
}