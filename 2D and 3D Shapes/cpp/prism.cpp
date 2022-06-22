#include "prism.h"

Prism::Prism(double h, _2Dshape* base)
    : _3Dshape {"prism" , h , base}
{
}

double Prism::volume()
{
    return base->area() * height ;
}

double Prism::area()
{
    return base->perimeter() * height + 2 * base->area() ;
}

std::ostream& operator<<(std::ostream& os, const Prism& p)
{
    std::cout<<"base of prism is "<< p.base->getName()<<" and its height is "<< p.height<<".\n";
    return os ;
}

