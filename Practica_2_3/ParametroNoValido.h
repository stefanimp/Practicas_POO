//
// Created by stefan on 22/02/2023.
//

#ifndef PRACTICA_2_PARAMETRONOVALIDO_H
#define PRACTICA_2_PARAMETRONOVALIDO_H

#include <string>

/**
 * @brief   Clase de un parametro no valido
 * */

class ParametroNoValido{
public:
    ParametroNoValido() = default;
    ParametroNoValido(std::string origen, std::string descripcion);
    ~ParametroNoValido();
    //NO ES NECESARIO COLOCAR GETTERS NI SETTERS
    std::string queOcurre() const;
private:
    std::string origen = "";
    std::string descripcion = "";
};

#endif //PRACTICA_2_PARAMETRONOVALIDO_H
