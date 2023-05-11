//
// Created by stefan on 08/05/2023.
//

#ifndef PRACTICA_9_EMPTYCONTAINER_H
#define PRACTICA_9_EMPTYCONTAINER_H

#include <stdexcept>

/**@brief Excepción para indicar intentos de extracción sobre un contenedor  vacío*/
class EmptyContainer: public std::domain_error {
public:
    EmptyContainer(std::string error);
    EmptyContainer(const EmptyContainer& orig);
    virtual ~EmptyContainer() noexcept;
private:

};

#endif //PRACTICA_9_EMPTYCONTAINER_H
