//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_BLOQUE_H
#define PRACTICA_9_BLOQUE_H

#include "ItemApilable.h"

/**@Brief Clase base para bloques de construcción*/
class Bloque: public ItemApilable {
public:
    Bloque();
    Bloque(int cuantos);
    Bloque(const Bloque& orig);
    virtual ~Bloque();
    virtual std::string getDescripcion() override;
private:


};

#endif //PRACTICA_9_BLOQUE_H
