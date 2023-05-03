//
// Created by stefan on 02/05/2023.
//

#ifndef PRUEBA_EMPTYCONTAINER_H
#define PRUEBA_EMPTYCONTAINER_H

#include "stdexcept"

class EmptyContainer: public std::domain_error{
public:
    EmptyContainer(std::string error);
    EmptyContainer(const EmptyContainer &original);
    virtual ~EmptyContainer() noexcept;
};

#endif //PRUEBA_EMPTYCONTAINER_H
