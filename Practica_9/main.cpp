/* 
 * File:   main.cpp
 * Author: jrbalsas
 *
 * Created on 15 de abril de 2016, 11:11
 */

#include <cstdlib>
#include <iostream>

#include "ContenedorItems.h"
#include "Item.h"
#include "Bloque.h"
#include "Espada.h"
#include "Filete.h"
#include "Cofre.h"
#include "Inventario.h"

using namespace std;

/**Inicializa el vector de items inicial
 * @pre v no contiene punteros inicializados
 * @post crea algunos objetos en el vector e inicializa el resto de elementos a 0
 * @return número de posiciones del vector con items creados*/
void inicializaItems(ContenedorItems &contenedor) {
    contenedor.mete(new Bloque(5));
    contenedor.mete(new Bloque(8));
    contenedor.mete(new Bloque());
    contenedor.mete(new Espada());
    contenedor.mete(new Filete());
}

/**Libera los items del vector creados en memoria dinámica*/
void liberaItems(ContenedorItems &contenedor) {
    for (int i = 1; i < contenedor.cuantosHay(); i++) {
        contenedor.saca(i);
    }

}

void visualiza(Cofre &c) {
    std::cout << "CONTENIDO DEL COFRE" << std::endl
            << "===================" << std::endl;
    for (int i = 1; i <= c.cuantosHay(); i++) {
        std::cout << i << ".- "
                << c.consulta(i).getDescripcion() << std::endl;
    }

}

/**@brief Probando los Cofres
 * 
 */
int main(int argc, char** argv) {

    ContenedorItems objetos;

    try {

        //Inicializamos algunos objetos de prueba
        inicializaItems(objetos);

        Cofre c; //Creamos un cofre con 27 posiciones

        //Metemos todos los objetos en el cofre

        try {
            for (int i = 1; i < objetos.cuantosHay() + 1; i++) {
                c.mete(&objetos.consulta(i));
            }
        }catch(std::exception &e) {
            //Capturamos cualquier excepción de la jerarquía que pueda generar
            //Consulta::mete. Es decir: out_of_range y invalid_argument
            std::cerr   << "Error al intentar meter un objeto en el cofre: "
                        << e.what() << std::endl;
        }

        visualiza(c);

        //Liberamos recursos
        liberaItems(objetos);
        
    } catch (std::exception &e) {
        //Capturamos cualquier excepción que se haya podido escapar
        //En tiempo de desarrollo
        std::cerr << "Finalización del programa por excepción sin capturar: "
                << e.what() << std::endl;
    }
    return 0;
}

