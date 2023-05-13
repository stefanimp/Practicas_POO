//
// Created by stefan on 13/05/2023.
//

#ifndef CLOUDPOO_V2_RACKALMACENAMIENTO_H
#define CLOUDPOO_V2_RACKALMACENAMIENTO_H

#include "Dispositivo.h"

class RackAlamacenamiento: public Dispositivo{
private:
    int capacidadTotal = 0; //Medido en terabytes
public:
    //Constructores y destructores
    RackAlamacenamiento(std::string descripcion, float consumoTotal, int capacidadTotal);
    ~RackAlamacenamiento();
    //Getters y setters
    void setCapacidadTotal(int capacidadTotal);
    int getCapacidadTotal() const;
    virtual std::string getDescripcion() const override;

};

#endif //CLOUDPOO_V2_RACKALMACENAMIENTO_H
