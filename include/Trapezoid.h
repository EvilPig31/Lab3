#ifndef TRAPEZOID_H
#define TRAPEZOID_H

#include "Figure.h"
#include <iostream>
#include <utility>
class Trapezoid : public Figure{
private:
    double base1, base2, height, x, y;

public:
    Trapezoid(double b1 = 0, double b2 = 0, double h = 0, double x_pos = 0, double y_pos = 0);
    std::pair<double, double> calculateCenter() const override;
    double calculateArea() const override;
    void printVertices(std::ostream &os) const override;
    void read(std::istream &is) override;
    bool operator==(const Figure &other) const override;
    Trapezoid &operator=(const Trapezoid &other);
    Trapezoid &operator=(Trapezoid &&other) noexcept;
    
};
#endif