//
// Created by stefan on 26/03/2023.
//

#ifndef EXAMEN_PARCIAL_1_CLIENTE_H
#define EXAMEN_PARCIAL_1_CLIENTE_H

#include <string>

/**
 * @brief   Clase de un cliente
 * */
class Cliente{
private:
    std::string nombre = "";
    std::string direccion = "";
public:
    //Constructores y destructor
    Cliente() = default;
    Cliente(std::string nombre, std::string direccion);
    ~Cliente();
    //Setters
    void setNombre(std::string nombre);
    void setDireccion(std::string direccion);
    //Getters
    std::string getNombre() const;
    std::string getDireccion() const;
};

#endif //EXAMEN_PARCIAL_1_CLIENTE_H
