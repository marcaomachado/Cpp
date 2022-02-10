// Copyright 2018 Universidade Federal de Minas Gerais (UFMG)

#include "complexo.h"

#include <cmath>

Complexo::Complexo() : Complexo(0, 0) {
}

Complexo::Complexo(double a) : Complexo(a, 0) {
}

Complexo::Complexo(double a, double b) {
  _real = a;
  _imag = b;
}

double Complexo::real() const {
  return _real;
}

double Complexo::imag() const {
  return _imag;
}

bool Complexo::operator==(Complexo x) const {
  // Precisão numérica utilizda.    
  static const double epsilon = 1E-6;
  return fabs(x.real() - this->_real) < epsilon && 
        fabs(x.imag() - this->_imag) < epsilon;
}

void Complexo::operator=(Complexo x) {
  _real = x.real();
  _imag = x.imag();
} 

double Complexo::modulo() const {
  return sqrt(_real * _real + _imag * _imag);
}

Complexo Complexo::conjugado() const {
  Complexo c;
  c._real = this->_real;
  c._imag = -this->_imag;
  return c;
}

Complexo Complexo::operator-() const {
  Complexo c;
  c._real = - this->_real;
  c._imag = - this->_imag;
  return c;
}

Complexo Complexo::inverso() const {
  Complexo i;
  double modQuadrado = this->modulo() * this->modulo();
  i._real = _real/modQuadrado;
  i._imag = -_imag/modQuadrado;
  return i;
}

Complexo Complexo::operator+(Complexo y) const {
  Complexo s(real() + y.real(), imag() + y.imag());
  return s;
}

Complexo Complexo::operator-(Complexo y) const {
  return (*this) + -y;
}

Complexo Complexo::operator*(Complexo y) const {
  Complexo p;
  p._real = this->_real * y.real() - this->_imag * y.imag();
  p._imag = this->_real * y.imag() + this->_imag * y.real();
  return p;
}

Complexo Complexo::operator/(Complexo y) const {
  return (*this) * y.inverso();
}
