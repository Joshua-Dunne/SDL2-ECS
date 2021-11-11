#ifndef COMP_H
#define COMP_H
#include <iostream>

struct Component
{
    Component();
    Component(std::string t_name) {id = t_name;}
    virtual void setName(std::string t_name) = 0;
    std::string id = "empty";
};

#endif