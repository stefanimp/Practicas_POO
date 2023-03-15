//
// Created by stefan on 18/02/2023.
//

#include "vehiculo.h"

#include <iostream>



/**
 * @brief   Define un vehiculo
 * @details el vehiculo es pasado por referencia hace uso de funciones auxiliares para cumplir los criterios de cada atributo
 * @param[in]vehiculo   struct de tipo vehiculo que queremos definir
 * @param[out]vehiculo  el vehiculo ya definido
 * */
void vehiculo::leePorTeclado(Vehiculo &vehiculo){
    std::string cadena = "";
    float valor;
    std::cout <<"Introduzca la marca del vehiculo: ";
    std::cin>>cadena;
    if(cadena.length() > vehiculo::MAX_CAR_MARCA){
        throw std::string ("[leePorTeclado[leeString]]: la cadena introducida es mayor de lo permitido");
    }
    if(cadena.length() < vehiculo::MIN_CAR_MARCA){
        throw std::string ("[leePorTeclado[leeString]]: la cadena introducida es menor de lo permitido");
    }
    vehiculo.marca = cadena;
    cadena = "";
    std::cout <<"Introduzca el modelo del vehiculo: ";
    std::cin >>cadena;
    if(cadena.length() > vehiculo::MAX_CAR_MODELO){
        throw std::string ("[leePorTeclado[leeString]]: la cadena introducida es mayor de lo permitido");
    }
    if(cadena.length() < vehiculo::MIN_CAR_MODELO){
        throw std::string ("[leePorTeclado[leeString]]: la cadena introducida es menor de lo permitido");
    }
    vehiculo.modelo = cadena;
    cadena = "";
    std::cout <<"Introduzca la matricula del vehiculo: ";
    std::cin>>cadena;
    if(cadena.length() != vehiculo::CAR_MATRICULA){
        throw std::string ("[leePorTeclado]: la cadena introducida no es de 6 caracteres");
    }
    vehiculo.matricula = cadena;
    cadena = "";
    std::cout <<"Introduzca el agno de fabricacion del vehiculo: ";
    std::cin>> vehiculo.agno_fabricacion;
    std::cout <<"Introduzca el precio del vehiculo: ";
    std::cin>>valor;
    if(valor < 0){
        throw std::string ("[leePorTeclado]: el precio introducido no puede ser menor a 0");
    }
    vehiculo.precio = valor;
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
void vehiculo::leePorTeclado(Vehiculo *vehiculo){
    leePorTeclado(*(vehiculo));
}

/**
 * @brief   muestra en pantalla los campos de vehiculo
 * @details el vehiculo es pasado por referenia y definido como contante. Muestra todos los campos de un struc de tipo vehiculo
 *@param[in]vehiculo    vehicullo que queremos mostrar en pantalla
 * */
void vehiculo::muestraEnPantalla(const Vehiculo &vehiculo){
    std::cout <<"Marca: " <<vehiculo.marca <<"  Modelo: " <<vehiculo.modelo <<"  Matricula: " <<vehiculo.matricula <<" Agno de fabricacion: " <<vehiculo.agno_fabricacion <<" Precio: " << vehiculo.precio <<std::endl;
}

/*
 * Al igual que en la función leePorTeclado de tipo puntero, en esta volvemos a llamar a la función de paso por referencia para así tener un codigo más limpio
 * */
/**
 * @brief   muestra en pantalla los campus de vehiculo
 * @details  función dedicada para cuando pasamos el objeto como puntero. Llama a la fuciónn muestraEnPantalla pasandolo por referencia
 * @param[in]vehiculo   vehiculo que queremos mostrar en pantalla
 * */
void vehiculo::muestraEnPantalla(const Vehiculo *vehiculo){
    muestraEnPantalla(*(vehiculo));
}

/**
 * @brief   Pide el tamaño para un verco en funcion de un tamaño máximo
 * @details pide al usuariao un tamaño apra un vector a partir de un tamaño máximo y un tamaó minimo que siemore es el mismo(0)
 * @param[in]tam_max    tamaño máximo que puede tener el vector
 * @return  tamañlo que tendrá el vector
 * */
int vehiculo::tamVec(const int tam_max){
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
void vehiculo::rellenarVector(Vehiculo  vehiculos[], const int tam_v){
    if(tam_v < 0){
        throw std::string("[rellenarVector]: el tamagno del vector no puede ser menor que 0");
    }
    for(int i = 0; i < tam_v; ++i){
        leePorTeclado(vehiculos[i]);
    }
}

/**
 * @brief   muestra los elementos de un vector de struct de tipo vehiculo
 * @param[in]vehiculos  el vector de vehiculos
 * @param[in]tam_v  tamaño que tienne el vector de vehiculos
 * */
void vehiculo::muestraEnPantalla(const Vehiculo vehiculos[], const int tam_v){
    bool decision = true;
    for(int i = 0; i < tam_v && decision; ++i){
        if(decision) {
            muestraEnPantalla(vehiculos[i]);
        }
        if(i%5 == 0){
            decision = false;
            char decision_char;
            std::cout<<"Pulse c para continuar viendo los datos de los vehiculos: ";
            std::cin >>decision_char;
            if(decision_char == 'c'){
                decision = true;
            }
        }
    }
}

/**
 * @brief   comprueba si la matricula dada conicide con el vehiculo dado
 * @param[in]vehiculo   vehiculo que con el que se comprobará la matricula
 * @param[in]matricula  matricula que se busca
 * @return verdadero si ese vehiculo tiene la matricula  buscada, falso si no
 * */
bool vehiculo::coincideMatricula(const Vehiculo vehiculo, const std::string matricula){
    return (vehiculo.matricula == matricula)? true:false;
}

/**
 * @brief   Busca entre un vector de vehiculos una matricula
 * @param[in]vehiculos  vector de vehiculos
 * @param[in]tam_v  tamaño del vector de vehiculos
 * @param[in]matricula  matricula buscada
 * @return puntero al vehiculo con la matricual buscada
 * */
vehiculo::Vehiculo* vehiculo::buscaMatricula(Vehiculo vehiculos[], const int tam_v, const std::string matricula){       // NO ponemos el vector vehiculos como constante ya que esto es un error sitáctico
    for(int i = 0; i < tam_v; ++i){
        if(coincideMatricula(vehiculos[i], matricula)){
            return &vehiculos[i];
        }
    }
    return nullptr;
}

/**
 * @brief   Incrementa el precio un % de un vehiculo
 * @details se realiza mendiante paso por referencia
 * @param[in]vehiculo   vehiculo a incrementar el precio
 * @param[in]porcentaje porcetaja a incrementar
 * @param[out]vehiculo  vehiculo con el precio ya incrementado
 * */
void vehiculo::incrementaPrecio(Vehiculo &vehiculo, const float porcentaje){
    if(porcentaje < 0){
        throw std::string ("[incrementaPrecio]El porcentae introducido es negativo");
    }
    vehiculo.precio +=  (porcentaje/100)*(vehiculo.precio);
}

/**
 * @brief   Incrementa el precio un % de un vehiculo
 * @details se realiza mediante punteros
 * @param[in]vehiculo   vehiculo a incrementar el precio
 * @param[in]porcentaje porcetaja a incrementar
 * @param[out]vehiculo  vehiculo con el precio ya incrementado
 * */
void vehiculo::incrementaPrecio(Vehiculo *vehiculo, const float porcentaje){
    incrementaPrecio(*(vehiculo), porcentaje);
}

/**
 * @brief   busca el vehiculo con el mayor precio
 * @param[in]vehiculos  vector de vehiculos
 * @param[in]tam_V  tamaño del vector de vehiculos
 * @return  posición en el vector del vehiculo de mayor precio
 * */
int vehiculo::maxPrecio(const Vehiculo vehiculos[], const int tam_V){
    float max_precio = vehiculos[0].precio;
    int pos = 0;
    for(int i = 0; i < tam_V; ++i){
        if(vehiculos[i].precio > max_precio){
            max_precio = vehiculos[i].precio;
            pos = i;
        }
    }
    return pos;
}

/**
 * @brief   busca un vehiculo dada una matricula
 * @details el vehiculo se busca entre en un vector de vehiculos
 * @param[in]vechiculos vector con los vehiculos
 * @param[in]tam_v  tamaño del vector de vehiculos
 * @param[in]matricula  matricula  que queremso buscar entre los vehiculos
 * @return posicion en el vector del vehiculo con dicha matricula
 * */
int vehiculo::buscarPorMatricula(const Vehiculo vechiculos[], const int tam_v, const std::string matricula){
    for(int i = 0; i < tam_v; ++i){
        if(coincideMatricula(vechiculos[i], matricula)){
            return i;
        }
    }
    throw std::string ("[buscarPorMatricula]: no existe ningun vehiculo con esa matricula");
}

