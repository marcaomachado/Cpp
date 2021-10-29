#ifndef NAVE_H
#define NAVE_H

#include "Ponto2D.hpp"

struct Nave
{
    Ponto2D _posicao;
    double _forcaDeAtaque = 1;
    double _energia = 100;

    Nave(Ponto2D posicao, double forcaDeAtaque);
    Nave(Ponto2D posicao);
    Nave();

    void mover(double dx, double dy);
    double calcular_distancia(Nave* nave);
    Nave* determinar_nave_mais_proxima(Nave** naves, int n);
    void atacar(Nave** naves, int n);
    void imprimir_status();
};

#endif