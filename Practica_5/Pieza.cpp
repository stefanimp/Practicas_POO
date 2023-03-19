/** 
 * @file Pieza.cpp
 * @author Yoyapro Gramo
 * 
 * @date Fecha estelar 20160317
 */

#include "Pieza.h"

using std::string;

/**
 * @todo Hay que comprobar que el peso no sea un valor negativo. Si lo es, se
 *       lanzaría una excepción de tipo std::invalid_argument
 */
Pieza::Pieza ( string nombre, float peso, string descripcion ):
_nombre(nombre), _peso(peso),
_descripcion(descripcion){
    if(peso < 0){
        throw std::invalid_argument("Pieza::Pieza: el peso no puede ser negativo");
    }
}

Pieza::Pieza ( const Pieza& orig ): Pieza ( orig._nombre,
                                            orig._peso,
                                            orig._descripcion)
{
}

Pieza::~Pieza ( )
{
}

Pieza& Pieza::setDescripcion ( string descripcion )
{
   this->_descripcion = descripcion;
   return *this;
}

string Pieza::getDescripcion ( ) const
{
   return _descripcion;
}

/**
 * @todo Hay que comprobar que el peso no sea un valor negativo. Si lo es, se
 *       lanzaría una excepción de tipo std::invalid_argument //HECHO
 */
Pieza& Pieza::setPeso ( float peso ){
    if (peso < 0){
        throw std::invalid_argument("Pieza::setPeso: el peso no puede ser negativo");
    }
   this->_peso = peso;
   return *this;
}

float Pieza::getPeso ( ) const
{
   return _peso;
}

Pieza& Pieza::setNombre ( string nombre )
{
   this->_nombre = nombre;
   return *this;
}

string Pieza::getNombre ( ) const
{
   return _nombre;
}

Pieza& Pieza::operator = (const Pieza& orig)
{
    if (this!= &orig) {
        _nombre = orig._nombre;
        _descripcion = orig._descripcion;
        _peso = orig._peso;
    }
   
   return *this;
}

void Pieza::fromCSV(std::string valores) {
    std::stringstream ss;
    ss.str(valores);
    std::getline(ss, this->_nombre,';');
    ss>> this->_peso;
    ss.ignore(1);
    std::getline(ss, this->_descripcion,';');
}