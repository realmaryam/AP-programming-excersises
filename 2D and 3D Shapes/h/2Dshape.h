#ifndef _2DSHAPE_H_
#define _2DSHAPE_H_

#include <iostream>
#include <cmath>

class _2Dshape
{
public:
    _2Dshape(const char* name, size_t z)
        : name {name}
        , noOfSides { z }
    {
    }
    virtual double perimeter() = 0;
    virtual double area() = 0;
    virtual void disp() = 0;
    const char* getName() { return name; }
    
private:    
    const char* name; 
    size_t noOfSides;
};

#endif
