//
// Created by stefan on 21/02/2023.
//

#ifndef PRACTICA_2_TEMAZO_H
#define PRACTICA_2_TEMAZO_H
#include "Fecha.h"

#include <string>

/**
 * @brief   clase de un tema
 * */

class Temazo{
public:
    Temazo();                                                     //CONSTRUCTOR por defecto, como le hemos puesto default no hay que declararlo en el .cpp
    Temazo(std::string titulo, std::string interprete, int duracion, std::string nombreUltimoGarito,const Fecha &fechaUltimoUso);       //COSNTRUCTOR parametrizado
    Temazo(const Fecha &fechaUltimoUso);
    Temazo(const Temazo &orignial);                                         // CONSTRUTOR por copia
    ~Temazo();                                                              //DESTRUCTOR
    //SETTERS
    void setTitulo(std::string titulo);
    void setInterprete(std::string interprete);
    void setDuracion(int duracion);
    void setNombreUltimoGarito(std::string nombreUltimoGarito);
    void setFechaUltimoUso(const Fecha &fechaUltimoUso);
    //GETTERS
    std::string getTitulo() const;
    std::string getInterprete() const;
    int getDuracion() const;
    int getPuntuacion() const;
    std::string getNombreUltimoGarito() const;
    const Fecha &getFechaUltimoUso() const;             //Tenemos que poner también el const antes ya que estamos pasando por referencia el objeto de tipo fecha


private:
    // Recordamos que hay que inicializar todos los atributos, así el constructor por defecto utilizará estos para crear el objeto y darle valores a los atributos
    std::string titulo = "";
    std::string interprete = "";
    std::string nombreUltimoGarito = "";
    Fecha fechaUltimoUso;
    // Duración en segundos
    int duracion = 0;
    // Puntuación del publico
    int puntuacion = 0;
};

#endif //PRACTICA_2_TEMAZO_H

