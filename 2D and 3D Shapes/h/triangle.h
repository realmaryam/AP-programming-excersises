#ifndef _TRIANGLE_H_
#define _TRIANGLE_H_

#include <iostream>
#include "2Dshape.h"

class Triangle : public _2Dshape
{
public:
    Triangle(double b, double s);
    void disp() override;
    double perimeter() override;
    double area() override;
    friend class Pyramid;
    
private:
    double side;
    double base;
};

#endif
