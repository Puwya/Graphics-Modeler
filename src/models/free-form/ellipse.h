#pragma once

#include <QBrush>
#include <QPainter>
#include <QPen>

#include "models/shape.h"

class Ellipse : public Shape {
 public:
  Ellipse();
  virtual ~Ellipse() noexcept;

 public:
  void setMajorAxis(const int &majorAxis);
  int getMajorAxis() const;

  void setMinorAxis(const int &minorAxis);
  int getMinorAxis() const;

 public:
  float area() const override;
  float perimeter() const override;
  void paint(QPainter* painter) override;

 private:
  int majorAxis_ = 0;
  int minorAxis_ = 0;
};
