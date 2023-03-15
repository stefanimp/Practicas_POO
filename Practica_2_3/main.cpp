#include <iostream>
#include <string>

#include "Fecha.h"
#include "djutils.h"
#include "Garito.h"
#include "ParametroNoValido.h"
#include "Temazo.h"

const int MAX_TEMAZOS = 20;
const int MAX_P_GARITOS = 10;

/**
 * @brief   Mustra las fechas de la clase temazo que sean anteriores a cierta fecha
 * */
void mostrarTemazosAnteriores(Temazo temazos[],const int tam_temazos, Fecha fecha_limite){
    for(int i = 0; i < tam_temazos; ++i){
        Fecha fecha = temazos[i].getFechaUltimoUso();
        if(fecha < fecha_limite){
            mostrarDatosFechas(temazos[i].getFechaUltimoUso());
        }
    }
}

/**
 * @brief   Muestra las fechas de un vector de punteros que apuntana a temazos y cuyas fechas son anteriores a cierta fecha
 * */
void mostrarTemazosAnteriores(Temazo **temazos, const int tam_temazos, Fecha fecha_limite){
    for (int i = 0; i < tam_temazos; ++i) {
        Fecha fecha = temazos[i]->getFechaUltimoUso();
        if(fecha < fecha_limite){
            mostrarDatosFechas(temazos[i]->getFechaUltimoUso());
        }
    }
}

int main() {
    //PRÁCTICA 3
    //VERSIÓN CON VECTORES DE PUNTEROS Y MEMORIA DINÁMICA
    //  a)
    //Puntero que apunta a un vector de punteros a temazos
    Temazo **p_vtemazos = new Temazo*[MAX_TEMAZOS];
    //IMPORTANTE debemos inicializarlos todoos a nulo para evitar problemas al trabajar con ellos y al destruirlos
    for (int i = 0; i < MAX_TEMAZOS; ++i) {
        p_vtemazos[i] = nullptr;
    }
    int contador_temazos = 0;;
    //  b)
    Garito *pMiCasa = new Garito("Casa Stefan", "Calle Pestaña", 15);
    //  c)
    //Punetero que apunta a un vector de punteros a garitos
    Garito **p_vGaritos = new Garito*[MAX_P_GARITOS];
    //Incializamos los punetros a nulo ya que al crear el vector no sabemos a donde apuntan y esto puede causar problemas
    for (int i = 0; i < MAX_P_GARITOS; ++i) {
        p_vGaritos[i] = nullptr;
    }
    int contador_garitos = 0;

    p_vGaritos[0] = new Garito("Sala Tren","Carretera de Malaga",300);
    ++contador_garitos;
    p_vGaritos[1] = new Garito("Granada 10","Gran Via",400);
    ++contador_garitos;
    //  d)
    p_vtemazos[0] = new Temazo("Animal","Al Safir",88,pMiCasa->getNombre(),Fecha(02,02,2003));
    ++contador_temazos;
    p_vtemazos[1] = new Temazo("A 300","JC Reyes",178,p_vGaritos[0]->getNombre(),Fecha(04,9,1955));
    ++contador_temazos;
    p_vtemazos[2] = new Temazo("Poliester","Pxxr Gvng",180,p_vGaritos[1]->getNombre(),Fecha(20,05,1992));
    ++contador_temazos;
    //  e)
    Fecha fecha_limite(01,01,2016);
    mostrarTemazosAnteriores(p_vtemazos, contador_temazos, fecha_limite);
    //Ejercicio de clase
    Fecha **fechas = new Fecha*[5];
    //Incializamos los punetros a nulo ya que al crear el vector no sabemos a donde apuntan y esto puede causar problemas
    for (int i = 0; i < 5; ++i) {
        fechas[i] = nullptr;
    }
    //Como no hay objetos creados para los 5 punteros a fechas los creamos
    for (int i = 0; i < 5; ++i) {
        fechas[i] = new Fecha();                    //Como usamos el constructor por defecto, los  objetos creados tendrán como atributos la fecha actual de creación del objeto
    }
    //Para asigan 5 fechas a 5 temazos deben existir 5 temazos, pro ahora solo exiten 3 temazos. Definicmos otros dos temazos nuevos
    p_vtemazos[3] = new Temazo("Caile","Luar la L",142,p_vGaritos[0]->getNombre(),Fecha());
    ++contador_temazos;
    p_vtemazos[4] = new Temazo("L3afia","Khaled",125,p_vGaritos[1]->getNombre(),Fecha());
    ++contador_temazos;
    p_vtemazos[5] = new Temazo("Fotos nuestras","JC Reyes & Camin",225,pMiCasa->getNombre(),Fecha());
    ++contador_temazos;

    for(int i = 0; i < 5; ++i){
        p_vtemazos[i]->setFechaUltimoUso(*fechas[i]);
    }

    //IMPORTANTE VACIAMOS LA MEMORIA DiNÁMICA CREADA Y HACEMOS QUE LOS PUNTEROS APUNTEN A NULO
    //Eliminamos de la memoria el vector de punteros a Temazo
    for(int i = 0; i < contador_temazos; ++i){
        if(p_vtemazos[i] != nullptr){       //Con esto decimos que si el puntero apunta a algun sitio, destruyamos esa memoria y hagamos que no apunte a ningún sitio
            std::cout<<"Eliminando memoria" <<std::endl;
            delete p_vtemazos[i];
            p_vtemazos[i] = nullptr;
        }
    }
    delete[] p_vtemazos;
    p_vtemazos = nullptr;

    //Eliminamos de la memoria el objeto al que apuntaba el puntero y hacemos que este no apunte a ningún sitio
    delete pMiCasa;
    pMiCasa = nullptr;

    //Eliminamos de la meoria el vector de punteros a Garito
    for (int i = 0; i < contador_garitos; ++i) {
        if(p_vGaritos[i] != nullptr){
            delete p_vGaritos[i];
            p_vGaritos[i] = nullptr;
        }
    }
    delete[] p_vGaritos;
    p_vGaritos = nullptr;

    //Eliminamos de la memroia el vector de punteros a Fecha
    for (int i = 0; i < 5; ++i) {
        if(!fechas[i]){
            delete fechas[i];
            fechas[i] = nullptr;
        }
    }
    delete[] fechas;
    fechas = nullptr;
    //Con todo esto habremos hecho una correcta gestión de la memoria dinámica

    /* VERSIÓN BÁSICA
    //  a)
    //Vector en memoria automática
    Temazo v_temazos[MAX_TEMAZOS];
    //  b)
    //Puntero en memoria dinámica(SIEMPRE o casi siempre que aparezcan punteros trabajaremos con memoria dinámica)
    Garito *pMiCasa = new Garito("Casa Stefan","Calle Pestaña",15);
    //  c)
    //Vector de punteros a Garitos en memoria automática
    //Es IMPORTANTE que cada vez que un puntero cree un nuevo objeto al finalizar el programa liberemos la memoria puntero a puntero
    //IMPORTANTE Si no llevasemos un contador de objetos que hemos creado, a la hora de destruir los objetos tendriamos que preguntar si apuntan a algun objeto o no, es decir if(v_pGaritos[i] != nullptr) v_pGarito = nullptr;
    Garito *v_pGaritos[MAX_P_GARITOS];
    int cant_garitos = 0;
    v_pGaritos[0] = new Garito("Sala tren", "Carretera de Malaga",300);
    ++cant_garitos;
    v_pGaritos[1] = new Garito("Granada 10","Gran via",400);
    ++cant_garitos;
    //  d)
    v_temazos[0].setTitulo("Animal");
    v_temazos[0].setInterprete("Al Safir");
    v_temazos[0].setDuracion(88);
    Fecha fecha_1(02,02,2003);
    v_temazos[0].setFechaUltimoUso(fecha_1);
    v_temazos[0].setNombreUltimoGarito(pMiCasa->getNombre());

    v_temazos[1].setTitulo("A 300");
    v_temazos[1].setInterprete("JC Reyes");
    v_temazos[1].setDuracion(178);
    Fecha fecha_2(04,9,1955);
    v_temazos[1].setFechaUltimoUso(fecha_2);
    v_temazos[1].setNombreUltimoGarito(v_pGaritos[0]->getNombre());

    v_temazos[2].setTitulo("Poliester");
    v_temazos[2].setInterprete("Pxxr gvng");
    v_temazos[2].setDuracion(180);
    Fecha fecha_3(20,05,1992);
    v_temazos[2].setFechaUltimoUso(fecha_3);
    v_temazos[2].setNombreUltimoGarito(v_pGaritos[1]->getNombre());
    //  e)
    Fecha fecha_limite(01,01,2016);
    mostrarTemazosAnteriores(v_temazos, MAX_TEMAZOS, fecha_limite);
    //  Ejercici clase
    Fecha *fechas = new Fecha[5];
    for(int i = 0; i < 5; ++i){
        v_temazos[i].setFechaUltimoUso(fechas[i]);
    }
    //ELIMINAMOS MEMORIA DINÁMICA Y HACEMOS QUE LOS PUNTEROS NO APUNTEN A NINGÚN SITIO
    delete pMiCasa;
    pMiCasa = nullptr;
    for(int i = 0; i < cant_garitos; ++i){
        delete v_pGaritos[i];
        v_pGaritos[i] = nullptr;
    }
    delete[] fechas;
    fechas = nullptr;
    */


    //PRÁCTICA 2
    /*
    //a) Instanciación de las variables
    Temazo tema_1;
    Fecha fecha_6;
    Temazo tema_2("Animal","Al Safir", 88,"Sala Tren",fecha_6);

    Garito garito_1("Sala tren","Carretera de Malaga",1);
    Garito garito_2(garito_1);

    Fecha fecha_1;
    Fecha fecha_2(23,02,2023);

    //b) Visualización de las variables

   /* mostrarDatosTemazo(tema_1);
    mostrarDatosTemazo(tema_2);

    mostrarDatosGarito(garito_1);
    mostrarDatosGarito(garito_2);

    mostrarDatosFechas(fecha_1);
    mostrarDatosFechas(fecha_2);

    // c)  Moficamos los datos de garito_2 mediante la función declarada en djutils y mostramos los datos capturando los posibles errores

    definirGarito(garito_2);

    mostrarDatosGarito(garito_2);

    try {
        garito_1.setNombre("");
    }catch (ParametroNoValido &e){
        std::cerr<<e.queOcurre() <<std::endl;
    }

    try {
        Garito garito_3("Industrial copera", "Soto Asa", 0);
    } catch (ParametroNoValido &e){
        std::cerr<<e.queOcurre() <<std::endl;
    }

    if(garito_1 == garito_2){
        std::cout<<"Son iguales" <<std::endl;
    } else{
        std::cout <<"Nos son iguales" <<std::endl;
    }

    //CREAMOS UN MENÚ DE OPCIONES

    int decision = 0;
    do {
        decision = 0;
        std::cout<<"Pulse 1 para mostrar las fechas" <<std::endl;
        std::cout<<"Pulse 2 para mostrar los temazos" <<std::endl;
        std::cout<<"Pulse 3 para mostrar los garitos"<<std::endl;
        std::cout<<"Pulse 4 para modificar los datos del segundo garito" <<std::endl;
        std::cout<<"Pulse -1 para salir" <<std::endl;

        std::cout<<"Introduzca su decision: ";
        std::cin>>decision;

        if(decision == 1){
            mostrarDatosFechas(fecha_1);
            mostrarDatosFechas(fecha_2);
        }
        if(decision == 2){
            mostrarDatosTemazo(tema_1);
            mostrarDatosTemazo(tema_2);
        }
        if(decision == 3){
            mostrarDatosGarito(garito_1);
            mostrarDatosGarito(garito_2);
        }
        if(decision == 4){
            definirGarito(garito_2);
        }

    } while (decision != -1);
    */
    return 0;
}
