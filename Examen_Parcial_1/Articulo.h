//
// Created by stefan on 26/03/2023.
//

#ifndef EXAMEN_PARCIAL_1_ARTICULO_H
#define EXAMEN_PARCIAL_1_ARTICULO_H

#include <string>

/**
 * @brief   Clase de un articulo
 * */
class Articulo{
private:
    static int num_articulos;
    int id;
    std::string nombre = "";
    float importe = 0;
public:
    //Constructores y destructores
    Articulo();
    Articulo(std::string nombre, float importe);
    Articulo(const Articulo &original);
    ~Articulo();
    //Setters
    void setNombre(std::string nomrbe);
    void setImporte(float importe);
    //Getters
    std::string getNombre() const;
    float getImporte() const;
    int getID() const;
};  

#endif //EXAMEN_PARCIAL_1_ARTICULO_H
