//
// Created by stefan on 07/05/2023.
//

#ifndef PRUEBA_CONTENEDOR_H
#define PRUEBA_CONTENEDOR_H

#include <string>
#include <stdexcept>

#include "EmptyContainer.h"

template <typename T>
class Contenedor{
private:
    int _maxObjetos = 27;
    T ** objetos = nullptr;
    int _numObjetos = 0;
public:
    Contenedor() = default;
    Contenedor(int cuantosCaben);
    Contenedor(const Contenedor &orig);
    virtual ~Contenedor();
    int cuantosCaben() const;
    int cuantosHay() const;
    virtual void mete(T *objeto);
    T& consulta(int cual);
    T* saca(int cual);

};

//Definimos los metodos
template<typename T>
Contenedor<T>::Contenedor(int cuantosCaben):_maxObjetos(cuantosCaben){
}

template<typename T>
Contenedor<T>::Contenedor(const Contenedor<T> &orig) {
    this->_maxObjetos = orig._maxObjetos;
    this->_numObjetos = orig._numObjetos;
    this->objetos = orig.objetos;
}

template<typename T>
Contenedor<T>::~Contenedor() {
}

template<typename T>
int Contenedor<T>::cuantosCaben() const{
    return _maxObjetos;
}

template<typename T>
int Contenedor<T>::cuantosHay() const {
    return _numObjetos;
}

template<typename T>
void Contenedor<T>::mete(T *objeto) {
    if(!objeto){
        throw std::invalid_argument ("[Contenedor::mete] Intento de asignar puntero 0");
    }
    if (_numObjetos == _maxObjetos){
        throw std::out_of_range("[Contenedor::mete] No caben más elementos en el Contenedor");
    }
    objetos[_numObjetos++] = objeto;
}

template<typename T>
T &Contenedor<T>::consulta(int cual) {
    if (_numObjetos==0)
        throw EmptyContainer("[Contenedor::consulta] El Contenedor está vacío");
    if (cual<=0 || cual >_numObjetos)
        throw std::out_of_range("[Contenedor::consulta] El elemento indicado no existe");
    return *objetos[cual-1];
}

template<typename T>
T *Contenedor<T>::saca(int cual) {
    if (_numObjetos==0)
        throw EmptyContainer("[Contenedor::saca] El Contenedor está vacío");
    if (cual<=0 || cual >_numObjetos)
        throw std::out_of_range("[Contenedor::mete] El elemento indicado no existe");
    T* elemento = objetos[cual-1];
    _numObjetos--;
    if (_numObjetos>0)
        objetos[cual-1]=objetos[_numObjetos];
    return elemento;
}

#endif //PRUEBA_CONTENEDOR_H
