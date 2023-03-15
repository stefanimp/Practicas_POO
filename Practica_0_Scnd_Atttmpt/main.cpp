/**
 * @brief   Practica 0
 * @file    main.cpp
 * @author  Stefan Giovanni Imperato Lozano
 * */
#include <iostream>
#include <string>

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
struct Vehiculo{
    std::string marca, modelo, matricula;
    int agno_fabricacion;
    float precio;
};

/**
 * @brief   Lee y devuelve un cadena cumpliendo que debe tener un tamaño minimpo y maximo
 * @param[in]tam_min   tamaño minimo de la cadena
 * @param[in]tam_max    tamaño mmaximo de la cadena
 * @param[in]mensaje    mensaje que se muestra especificando que se quiere introducir
 * @return cadena    cadena que cumple un tamaño minimo y maximo
 * */
std::string leeString(const int tam_min, const int tam_max, const std::string mensaje){
    std::string cadena;
    do{
        std::cout <<mensaje;
        std::cin>>cadena;
    } while(cadena.length() < tam_min || cadena.length() > tam_max);
    return cadena;
}

/**
 * @brief   Lee de entrada estandar una cadena y la devuelve
 * @param[in]tam    tamaño que debe tener la cadena
 * @param[in]mensaje    mensaje que se muestra espacificando que se quiere introducir
 * @return    cadena que cumple el tamaño especificado
 * */
std::string leeString(const int tam, const std::string mensaje){
    std::string cadena = "";
    do{
        std::cout <<mensaje;
        std::cin>>cadena;
    } while(cadena.length() != tam);
    return cadena;
}

/**
 * @brief   Lee de la entrada estandar un numero float
 * @details el numero debe ser mayor a un minimo establecido
 * @param[in]valor_min  valor que debe sobrepasar el numero
 * @param[in]mensaje    mensaje que se muestra especificando que se quiere introducir
 * @return  valor que cumple ser mayor a valor_min
 * */
float leeNumMinimo(const int valor_min, const std::string mensaje){
    float valor;
    do{
        std::cout <<mensaje;
        std::cin >>valor;
    } while(valor < valor_min);
    return valor;
}

/**
 * @brief   Define un vehiculo
 * @details el vehiculo es pasado por referencia hace uso de funciones auxiliares para cumplir los criterios de cada atributo
 * @param[in]vehiculo   struct de tipo vehiculo que queremos definir
 * @param[out]vehiculo  el vehiculo ya definido
 * */
void leePorTeclado(Vehiculo &vehiculo){
    vehiculo.marca = leeString(MIN_CAR_MARCA, MAX_CAR_MARCA,"Introduzca la marca del vehiculo: ");
    vehiculo.modelo = leeString(MIN_CAR_MODELO, MAX_CAR_MODELO, "Introduzca el modelo del vehiculo: ");
    vehiculo.matricula = leeString(CAR_MATRICULA, "Introduzca la matricula del vehiculo: ");
    std::cout <<"Introduzca el agno de fabricacion del vehiculo: ";
    std::cin>> vehiculo.agno_fabricacion;
    vehiculo.precio = leeNumMinimo(CAR_MATRICULA, "Introduzca el precio del vehiculo: ");
}
/* IMPORTANTE cuando tengamos que sobrecargar funciones por que una se ellas es por paso por refencia y la otra como puntero lo haremos de esta manera para evitar duplicar codigo.
 * Lo que haremos será pasar la dirección de memroia del puntero con el que estamos trabajando a la función 2 ,que no funciona mediante punteros. Entonces los cambios aplicados en la función 2 se apliacarán al puntero de la primera función y por ende,
 * al objeto apuntado.
*/
/**
 * @brief   Define un vehiculo
 * @details esta función es dedicada para cuando el objeto es pasado meidante un puntero. Los mandamos a la función leePorTeclado pasado por referencia.
 * @param[in]vehiculo   struct de tipo vehiculo que queremos definir
 * @param[out]vehiculo  el vehiculo ya definido
 * */
void leePorTeclado(Vehiculo *vehiculo){
    leePorTeclado(*(vehiculo));
}

/**
 * @brief   muestra en pantalla los campos de vehiculo
 * @details el vehiculo es pasado por referenia y definido como contante. Muestra todos los campos de un struc de tipo vehiculo
 *@param[in]vehiculo    vehicullo que queremos mostrar en pantalla
 * */
void muestraEnPantalla(const Vehiculo &vehiculo){
    std::cout <<"Marca: " <<vehiculo.marca  <<std::endl;
    std::cout <<"Modelo: " <<vehiculo.modelo <<std::endl;
    std::cout <<"Matricula: " <<vehiculo.matricula <<std::endl;
    std::cout <<"Agno de fabricacion: " <<vehiculo.agno_fabricacion <<std::endl;
    std::cout <<"Precio: " << vehiculo.precio <<std::endl;
}

/*
 * Al igual que en la función leePorTeclado de tipo puntero, en esta volvemos a llamar a la función de paso por referencia para así tener un codigo más limpio
 * */
/**
 * @brief   muestra en pantalla los campus de vehiculo
 * @details  función dedicada para cuando pasamos el objeto como puntero. Llama a la fuciónn muestraEnPantalla pasandolo por referencia
 * @param[in]vehiculo   vehiculo que queremos mostrar en pantalla
 * */
void muestraEnPantalla(const Vehiculo *vehiculo){
    muestraEnPantalla(*(vehiculo));
}

/**
 * @brief   Pide el tamaño para un verco en funcion de un tamaño máximo
 * @details pide al usuariao un tamaño apra un vector a partir de un tamaño máximo y un tamaó minimo que siemore es el mismo(0)
 * @param[in]tam_max    tamaño máximo que puede tener el vector
 * @return  tamañlo que tendrá el vector
 * */
int tamVec(const int tam_max){
    int tam;
    do{
        std::cout <<"Introduzca el tamagno deseado del vector(max de "<<tam_max <<" ): ";
        std::cin >>tam;
    } while(tam < TAM_MIN_VEC || tam > tam_max);
    return tam;
}

/**
 * @brief   Lee vehiculos para un vector de vehiculos
 * @param[in]tam_v  tamaño que tendrá  el vector
 * @param[in]vehiculos  vector de struct de vehiculos
 * @param[out]vehiculos vector ya definido de vehiculos
 * */
void leePorTecladoVec(Vehiculo  vehiculos[], const int tam_v){
    for(int i = 0; i < tam_v; ++i){
        leePorTeclado(vehiculos[i]);
    }
}

// ASÍ SE HARÍA CON RECURSIVIDAD, EN ESTE CASO; LA RECURSIVIDAD NO ES EFICIENTE YA QUE ES MÄS COSTOSO EL HECHO DE LLAMAR A UNA FUNCUÓN N VECES QUE EJERCUTAR UN BUCLE FOR N VECES
 /*
void leePorTecladoVec(Vehiculo vehiculos[], const int tam_v,const int pos){
    if(pos < tam_v){
        leePorTeclado(vehiculos[pos]);
        leePorTecladoVec(vehiculos, tam_v, pos + 1);
    }
}

/**
 * @brief   Lee vehisulos para un vector de vehiculos
 * @param[in]tam_v  tamaño que tendrá  el vector
 * @param[in]vehiculos  vector de struct de vehiculos
 * @param[out]vehiculos vector ya definido de vehiculos
 * */
 /*
void leePorTecladoVec(Vehiculo vehiculos[], const int tam_v){
    leePorTecladoVec(vehiculos, tam_v, 0);
}
*/


/**
 * @brief   muestra los elementos de un vector de struct de tipo vehiculo
 * @param[in]vehiculos  el vector de vehiculos
 * @param[in]tam_v  tamaño que tienne el vector de vehiculos
 * */
void muestraEnPantallaVec(const Vehiculo vehiculos[], const int tam_v){
    for(int i = 0; i < tam_v; ++i){
        muestraEnPantalla(vehiculos[i]);
    }
}

bool coincideMatricula(const Vehiculo vehiculo, const std::string matricula){
    return (vehiculo.matricula == matricula)? true:false;
}

Vehiculo* buscaMatricula(Vehiculo vehiculos[], const int tam_v, const std::string matricula){       // NO ponemos el vector vehiculos como constante ya que esto es un error sitáctico
    for(int i = 0; i < tam_v; ++i){
        if(coincideMatricula(vehiculos[i], matricula)){
            return &vehiculos[i];
        }
    }
    return nullptr;
}

void incrementaPrecio(Vehiculo &vehiculo, const float porcentaje){
    vehiculo.precio +=  (porcentaje/100)*(vehiculo.precio);
}

void incrementaPrecio(Vehiculo *vehiculo, const float porcentaje){
    incrementaPrecio(*(vehiculo), porcentaje);
}

int main(){

    Vehiculo vehiculo_prueba1;
   // leePorTeclado(vehiculo_prueba1);
   // std::cout <<std::endl <<vehiculo_prueba1.marca;

    Vehiculo *vehiculo_prueba2 = nullptr;       // declaramos el puntero y hacemos que no apunte a ninguna dirección de memoria
    vehiculo_prueba2 = &vehiculo_prueba1;       // hacemos que apunte a la dirección de memoria de vehiculo_prueba1
    vehiculo_prueba1.precio = 100;

    /*
     * Tammbien podríamos haber declaradoe el puntero y a la vez decirle que apunte a la dirección de memoria de vehiculo_prueba1. Esto se haría de la siguiente forma:
     * Vehiculo *vehiculo_prueba2 = &vehiculo_prueba1;
     * */

    /*leePorTeclado(vehiculo_prueba2);
    std::cout <<std::endl <<vehiculo_prueba1.modelo;

    muestraEnPantalla(vehiculo_prueba2);

    std::cout<<std::endl;

    muestraEnPantalla(vehiculo_prueba1);

    Vehiculo vehiculo_prueba3;

    leePorTeclado(vehiculo_prueba3);
     */

    //muestraEnPantalla(vehiculo_prueba3);
    /*
    Vehiculo vehiculos[MAX_VEHICULOS];
    int tam_v_vehiculos = tamVec(MAX_VEHICULOS);
    leePorTecladoVec(vehiculos, tam_v_vehiculos);
    muestraEnPantallaVec(vehiculos, tam_v_vehiculos);
    */

    Vehiculo vehiculo_3;
    vehiculo_3.precio = 100;

    incrementaPrecio(vehiculo_3, 19);
    std::cout<<vehiculo_3.precio;

    incrementaPrecio(vehiculo_prueba2, 19);
    std::cout<< std::endl<<vehiculo_prueba2->precio;

    vehiculo_prueba2 = nullptr;


    return 0;
}