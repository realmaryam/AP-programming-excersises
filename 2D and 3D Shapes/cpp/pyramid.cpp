#include "pyramid.h"

Pyramid::Pyramid(double h, _2Dshape* base, size_t pharaoh)
    : _3Dshape { "pyramid" , h , base }
{
    std::cout<<"pyramid constructor"<<std::endl;
    this->pharaoh = new char() ;
    if( pharaoh == 1)
        this->pharaoh = strdup("Tutankhamun");
    if( pharaoh == 2)
        this->pharaoh = strdup("Ramesses"); 
    if( pharaoh == 3)
        this->pharaoh = strdup("Cleopatra"); 
}

Pyramid::Pyramid(const Pyramid& p)
    : _3Dshape {p.type , p.height, p.base}
{
    std::cout<<"pyramid copy constructor"<<std::endl;
    pharaoh = new char() ;
    strcpy(pharaoh , p.pharaoh);
}

Pyramid::Pyramid(Pyramid&& p)
    : _3Dshape {std::move(p)}
{
    std::cout<<"pyramid move constructor"<<std::endl;
    pharaoh = p.pharaoh;
    p.pharaoh = nullptr;
}

Pyramid::~Pyramid()
{
    delete[] pharaoh;
    pharaoh = NULL ;
    std::cout << "pyramid distructor"<<std::endl;
}

double Pyramid::volume()
{
    return base->area() * height / 3 ;
}

double Pyramid::area()
{
    if( !strcmp(base->getName(), "square"))
    {
        double side { base->perimeter()/4};
        double slant { sqrt( pow( side/2 , 2) + pow( height , 2) )};
        return slant * side * 2 + base->area() ;
    }
    if( !strcmp(base->getName(), "rectangle"))
    {
        double f_side {};
        double s_side {};
        double perimeter { base->perimeter() };
        double area { base->area() };
        double f_slant {};
        double s_slant {};
        f_side = ( perimeter/2 + sqrt( pow( perimeter/2 , 2) - 4 * area ) )/2 ;
        s_side = ( perimeter/2 - sqrt( pow( perimeter/2 , 2) - 4 * area ) )/2 ;
        f_slant = { sqrt( pow( s_side/2 , 2) + pow( height , 2) )};
        s_slant = { sqrt( pow( f_side/2 , 2) + pow( height , 2) )};
        return area + f_slant * f_side + s_slant * s_side ;
    }
    if( !strcmp(base->getName(), "triangle"))
    {
        Triangle* _base = dynamic_cast<Triangle*>(this->base);
        double base_side { _base->base };
        double base_base { _base->side };
        double base_height { sqrt( pow( base_side , 2) - pow( base_base/2 , 2 ))};
        double hprim = { (base_base * base_height)/ (3 * base_side) };
        double slant1 = { sqrt( pow( hprim , 2) + pow( height , 2) )};
        double slant2 = { sqrt( pow( base_height/3 , 2) + pow( height , 2) )};
        std::cout << "this is Pyramid's area with base triangle: "<<base->area() + slant1 * base_side + slant2/2 * base_base<<std::endl;
        return base->area() + slant1 * base_side + slant2/2 * base_base;
    }
    return 0;
}

Pyramid& Pyramid::operator= (const Pyramid& p)
{
    std::cout<< "operator="<<std::endl;
    if(this == &p)
        return *this;
    base = p.base;
    height = p.height;
    type = p.type;
    delete[] pharaoh;
    pharaoh = new char (*p.pharaoh);
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Pyramid& p)
{
    std::cout<< "Pharaoh "<< p.pharaoh << " is buried in this pyramid!"<<std::endl;
    return os;
}