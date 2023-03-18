/** 
 * @file StarFighter.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <stdexcept>
#include <sstream>

#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( ): StarFighter ( "", "" ) {
}

StarFighter::StarFighter ( string marca, string modelo ):
                           _marca (marca),
                           _modelo(modelo),
                           num_piezas(1),
                           partes(new Pieza*[1]){
    partes[0] = new Pieza("Controlador", 2.78, "Controlador por defecto que incorporan todas las naves");
    ++num_piezas;
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::StarFighter ( const StarFighter& orig ):
    _marca(orig._marca),_modelo(orig._modelo),
    _numPlazas(orig._numPlazas),
    num_piezas(orig.num_piezas),
    partes(orig.partes)
{
   _numStarFighters++;
   _idSF = _numStarFighters;
}

StarFighter::~StarFighter ( ){
    for (int i = 0; i < num_piezas; ++i) {
        delete partes[i];
        partes[i] = nullptr;
    }
    delete [] partes;
    partes = nullptr;
}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción
 *       correspondiente. El número de plazas no puede ser <= 0
 */
StarFighter& StarFighter::setNumPlazas ( int numPlazas )
{
   if ( numPlazas <= 0 )
   {
      throw std::invalid_argument ( "StarFighter::StarFighter: el número de"
                                    " plazas no puede ser negativo" );
   }

    this->_numPlazas = numPlazas;
    return *this;
}

int StarFighter::getNumPlazas ( ) const
{
   return _numPlazas;
}

StarFighter& StarFighter::setModelo ( string modelo )
{
   this->_modelo = modelo;
   return *this;
}

string StarFighter::getModelo ( ) const
{
   return _modelo;
}

StarFighter& StarFighter::setMarca ( string marca )
{
   this->_marca = marca;
   return *this;
}

string StarFighter::getMarca ( ) const
{
   return _marca;
}

int StarFighter::getIdSF ( ) const
{
   return _idSF;
}

string StarFighter::toCSV () const
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo << " ; "
       << _numPlazas;

   return aux.str ();
}

StarFighter& StarFighter::operator = (const StarFighter& otro)
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
      _numPlazas = otro._numPlazas;
   }

   return *this;
}

void StarFighter::fromCSV (string& datos)
{
   std::stringstream aux;
   
   aux << datos;
   
   getline ( aux, _marca, ';' );
   getline ( aux, _modelo, ';' );
   aux >> _numPlazas;
}

void StarFighter::desplazaIzquierda(int posicion) {
    for (int i = posicion; i < num_piezas - 1 ; ++i) {
        partes[i] = partes[i+1];
    }
}

void StarFighter::agnadirPieza(std::string nombre, float peso, std::string descripcion) {
    if(num_piezas == MAX_PARTES){
        throw std::length_error("StarFighter::agnadirPieza: se ha alcanzado el numero máximo de piezas que puede agregar una nave");
    }
    ++num_piezas;
    Pieza **copia = new Pieza * [num_piezas];
    for (int i = 0; i < num_piezas - 1; ++i) {
        copia[i] = partes[i];
        partes[i] = nullptr;
    }
    delete[] partes;

    partes = copia;
}

void StarFighter::eliminarPieza(const Pieza &pieza) {
    int posicion;
    for (int i = 0; i < num_piezas; ++i) {
        if(partes[i] == &pieza){
            posicion = i;
        }
    }
    delete partes[posicion];
    partes[posicion] = nullptr;
    StarFighter::desplazaIzquierda(posicion);
    --num_piezas;
}

void StarFighter::eliminarPieza(std::string nombre) {
    for (int i = 0; i < num_piezas; ++i) {
        if(partes[i]->getNombre() == nombre){
            delete partes[i];                               //Es importante hacer el delete ya que aunque desplazemos el vector y el contenido de la posición donde se encuentra la pieza ya no sea accesible sigue existiendo en memoria
            partes[i] = nullptr;
            StarFighter::desplazaIzquierda(i);
            --num_piezas;
        }
    }
}