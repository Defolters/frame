#ifndef COMPONENT_H
#define COMPONENT_H
#include "Observer.h"

class Frame;

class Component : public Observer
{
public:
    virtual void draw(Frame& frame) = 0;
};

#endif //COMPONENT_H 

