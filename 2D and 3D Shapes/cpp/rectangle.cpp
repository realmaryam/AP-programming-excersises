#include "rectangle.h"

Rectangle::Rectangle(double l, double w)
    : _2Dshape{ "rectangle", 4 }
    , length{ l }
    , width{ w }
{
}

void Rectangle::disp()
{
    size_t l { static_cast<size_t>(length)};
    size_t w { static_cast<size_t>(width)};
    for(size_t i{}; i< w; i++)
        std::cout<<"* ";
    std::cout<<std::endl;
    for(size_t i{}; i< l-2; i++)
    {
        std::cout<<"* ";
        for(size_t j{}; j< w-2 ; j++)
            std::cout<<"  ";
        std::cout<<"* "<<std::endl;
    }
    for(size_t i{}; i< w; i++)
        std::cout<<"* ";
    std::cout<<std::endl;
}

double Rectangle::perimeter()
{
    return 2 * ( width + length );
}

double Rectangle::area()
{
    return width * length;
}