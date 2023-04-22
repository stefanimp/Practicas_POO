//
// Created by stefan on 21/04/2023.
//

#ifndef PRUEBA_ORDENA_H
#define PRUEBA_ORDENA_H

/**
 * Intercambia dos variables de cualquier tipo
 * @pre el tipo T tiene sobrecargado el operador de asignación
 * */
 template<typename T>
 void intercambia(T &a, T &b){
     T c = a;
     a = b;
     b = c;
 }

/**
 * Ordena un vector de elementos de menor a mayor utilizando el algoritmo de selección
 * @pre Los elementos tienen que tener sobrecargado el operador <
 * */
 template<typename T>
 void ordena(T *valores,const int numValores){
     int posMenor;

    for (int i = 0; i < numValores - 1; ++i) {
        posMenor = i;
        for (int j = i + 1; j < numValores  ; ++j) {
            if(*valores[j] < *valores[posMenor]){
                posMenor = j;
            }
            intercambia(valores[i], valores[posMenor]);
        }
    }
 }

#endif //PRUEBA_ORDENA_H
