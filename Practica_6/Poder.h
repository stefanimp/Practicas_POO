//
// Created by stefan on 10/04/2023.
//

#ifndef PRUEBA_PODER_H
#define PRUEBA_PODER_H

#include <string>s
#include <sstream>

class Poder{
protected:
    std::string nombre = "";
    std::string descripcion = "";
    std::string afecta_a = "";
    float capacidad_destructiva = 0;
public:
    //Constructores y destructores
    Poder() = default;
    Poder(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva);
    Poder(const Poder &original);
    ~Poder();
    //Setters
    void setNombre(std::string nombre);
    void setDescripcion(std::string descripcion);
    void setAfecta(std::string afecta_a);
    void setCapacidadDestructiva(float capaciadad_destructiva);
    //Getters
    std::string getNombre() const;
    std::string getDescripcion() const;
    std::string getAfectaA() const;
    float getCapacidadDestructiva() const;
    //Operadores
    Poder& operator=(const Poder &original);
    //Otros métodos
    std::string toCSV() const;
};

#endif //PRUEBA_PODER_H
