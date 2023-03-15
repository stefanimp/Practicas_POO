//
// Created by stefan on 22/02/2023.
//

#ifndef PRACTICA_2_FECHA_H
#define PRACTICA_2_FECHA_H

#include <string>

/**
 * @brief   Clase de una fecha
 * */

class Fecha{
public:
    Fecha();                                //CONSTRUCTOR por defecto, asigna al objeto la fecha actual
    Fecha(int dia, int mes, int ango);      //CONSTRUCTOR parametrizado
    Fecha(const Fecha &original);           //CONSTRUCTOR por copia
    ~Fecha();                               //DESTRUCTOR
    //SETTERS
    void setDia(int dia);
    void setMes(int mes);
    void setAgno(int ango);
    //GETTERS
    int getDia() const;
    int getMes() const;
    int getAgno() const;
    //OTROS MÉTODOS
    bool operator <(const Fecha &fecha);
    bool operator ==(const Fecha &fecha);
    bool operator <=(const Fecha &fecha);
    bool operator >=(const Fecha &fecha);
    bool operator >(const Fecha &fecha);
    bool operator !=(const Fecha &fecha);
    void operator =(const Fecha &fecha);
private:
    //Incializamos todos los atributos
    int dia = 0;
    int mes = 0;
    int agno = 0;
};

#endif //PRACTICA_2_FECHA_H
