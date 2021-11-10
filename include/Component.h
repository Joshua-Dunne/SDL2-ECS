#ifndef COMP_H
#define COMP_H
#include <iostream>

class Component
{
    Component() = delete;
    Component(int t_id) {id = t_id;}
    int id;
};

#endif