#ifndef _SQUARE_H_
#define _SQUARE_H_

#include <iostream>
#include "2Dshape.h"

class Square : public _2Dshape
{
public:
    Square(double s);
    void disp() override;
    double perimeter() override;
    double area() override;

private:
    double side;
};

#endif
