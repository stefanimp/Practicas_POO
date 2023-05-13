/**
 * @file Dispositivo.h
 * @author ujapoo
 */
#ifndef CLOUDPOO_DISPOSITIVO_H
#define CLOUDPOO_DISPOSITIVO_H


#include <string>
#include <stdexcept>
#include <sstream>

class Dispositivo {
private:
    std::string descripcion;
    float consumo;
    bool activo = false;
public:
    Dispositivo(const std::string &descripcion, float consumo);
    Dispositivo(const Dispositivo& orig) = default;
    virtual ~Dispositivo() = default;

    virtual std::string getDescripcion() const = 0;
    virtual float getConsumo() const;
    bool isActivo() const;
    Dispositivo& operator= (const Dispositivo &original);

    void conmutaEstado();

};


#endif //CLOUDPOO_DISPOSITIVO_H
