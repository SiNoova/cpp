#include <iostream>
#include "Point.hpp"

int main()
{
    Point a(Fixed(1), Fixed(2));
    Point b(Fixed(2), Fixed(0));
    Point c(Fixed(0), Fixed(0));

    Point inside(Fixed(1), Fixed(1.9f));     
    Point edge(Fixed(0.1f), Fixed(0.3f));   
    Point outside(Fixed(0.5f), Fixed(1.5f)); 

    std::cout << "Inside point: " << bsp(a, b, c, inside) << std::endl;
    std::cout << "Edge point:   " << bsp(a, b, c, edge) << std::endl;
    std::cout << "Outside point:" << bsp(a, b, c, outside) << std::endl;

    return 0;
}
