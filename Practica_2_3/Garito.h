//
// Created by stefan on 22/02/2023.
//

#ifndef PRACTICA_2_GARITO_H
#define PRACTICA_2_GARITO_H

#include <string>

/**
 * @brief   Clase de un garito
 * */

const int AFORO_MIN = 1;

class Garito{
public:
    Garito() = default;                                             //CONSTRUCTOR por defect, ocomo le hemos puesto default no hay que declararlo en el .cpp
    Garito(std::string nombre, std::string direccion, int aforo);   //CONSTRUCTOR parametrizado
    Garito(const Garito &original);                                 //CONSTRUCTOR por copia
    ~Garito();                                                      //DESTRUCTOR
    //SETTERS
    void setNombre(std::string nombre);
    void setDireccion(std::string direccion);
    void setAforo(int aforo);
    //GETTERS
    std::string getNombre() const;
    std::string getDireccion() const;
    int getAforo() const;
    //OTROS MÉTODOS
    bool operator ==(const Garito &otro);

private:
    //Inicialiazmos los atributos
    std::string nombre = "Sin nombre";
    std::string direccion = "Desconocida";
    int aforo = 1;
};

#endif //PRACTICA_2_GARITO_H
