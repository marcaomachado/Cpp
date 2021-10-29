#include <iostream>
#include "Nave.hpp"
#include "Ponto2D.hpp"
#include <cmath>
using namespace std;


Nave :: Nave(){}
Nave :: Nave(Ponto2D posicao, double forcaDeAtaque)
{
    _posicao = posicao;
    _forcaDeAtaque = forcaDeAtaque;
}

Nave :: Nave(Ponto2D posicao){
    _posicao = posicao;
}

void Nave :: mover(double dx, double dy)
{
    this->_posicao._x += dx;
    this->_posicao._y += dy;
}


double Nave :: calcular_distancia(Nave* nave)
{
    double dx = this->_posicao._x - nave->_posicao._x;
    double dy = this->_posicao._y - nave->_posicao._y;
    return sqrt(dx * dx + dy * dy);
}

Nave* Nave :: determinar_nave_mais_proxima(Nave** naves, int n)
{
    double menorDistancia = 1000;
    int index = 0;
    for (int i = 0; i < n; i++)
    {
        if (menorDistancia > calcular_distancia(*(naves+i)) && 
            ( (*(naves + i))->_posicao._x != this->_posicao._x ||(*(naves + i))->_posicao._y != this->_posicao._y))
        {
            menorDistancia = calcular_distancia(*(naves+i));  // naves[i] = *(naves + i) ?
            index = i;
        }
    }
    return *(naves + index);
}

void Nave ::atacar(Nave** naves, int n)
{
    Nave* alvo = determinar_nave_mais_proxima(naves, n);
    double d = calcular_distancia(alvo);
    double dano = (100 / d) * this->_forcaDeAtaque;
    if(dano < 30)
        alvo->_energia -= dano;
    else
        alvo->_energia -= 30;

    if( alvo->_energia <= 50)
        cout << "Energia baixa" << endl; 
}

void Nave :: imprimir_status()
{
    cout << this->_posicao._x << " " << this->_posicao._y << " " << this->_energia << endl;
}
