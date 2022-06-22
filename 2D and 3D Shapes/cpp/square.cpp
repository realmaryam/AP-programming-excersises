#include "square.h"

Square::Square(double s)
    : _2Dshape { "square" , 4 }
    , side{ s }
{
}

void Square::disp()
{
    size_t s { static_cast<size_t>(side)};
    for(size_t i{}; i< s; i++)
        std::cout<<"* ";
    std::cout<<std::endl;
    for(size_t i{}; i< s-2; i++)
    {
        std::cout<<"* ";
        for(size_t j{}; j< s-2 ; j++)
            std::cout<<"  ";
        std::cout<<"* "<<std::endl;
    }
    for(size_t i{}; i< s; i++)
        std::cout<<"* ";
    std::cout<<std::endl;
}

double Square::perimeter()
{
    return 4 * side;
}

double Square::area()
{
    return side * side;
}