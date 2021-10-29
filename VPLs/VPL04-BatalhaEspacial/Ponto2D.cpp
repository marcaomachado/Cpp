#include "Ponto2D.hpp"
#include <cmath>

// Ponto2D ::Ponto2D()
// {
//     this->_x = 0;
//     this->_y = 0;
// }

Ponto2D :: Ponto2D(){}

Ponto2D ::Ponto2D(double x = 0, double y = 0)
{
    this->_x = x;
    this->_y = y;
}

double Ponto2D ::calcular_distancia(Ponto2D *ponto)
{
    double dx = (*ponto)._x - this->_x;
    double dy = ponto->_y - this->_y;
    return sqrt(dx * dx + dy * dy);
}