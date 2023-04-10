/**
 * @file Mutante.h
 * @author algarcia
 *
 * @date 6 de abril de 2016, 19:52
 */

#ifndef MUTANTE_H
#define MUTANTE_H
#include "Poder.h"
#include "PoderPsiquico.h"
#include "PoderFisico.h"

#include <string>

using std::string;

/**
 * @brief Clase Muntante
 */
class Mutante {
public:
    static const int MAX_PODERES = 10; ///< Max. moderes de un mutante

public:
    Mutante() = default;
    Mutante(string nombre, string apodo, int fechaN,string nacionalidad);
    Mutante(const Mutante& orig);
    virtual ~Mutante();
    void setNombreReal(string nombreReal);
    string getNombreReal() const;
    void setNacionalidad(string nacionalidad);
    string getNacionalidad() const;
    void setFechaDeNacimiento(int fechaDeNacimiento);
    int getFechaDeNacimiento() const;
    void setApodo(string apodo);
    string getApodo() const;

    string toCSV() const;

    Mutante& operator=(const Mutante& orig);

    //Metodos ejercicio 2
    void addPoder(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva);
    void desplazarPoderesIzquierda(int posicion);
    void borrarPoder(int cual);
    float capacidadDestructivaTotal() const;
    //Metodos ejercicio 3
    void addPoderPsiquico(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva);
    void addPoderFisico(std::string nombre, std::string descripcion, std::string afecta_a, float capacidad_destructiva);
    //Métodos ejercicio 4
    void addPoder(const Poder &poder);
    void addPoder(const PoderFisico &poderFisico);
    void addPoder(const PoderPsiquico &poderPsiquico);
    //Metodos ejercicio 5
    int getNumPoderes() const;
    string mostrarPoder(int posicion) const;
private:
    string _nombreReal = "---";
    string _apodo = "---";
    int _fechaDeNacimiento = 0;
    string _nacionalidad = "---";
    int num_poderes = 0;
    Poder **poderes = nullptr;
};

#endif /* MUTANTE_H */

