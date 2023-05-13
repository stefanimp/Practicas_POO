//
// Created by stefan on 13/05/2023.
//

#ifndef CLOUDPOO_V2_RACKSERVIDORES_H
#define CLOUDPOO_V2_RACKSERVIDORES_H

#include "Dispositivo.h"

class RackServidores: public Dispositivo{
private:
    int totalServidores = 0;
    int servidoresOperativos = 0;   //No podrá haber más servidores operativos que totalServidores
public:
    //Constructores y destructores
    RackServidores(std::string descripcion, float consumoTotal, int totalServidores);
    ~RackServidores();
    //Getters y setters
    void setToatoalServidores(int totalServidores);
    int getTotalServidores() const;
    void setServidoresOperativo(int servidoresoperativos);
    int getServidoresOperativos() const;
    std::string getDescripcion() const override;
    float getConsumo() const override;
};

#endif //CLOUDPOO_V2_RACKSERVIDORES_H
