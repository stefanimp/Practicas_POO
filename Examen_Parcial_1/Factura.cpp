//
// Created by stefan on 27/03/2023.
//
#include "Factura.h"

int Factura::cant_facturas = 0;         //Debemos inicializar el numero de facturas aquí(.cpp) y no en el .h ya que si l hacemos en el .h cada vez que se cree unu objeto del tipo factura el atributo volvería a ser 0


/**
 * @brief   Constructor por defecto de la clase Factura
 * @post    Se crea un objeto del tipo Factura con los valores por defecto
 * */
Factura::Factura():fecha(000101){
    ++cant_facturas;
    numero = cant_facturas;
    cliente = nullptr;
    num_articulos = 0;
    articulos = nullptr;
}

/**
 * @brief   Constructor parametrizado de la clase Factura
 * @param fecha Fecha de emisión de la factura
 * @post    Se crea un objeto de la clase Factura con los parámetros dados
 * */
Factura::Factura(int fecha):fecha(fecha){
    ++cant_facturas;
    numero = cant_facturas;
    cliente = nullptr;
    num_articulos = 0;
    articulos = nullptr;
}

/**
 * @brief   Constructor por copia de la clase Factura
 * @details Interpretamos que al realizar una copia de una factura no se deben aumentar el numero de facturas emitidas ni cambiar el ID de la nueva factura sobre la que se copiarán los datos, ya que un posible uso del constructor por copia de factura es dar una copia de la factura al cliente por lo que los datos deben ser los mismo, aunque los articulo no deben apuntar al mismo sitios para evitar que el cliente pueda modificarlos
 * @param original  Factura desde la que se copiarán los datos
 * @post    Se crea un objeto con los datos del orginal
 * */
Factura::Factura(const Factura &original):
numero(original.numero),
fecha(original.fecha),
cliente(original.cliente),
num_articulos(original.num_articulos){
    if(original.num_articulos == 0){
        articulos = nullptr;
    } else{
        Articulo **copia = new Articulo * [original.num_articulos];
        for (int i = 0; i < original.num_articulos; ++i) {
            copia[i] = new Articulo(*original.articulos[i]);
        }
        articulos = copia;
    }
}

/**
 * @brief   Destructor de la clase Factura
 * @post    Se destruye el objeto, se rompen los vínculos establecidos y se eliminan los artículos de los cuales se compone
 * */
Factura::~Factura() {
    cliente = nullptr;
    for (int i = 0; i < num_articulos; ++i) {
        delete articulos[i];
        articulos[i] = nullptr;
    }

    delete[] articulos;
    articulos = nullptr;
}

void Factura::setFecha(int fecha) {
    if(fecha <= 000101){
        throw std::invalid_argument("Factura::setFecha: la fecha que se quiere asignar no es valida");
    }
    this->fecha = fecha;
}

void Factura::setCliente(Cliente *cliente) {
    if(cliente->getNombre() == "" || cliente->getDireccion() == ""){
        throw std::invalid_argument("Factura::setCliente: los atributos del cliente no pueden estar vacios");
    }
    this->cliente = cliente;
}

int Factura::getFecha() const {
    return fecha;
}

int Factura::getNumfactura() const {
    return numero;
}

Cliente &Factura::getCliente() const {
    return *cliente;
}

void Factura::agnadirArticulos(std::string nombre, float importe) {
    if(num_articulos == MAX_ARTICULOS){
        throw std::out_of_range("Factura::agnadirArticulos: se ha alcanzado el maximo de articulos que puede agnadir a una factura");
    }
    Articulo **nuevo = new Articulo * [++num_articulos];
    for (int i = 0; i < num_articulos - 1; ++i) {
        nuevo[i] = articulos[i];
        articulos[i] = nullptr;
    }
    nuevo[num_articulos-1] = new Articulo(nombre, importe);

    delete[] articulos;
    articulos = nuevo;
}

void Factura::consultarArticulo(int posicion) {
    std::cout<<"El nombre del articulo seleccionado es: " <<articulos[posicion-1]->getNombre() <<std::endl;
    std::cout<<"El importe del articulo seleccionado es: " <<articulos[posicion-1]->getImporte() <<std::endl;
    std::cout<<"El ID del articulo seleccionado es: " <<articulos[posicion-1]->getID() <<std::endl;
}

float Factura::importe() const {
    float importe = 0;
    for (int i = 0; i < num_articulos; ++i) {
        importe+= articulos[i]->getImporte();
    }
    return importe;
}

std::string Factura::getNombreCliente() const {
    return cliente->getNombre();
}