//
// Created by stefan on 18/02/2023.
//

#ifndef PRACTICAS_VEHICULO_H
#define PRACTICAS_VEHICULO_H

#include <string>

namespace vehiculo {
    const int MAX_CAR_MARCA = 20;
    const int MIN_CAR_MARCA = 3;
    const int MAX_CAR_MODELO = 30;
    const int MIN_CAR_MODELO = 1;
    const int CAR_MATRICULA = 6;
    const int MAX_VEHICULOS = 20;
    const int TAM_MIN_VEC = 0;

/**
 * @brief   Estructura de un vehiculo
 * */
    struct Vehiculo {
        std::string marca, modelo, matricula;
        int agno_fabricacion;
        float precio;
    };


    void leePorTeclado(Vehiculo &vehiculo);

    void leePorTeclado(Vehiculo *vehiculo);

    void muestraEnPantalla(const Vehiculo &vehiculo);

    void muestraEnPantalla(const Vehiculo *vehiculo);

    int tamVec(const int tam_max);

    void rellenarVector(Vehiculo vehiculos[], const int tam_v);

    void muestraEnPantalla(const Vehiculo vehiculos[], const int tam_v);

    bool coincideMatricula(const Vehiculo vehiculo, const std::string matricula);

    Vehiculo *buscaMatricula(Vehiculo vehiculos[], const int tam_v, const std::string matricula);

    void incrementaPrecio(Vehiculo &vehiculo, const float porcentaje);

    void incrementaPrecio(Vehiculo *vehiculo, const float porcentaje);

    int maxPrecio(const Vehiculo vehiculos[], const int tam_V);

    int buscarPorMatricula(const Vehiculo vechiculos[], const int tam_v, const std::string matricula);
};


#endif //PRACTICAS_VEHICULO_H
