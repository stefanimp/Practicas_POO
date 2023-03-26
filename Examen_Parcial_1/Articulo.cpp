//
// Created by stefan on 27/03/2023.
//

#include "Articulo.h"

int Articulo::num_articulos = 0;

Articulo::Articulo():
nombre(""),
importe(0){
    ++num_articulos;
    id = num_articulos;
}

Articulo::Articulo(std::string nombre, float importe):
nombre(nombre),
importe(importe){
    ++num_articulos;
    id = num_articulos;
}

/**
 * @brief   Constructor por copia de la clase Articulo
 * @details Suponemos que cada tipo de articulo tiene un ID unico pero pueden existir mas de un articulo del mismo tipo, en este caso tendrían el mismo ID a pesar de ser artículos independiente con las mismas características. De esta forma podríamos ver cuantos artículos de un mismo tipo hay( también se podría realizar a partir del nombre pero para este programa tomaremos esta decisión, si queremos algo más acertado el enunciado debería especificar más el problemas, como no lo hace nosotros elegiremos esta solución)
 * @param original   Articulo del que se copiaran los atributos
 * @post    Se crea un nuevo objeto con los mismo atributos que el original
 * */
Articulo::Articulo(const Articulo &original):
nombre(original.nombre),
importe(original.importe),
id(original.id){
}
Articulo::~Articulo() {}

void Articulo::setNombre(std::string nomrbe) {
    this->nombre = nomrbe;
}

void Articulo::setImporte(float importe) {
    this->importe = importe;
}

std::string Articulo::getNombre() const {
    return nombre;
}

float Articulo::getImporte() const {
    return importe;
}

int Articulo::getID() const {
    return id;
}