#include "polyline.h"

Polyline::Polyline() {}

Polyline::~Polyline() noexcept {}

float Polyline::area() const {
  return 0;
}

float Polyline::perimeter() const {
  return 0;
}

void Polyline::draw() const {
  // getPoints and call QPainter.drawLine(Qpoint......)
}

void Polyline::move() {}
