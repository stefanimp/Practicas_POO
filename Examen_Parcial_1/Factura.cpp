//
// Created by stefan on 27/03/2023.
//
#include "Factura.h"

int Factura::cant_facturas = 0;         //Debemos inicializar el numero de facturas aquí(.cpp) y no en el .h ya que si l hacemos en el .h cada vez que se cree unu objeto del tipo factura el atributo volvería a ser 0


/**
 * @brief   Constructor por defecto de la clase Factura
 * @details La fecha por defecto será 000101
 * @post    Se crea un objeto del tipo Factura con los valores por defecto
 * */
Factura::Factura():fecha(FECHA_DEFECTO){
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

/**
 * @brief   Modifica el valor del atributo Fecha
 * @param fecha Nuevo valor que tendrá el atributo
 * @post    El valor del atributo queda modificado
 * */
void Factura::setFecha(int fecha) {
    if(fecha <= FECHA_DEFECTO){
        throw std::invalid_argument("Factura::setFecha: la fecha que se quiere asignar no es valida");
    }
    this->fecha = fecha;
}

/**
 * @brief   Asigna un cliente a la factura
 * @param cliente   Cliente que se va a asignar
 * @post    El cliente queda asignado
 * @post    Si el nombre o la dirección del cliente están vacíos se lanza una excepción
 * */
void Factura::setCliente(Cliente *cliente) {
    if(cliente->getNombre() == "" || cliente->getDireccion() == ""){
        throw std::invalid_argument("Factura::setCliente: los atributos del cliente no pueden estar vacios");
    }
    this->cliente = cliente;
}

/**
 * @brief   Devuelve el valor del atributo fecha
 * @post    Devuelve el valor del atributo fecha
 * */
int Factura::getFecha() const {
    return fecha;
}

/**
 * @brief   Devuelve el valor del atributo numero
 * @post    Devuelve el valor del atributo numero
 * */
int Factura::getNumfactura() const {
    return numero;
}

/**
 * @brief   Devuelve el Cliente asociado a la factura
 * @post    Devuelve el cliente asociado a la factura
 * */
Cliente &Factura::getCliente() const {
    return *cliente;
}

/**
 * @brief   Añade un articuo a la factura
 * @details Ya que estamos trabajando con vectores de punteros que apuntan a objetos y solo tendremos tantos punteros como articulos tengamos, es decir, cada vez que añadamos un articulo tendremos que ampliar el tamaño de nuestro vector de punteros, describiré el procedimiento en el codigo
 * @param nombre    Nombre del articulo que se desea añadir
 * @param importe   Importe del articulo que se desea añadir
 * @post    El articulo queda añadido
 * @post    Si se ha alcanzado el numero máximo de artículos permitidos se lanza una excepción
 * */
void Factura::agnadirArticulos(std::string nombre, float importe) {
    if(num_articulos == MAX_ARTICULOS){
        throw std::out_of_range("Factura::agnadirArticulos: se ha alcanzado el maximo de articulos que puede agnadir a una factura");
    }
    //Aumentamos el numero de articulos que tendrá la factura
    //Creamos un nuevo vector de punteros que apuntan a objetos con el nuevo tamaño y le iremos asignando la dirección a la que apuntaba el anterior vector(que tenía menor tamaño y por eso no se puede añadir directamente el objeto)
    //A la vez que asignamos al nuevo vector, colocamos el anterior vector a nullptr
    Articulo **nuevo = new Articulo * [++num_articulos];
    for (int i = 0; i < num_articulos - 1; ++i) {
        nuevo[i] = articulos[i];
        articulos[i] = nullptr;
    }
    //Añadimos el nuevo articulo a la ultima posición del vector
    nuevo[num_articulos-1] = new Articulo(nombre, importe);

    //Eliminamos el contenido del anterior vector y asignamos el atributo articulos al nuevo vector
    delete[] articulos;
    articulos = nuevo;
}

/**
 * @brief   Muestra los datos de un articulo según su posición
 * @param posicion  Posición del articulo del qu se desean consular los datos
 * @post    Se muestran por pantalla los datos del articulo indicado
 * @post    Si la posición es menor a 0 o mayor que la cantidad de artículos que hay en la factura se lanza una excepción
 * */
void Factura::consultarArticulo(int posicion) {
    if(posicion > num_articulos || posicion < MIN_ARTICULOS){
        throw std::invalid_argument("Factura::consultarArticulo: Error, la posición introducida no es valida");
    }
    std::cout<<"El nombre del articulo seleccionado es: " <<articulos[posicion-1]->getNombre() <<std::endl;
    std::cout<<"El importe del articulo seleccionado es: " <<articulos[posicion-1]->getImporte() <<std::endl;
    std::cout<<"El ID del articulo seleccionado es: " <<articulos[posicion-1]->getID() <<std::endl;
}

/**
 * @brief   Devuelve el importe total de los artículos que aparecen en la factura
 * @post    Devuelve el importe total de los artículos que aparecen en la factura
 * */
float Factura::importe() const {
    float importe = 0;
    for (int i = 0; i < num_articulos; ++i) {
        importe+= articulos[i]->getImporte();
    }
    return importe;
}

/**
 * @brief   Devuelve el nombre del cliente
 * @post    Devuelve el nombre del cliente
 * */
std::string Factura::getNombreCliente() const {
    return cliente->getNombre();
}