/**
 * @file PoderPsiquico.cpp
 * @author algarcia
 *
 * @date 6 de abril de 2016
 */

#include <sstream>

#include "PoderPsiquico.h"

using std::string;

PoderPsiquico::PoderPsiquico ( string nmb, string dsc, string aA, float cD):
        Poder ( nmb, dsc, aA, cD )
{ }

PoderPsiquico::PoderPsiquico ( string nmb, string dsc, string aA, float cD, float luciddez ):
               Poder ( nmb, dsc, aA, cD ),lucidez(luciddez)
{ }

PoderPsiquico::PoderPsiquico ( const PoderPsiquico& orig ):
               Poder(orig), lucidez(orig.lucidez){ }

PoderPsiquico::~PoderPsiquico ( ){ }

PoderPsiquico& PoderPsiquico::operator= ( const PoderPsiquico& orig )
{
   if ( this != &orig )
   {
      this->Poder::operator= ( orig );
   }
   lucidez = orig.lucidez;
   return  *this;
}

float PoderPsiquico::getLucidez() const {
    return lucidez;
}

float PoderPsiquico::getCapacidadDestructiva() const {
    return (Poder::getCapacidadDestructiva()*lucidez);
}

void PoderPsiquico::setLucidez(float lucidez) {
    if(lucidez < MIN_LUCIDEZ || lucidez > MAX_LUCIDEZ){
        throw std::invalid_argument("PoderPsiquico::setLucide: Valor no valido");
    }
    this->lucidez = lucidez;
}

std::string PoderPsiquico::toCSV() const {
    //Creamos los objetos necesarios, uno de tipo stringstream para poder pasar todos os datos a string y otro de tipo string que será el que devolvamos
    std::stringstream ss;
    std::string cadena_final;
    //Prinnero guaramos la infomación específica de esta clase
    ss<<lucidez <<" ; ";
    //Recuperamos la información de la clase superior a información que ne este caso coincide con la clase base
    ss<<Poder::toCSV();
    //Almacenamos los datos del stringstream en el string normal
    std::getline(ss,cadena_final);

    return cadena_final;
}