//
// Created by stefan on 13/05/2023.
//

#ifndef CLOUDPOO_V2_DATACENTEREXCEPTION_H
#define CLOUDPOO_V2_DATACENTEREXCEPTION_H

#include <stdexcept>

class DataCenterExcepcion: public std::out_of_range{
public:
    DataCenterExcepcion(std::string error = "[DataCenter] Potencia superior a la disponible en el DataCenter"): std::out_of_range(error){};
    DataCenterExcepcion(const DataCenterExcepcion &original): std::out_of_range(original){};
    virtual ~DataCenterExcepcion() noexcept override{};
private:
};

#endif //CLOUDPOO_V2_DATACENTEREXCEPTION_H
