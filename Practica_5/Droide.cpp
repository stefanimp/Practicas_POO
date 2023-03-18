/** 
 * @file Droide.cpp
 * @author Casipro Gramo
 * 
 * @date Fecha estelar 20160309
 */

#include <sstream>

#include "Droide.h"

using std::string;

int Droide::_numDroides = 0;

Droide::Droide ( ): Droide ( "", "" ) {
}

Droide::Droide ( string marca, string modelo ): _marca (marca), _modelo (modelo)
{
   _numDroides++;
   _idD = _numDroides;
}

Droide::Droide ( const Droide& orig ): Droide(orig._marca, orig._modelo) {
}

Droide::~Droide ( ) {
}

int Droide::getIdD ( ) const
{
   return _idD;
}

Droide& Droide::setModelo ( string modelo )
{
   this->_modelo = modelo;
   return *this;
}

string Droide::getModelo ( ) const
{
   return _modelo;
}

Droide& Droide::setMarca ( string marca )
{
   this->_marca = marca;
   return *this;
}

string Droide::getMarca ( ) const
{
   return _marca;
}

string Droide::toCSV () const
{
   std::stringstream aux;

   aux << _marca << " ; "
       << _modelo;

   return  aux.str ();
}

Droide& Droide::operator = ( const Droide& otro )
{
   if ( this != &otro )
   {
      _marca = otro._marca;
      _modelo = otro._modelo;
   }
   
   return *this ;
}

void Droide::fromCSV ( string& datos )
{
   std::stringstream aux;

   aux << datos;

   getline ( aux, this->_marca, ';' );
   getline ( aux, this->_modelo, ';' );
}