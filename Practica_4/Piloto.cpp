//
// Created by stefan on 13/03/2023.
//

#include <stdexcept>
#include <sstream>
#include <string>
#include "Piloto.h"

using std::string;

int Piloto::_numPilotos = 0;

Piloto::Piloto ( ): Piloto ( "" )
{ }

Piloto::Piloto ( string nombre ): _nombre (nombre)
{
    _numPilotos++;
    _idP = _numPilotos;
}

Piloto::Piloto ( const Piloto& orig ): _nombre(orig._nombre),
                                       _nacionalidad(orig._nacionalidad),
                                       _numMisiones(orig._numMisiones),
                                       _fechaUltimaMision(orig._fechaUltimaMision),
                                       _incidenciasUltimaMision(orig._incidenciasUltimaMision),
                                       nave(orig.nave),
                                       auxiliar(orig.auxiliar)
{
    _numPilotos++;
    _idP = _numPilotos;
}

Piloto::~Piloto (){
    nave = nullptr;
    auxiliar = nullptr;
}

/**
 * @todo Aquí hay que añadir la comprobación del parámetro y lanzar la excepción    //HECHO
 *       correspondiente. El número de misiones no puede ser <= 0
 */
Piloto& Piloto::setNumMisiones ( int numMisiones ){
    if(numMisiones <= 0){
        throw std::invalid_argument("El numero de misiones no puede ser <= 0");
    }
    this->_numMisiones = numMisiones;
    return (*this);
}

int Piloto::getNumMisiones ( ) const
{
    return _numMisiones;
}

Piloto& Piloto::setNacionalidad ( string nacionalidad ){
    this->_nacionalidad = nacionalidad;
    return (*this);
}

string Piloto::getNacionalidad ( ) const
{
    return _nacionalidad;
}

Piloto& Piloto::setNombre ( string nombre ){
    this->_nombre = nombre;
    return (*this);
}

string Piloto::getNombre ( ) const
{
    return _nombre;
}

int Piloto::getIdP ( ) const
{
    return _idP;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener incidencias;  //HECHO
 *       haz esta comprobación y lanza la excepción correspondiente
 */
Piloto& Piloto::setIncidenciasUltimaMision ( string incidenciasUltimaMision ){
    if(this->_numMisiones == 0){
        throw std::invalid_argument("El numero de misiones es 0 por lo que no puede haber incidencias");
    }
    this->_incidenciasUltimaMision = incidenciasUltimaMision;
    return (*this);
}

string Piloto::getIncidenciasUltimaMision ( ) const
{
    return _incidenciasUltimaMision;
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de  //HECHO
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
Piloto& Piloto::setFechaUltimaMision ( long fechaUltimaMision ){
    if(this->_numMisiones == 0){
        throw std::invalid_argument("El numero de misiones es 0 por lo que no hay fecha de ultima mision");
    }
    this->_fechaUltimaMision = fechaUltimaMision;
    return (*this);
}

/**
 * @todo Si el número de misiones del piloto es 0, no puede tener fecha de  //HECHO
 *       última misión; haz esta comprobación y lanza la excepción
 *       correspondiente
 */
long Piloto::getFechaUltimaMision ( ) const{
    if(this->_numMisiones == 0){
        throw std::invalid_argument("El numero de misiones es 0por lo que no hay fecha de ultima mision");
    }
    return _fechaUltimaMision;
}

Piloto& Piloto::setNave(StarFighter *nave) {
    if(nave == nullptr){
        throw std::invalid_argument("Piloto::setNave: el puntero a la nave no apunta a nada");
    }
    if(!nave->getLibre()){
        throw std::invalid_argument("Piloto::setNaveLa nave no está libre");
    }
    if(nave->getMarca() == "Incom Corporation" && this->_numMisiones < 50){
        throw std::invalid_argument("Piloto::setNave: el piloto tiene un numero de misiones menor de 50");
    }
    nave->setLibre(false);
    this->nave = nave;
    return (*this);
}

StarFighter& Piloto::getNave() const {
    if(nave == nullptr){
        throw std::runtime_error("Piloto::getNave: no hay nave asociada");
    }
    return *nave;
}

Piloto& Piloto::setAuxiliar(Droide *auxiliar) {
    if(auxiliar == nullptr){
        throw std::invalid_argument("Piloto::setAuxilliar: el puntero al droide es no apunta a nada");
    }
    this->auxiliar = auxiliar;
    return (*this);
}

Droide& Piloto::getAuxiliar() const{
    if(auxiliar == nullptr){
        throw std::runtime_error("Piloto::getAuxiliar: no hay auxiliar asociado");
    }
    return (*this->auxiliar);
}

string Piloto::toCSV () const
{
    std::stringstream aux;

    aux << _nombre << " ; "
        << _nacionalidad << " ; "
        << _numMisiones << " ; "
        << _fechaUltimaMision << " ; "
        << _incidenciasUltimaMision <<" ; "
        <<nave->getIdSF() <<" ; "
        <<auxiliar->getIdD();

    return ( aux.str () );
}

Informe Piloto::generaInforme() const {
    Informe informe;

    informe.setIdPiloto(this->_idP);
    informe.setFechaEstelar(this->_fechaUltimaMision);
    //Creamos la variable ss de tipo stringstream que nos permitirá convertir numeros y otras variables a formato string para as´poder pasar este string al metodo setDatosInforme()
    std::stringstream ss;
    ss <<"Identificardor de la nave: "<< this->nave->getIdSF() <<" ; " <<"Identificador del droide: " << this->auxiliar->getIdD() <<" ; " <<"Incidencias ultima mision: " << this->getIncidenciasUltimaMision();
    informe.setDatosInforme(ss.str());
    return informe;

    // O utilizamos el metodo toCSV directamente?
    /*
    Informe informe;
    std::stringstream ss = this->toCSV() + this->getIncidenciasUltimaMision();
    informe.setDatosInforme(ss.str());
    informe.setFechaEstelar(this->_fechaUltimaMision);
    informe.setIdPiloto(this->_idP);
    return informe;
    */
}

Piloto& Piloto::operator = ( const Piloto& otro )
{
    if ( this != &otro )
    {
        _nombre = otro._nombre;
        _nacionalidad = otro._nacionalidad;
        _numMisiones = otro._numMisiones;
        _fechaUltimaMision = otro._fechaUltimaMision;
        _incidenciasUltimaMision = otro._incidenciasUltimaMision;
        nave = otro.nave;
        auxiliar = otro.auxiliar;
    }

    return ( *this );
}
