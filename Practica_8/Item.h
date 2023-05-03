/** 
 * @file    Item.h
 * @author  jrbalsas
 * 
 * @date    15 de abril de 2016
 */

#include <string>

#ifndef ITEM_H
#define ITEM_H

class Item {
public:
    virtual std::string getDescripcion() const = 0;
    virtual ~Item() {};
};

#endif /* ITEM_H */

