#include "triangle.h"

Triangle::Triangle(double b, double s)
    : _2Dshape { "triangle" , 3 }
    , side { s }
    , base { b }
{
}

void Triangle::disp()
{
    double height { sqrt( pow( side , 2) - pow( base/2 , 2 ))};
    size_t s { static_cast<size_t>( base ) };
    size_t line {static_cast<size_t>( base )};
    size_t counter {};
    size_t fit {};
    line = 2 * line - 1 ;
    size_t j {};
    for (size_t k {}; k < static_cast<size_t>( height )+1 ; k++)
    { 
        for (size_t i {  0 }; i < 2*line  ; i++)
        {
            if( i  == s - j)
            {
                std::cout<< " *";
                counter = 0;
            }
            else if( i == s + j && j != 0 )
            {
                std::cout<< " *";
                break;
            }
            else
                std::cout<< "  ";
            counter++ ;
        }
        std::cout<< std::endl;
        j++;
    }
    fit = abs( line  - counter + 1 );
    while( fit )
    {
        std::cout<<" ";
        fit--;
    }
    if( base +2 >= static_cast<double> ( counter ) )
    {   

        for (size_t i {}; i <static_cast<size_t>( base ) ; i++)
            std::cout<< "* ";
    }

    if( static_cast<double> ( counter ) > base +2 )
        for (size_t i {}; i <static_cast<size_t>( base ) ; i++)
            std::cout<< "*  ";
    std::cout<<std::endl;
}

double Triangle::perimeter()
{
   return 2 * side + base ;
}

double Triangle::area()
{
   double height { sqrt( pow( side , 2) - pow( base/2 , 2 ))};
   return ( height * base )/2 ;
}