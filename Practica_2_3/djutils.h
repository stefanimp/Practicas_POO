//
// Created by stefan on 23/02/2023.
//

#ifndef PRACTICA_2_DJUTILS_H
#define PRACTICA_2_DJUTILS_H

#include "Temazo.h"
#include "Garito.h"
#include "Fecha.h"

#include <string>
#include <iostream>

std::string introducirString(const std::string mensaje);

void mostrarDatosTemazo(const Temazo &temazo);

void mostrarDatosGarito(const Garito &garito);

void mostrarDatosFechas(const Fecha &fecha);

void definirGarito(Garito &garito);


#endif //PRACTICA_2_DJUTILS_H
