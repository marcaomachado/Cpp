/**
 * Todas as tarefas deste exercicio devem ser feitas sobre esse arquivo.
 * Os metodos e operacoes marcados com a tag "TODO" devem ser editados.
 */

#include "polygon.h"

std::ostream& operator<<(std::ostream& out, const Polygon& poly) {
  for (const Point& p : poly.limits) {
    out << " " << p;
  }
  return out;
}

bool operator==(const Polygon& lhs, const Polygon& rhs) {
  // std::cout << "RHS: " << rhs.limits[0].x << ", " << rhs.limits[0].y
  //           << std::endl;
  // std::cout << "LHS: " << lhs.limits[0].x << ", " << lhs.limits[0].y
  //           << std::endl;

  for (Point point : (std::vector<Point>)lhs) {
    if (!(rhs.contains(point))) {
      return false;
    }
  }
  for (Point point : (std::vector<Point>)rhs) {
    if (!(lhs.contains(point))) {
      return false;
    }
  }
  return true;
}

bool Point::contains(const Point& p) const {
  return p.x == this->x && p.y == this->y;
}

std::ostream& operator<<(std::ostream& out, const Point& p) {
  out << "(" << p.x << ", " << p.y << ")";
  return out;
}

bool RightRectangle::contains(const Point& p) const {
  // std::cout << "ENTROU NO CONTAINS" << std::endl;

  // int botLeftPointPosition = 0;
  // int topRightPointPosition = 0;
  // int counterInf = 0;
  // int counterSup = 0;

  // for (int i = 0; i < limits.size(); i++) {
  //   for (int j = 0; j < limits.size(); j++) {
  //     if (limits[i].x <= limits[j].x && limits[i].y <= limits[j].y) {
  //       counterInf++;
  //     }
  //     if (limits[i].x >= limits[j].x && limits[i].y >= limits[j].y) {
  //       counterSup++;
  //     }
  //   }
  //   if (counterInf == limits.size()) {
  //     botLeftPointPosition = i;
  //   }
  //   if (counterSup == limits.size()) {
  //     topRightPointPosition = i;
  //   }
  //   counterInf = 0;
  //   counterSup = 0;
  // }

  // if (p.x >= limits[botLeftPointPosition].x &&
  //     p.x <= limits[topRightPointPosition].x &&
  //     p.y >= limits[botLeftPointPosition].y &&
  //     p.y <= limits[topRightPointPosition].y) {
  //   return true;
  // }

  // std::cout << " p = " << p.x << ", " << p.y << std::endl;
  // std::cout << " bot = " << this->limits[0].x << ", " << this->limits[0].y
  //           << std::endl;
  // std::cout << " top =" << this->limits[1].x << ", " << this->limits[1].y
  //           << std::endl;

  if (p.x >= this->limits[0].x && p.x <= this->limits[1].x &&
      p.y >= this->limits[0].y && p.y <= this->limits[1].y) {
    return true;
  }

  return false;
}

Point::Point(int xx, int yy) : x(xx), y(yy) {
  this->limits.push_back(*this);
}

RightRectangle::RightRectangle(int x0, int y0, int x1, int y1) {
  // std::cout << " x0 = " << x0 << ", "
  //           << " y0 = " << y0 << ", "
  //           << " x1 = " << x1 << ", "
  //           << " y1 = " << y1 << ", " << std::endl;
  int menorX = x0;
  int maiorX = x1;
  int menorY = y0;
  int maiorY = y1;
  if (x1 <= x0) {
    menorX = x1;
    maiorX = x0;
  }
  if (y1 <= y0) {
    menorY = y1;
    maiorY = y0;
  }

  this->limits.push_back(Point(menorX, menorY));
  this->limits.push_back(Point(maiorX, maiorY));

  // std::cout << " limits x0 = " << this->limits[0].x << ", "
  //           << " limits y0 = " << this->limits[0].y << ", "
  //           << " limits x1 = " << this->limits[1].x << ", "
  //           << " limits y1 = " << this->limits[1].y << ", " << std::endl;
}