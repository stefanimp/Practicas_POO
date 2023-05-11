//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_ITEM_H
#define PRACTICA_9_ITEM_H

#include <string>
#include <sstream>

/**@brief Interfaz de objetos del juego*/
class Item {
private:
    int prueba = 0;
public:
    virtual std::string getDescripcion() =0;
    virtual ~Item() {};
};

#endif //PRACTICA_9_ITEM_H
