//
// Created by stefan on 13/03/2023.
//


#include <sstream>
#include "StarFighter.h"

using std::string;

int StarFighter::_numStarFighters = 0;

StarFighter::StarFighter ( ): StarFighter ( "", "" )
{ }

StarFighter::StarFighter ( string marca, string modelo ): _marca (marca),
                                                          _modelo(modelo),
                                                          libre(true)
{
    _idSF = _numStarFighters + 1000;
    _numStarFighters++;
}

StarFighter::StarFighter ( const StarFighter& orig ): _marca(orig._marca),
                                                      _modelo(orig._modelo),
                                                      _numPlazas(orig._numPlazas),
                                                      libre(orig.libre)
                                                      //piloto(orig.piloto)
{
    _idSF = _numStarFighters + 1000;
    _numStarFighters++;
}

StarFighter::~StarFighter ( ){
    //piloto = nullptr;
}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción    //HECHO
 *       correspondiente. El número de plazas no puede ser <= 0
 */
StarFighter& StarFighter::setNumPlazas ( int numPlazas ){
    if(numPlazas <= 0){
        throw std::invalid_argument("El numero de plazas no puede ser <= 0");
    }
    this->_numPlazas = numPlazas;
    return (*this);
}

int StarFighter::getNumPlazas ( ) const
{
    return _numPlazas;
}

StarFighter& StarFighter::setModelo ( string modelo ){
    this->_modelo = modelo;
    return (*this);
}

string StarFighter::getModelo ( ) const
{
    return _modelo;
}

StarFighter& StarFighter::setMarca ( string marca ){
    this->_marca = marca;
    return (*this);
}

string StarFighter::getMarca ( ) const
{
    return _marca;
}

int StarFighter::getIdSF ( ) const
{
    return _idSF;
}

/*
StarFighter& StarFighter::setPiloto(Piloto *piloto) {
    if(piloto == nullptr){
        throw std::invalid_argument("StarFighter::setPiloto: el puntero al piloto no apunta a nada");
    }
    this->piloto = piloto;
    return (*this);
}
*/

/*
Piloto& StarFighter::getPiloto() const {
    if(piloto == nullptr){
        throw std::runtime_error("StarFighter::getPiloto: no hay piloto asociado");
    }
    return *piloto;
}
*/

float StarFighter::getParsecs() const {
    return parsecs;
}

void StarFighter::incrementarParsecs(float incremento) {
    if(incremento < 0){
        throw std::invalid_argument("StarFigher:: incrementarParsecs: solo se pueden pasar valores positivos como parametro");
    }
    parsecs += incremento;
}

void StarFighter::setLibre(bool libre) {
    this->libre = libre;
}

bool StarFighter::getLibre() const {
    return libre;
}

string StarFighter::toCSV () const
{
    std::stringstream aux;

    aux << _marca << " ; "
        << _modelo << " ; "
        << _numPlazas <<" ; "
        //<<piloto->getIdP() <<" ; "
        <<parsecs;

    return ( aux.str () );
}

StarFighter& StarFighter::operator = (const StarFighter& otro)
{
    if ( this != &otro )
    {
        _marca = otro._marca;
        _modelo = otro._modelo;
        _numPlazas = otro._numPlazas;
        //piloto = otro.piloto;
        parsecs = otro.parsecs;
    }

    return ( *this );
}