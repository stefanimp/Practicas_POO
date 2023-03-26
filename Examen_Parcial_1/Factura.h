//
// Created by stefan on 26/03/2023.
//

#ifndef EXAMEN_PARCIAL_1_FACTURA_H
#define EXAMEN_PARCIAL_1_FACTURA_H

#include <string>

#include "Cliente.h"
#include "Articulo.h"

const int MIN_ARTICULOS = 0;
const int MAX_ARTICULOS = 5;

/**
 * @brief   Clase de una factura
 * */
class Factura{
private:
    static int cant_facturas;           //Cantidad de facturas emitidas
    int numero;                         //Numero identificador de las facturas
    int fecha = 000101;                 //Fecha de emisión de la factura por defecto(2000/01/01) esta siempre debe ser mayor a esta
    Cliente *cliente = nullptr;
    Articulo **articulos = nullptr;     //Máximo 5 artículos y mínimo 0
public:
    //Cosntructores y destructores
    Factura();
    Factura(int fecha);
    Factura(const Factura &original);
    ~Factura();
    //Setters
    void setFecha(int fecha);
    void setCliente(const Cliente &cliente);
    //Getters
    int getFecha() const;
    int getNumfactura() const;
    Cliente& getCliente() const;
    //Otros métodos
    void agnadirArticulos(std::string nombre, float importe);
    void consultarArticulo(int posicion);
    float importe() const;

};

#endif //EXAMEN_PARCIAL_1_FACTURA_H
