//
// Created by stefan on 18/03/2023.
//

#ifndef PRUEBA_ESCUADRON_H
#define PRUEBA_ESCUADRON_H

#include <string>

#include "Piloto.h"

const int MAX_PILOTOS = 50;

class Escuadron{
private:
    std::string nombre = "";
    int num_pilotos = 0;
    std::string base = "";
    Piloto **integrantes = nullptr;
public:
    //Constructores
    Escuadron() = default;
    Escuadron(std::string nombre, int num_pilotos, std::string base, Piloto **integrantes);
    Escuadron(std::string nombre, std::string base);
    Escuadron(const Escuadron &original);
    ~Escuadron();
    //Setters
    void setNombre(std::string nombre);
    void setBase(std::string base);
    void setIntegrantes(Piloto **integrantes, int num_integrantes);
    //Getters
    std::string getNombre() const;
    int getNumPilotos() const;
    std::string getBase() const;
    Piloto** getIntegrantes() const;
    //Otros métodos
    void agnadirPiloto(Piloto *piloto);
    void agnadirPiloto(std::string nombre);
    float promedioMisiones();
};

#endif //PRUEBA_ESCUADRON_H
