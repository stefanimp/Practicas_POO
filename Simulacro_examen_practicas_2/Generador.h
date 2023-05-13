/**
 * @file Generador.h
 * @author ujapoo
 */

#ifndef CLOUDPOO_GENERADOR_H
#define CLOUDPOO_GENERADOR_H


#include <string>

class Generador {
private:
    std::string modelo;
    float potencia;
public:
    Generador(const std::string &cadena, float potencia);
    Generador(const Generador& orig) = default;
    virtual ~Generador() = default;
    
    const std::string &getModelo() const;

    float getPotencia() const;
};


#endif //CLOUDPOO_GENERADOR_H
