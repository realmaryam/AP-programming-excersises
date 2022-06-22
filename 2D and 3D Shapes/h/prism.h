#ifndef _PRISM_H_
#define _PRISM_H_

#include <iostream>
#include "3Dshape.h"
#include "square.h"

class Prism : public _3Dshape
{
public:
    Prism(double h, _2Dshape* base);
    double volume() override;
    double area() override;
    friend std::ostream& operator<<(std::ostream& os, const Prism& p);
};

#endif
