#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <iostream>
#include <utility>
class Rhombus : public Figure{
private:
    double diagonal1, diagonal2, x, y;

public:
    Rhombus(double d1 = 0, double d2 = 0, double x_pos = 0, double y_pos = 0);
    std::pair<double, double> calculateCenter() const override;
    double calculateArea() const override;
    void printVertices(std::ostream &os) const override;
    void read(std::istream &is) override;
    bool operator==(const Figure &other) const override;
    Rhombus &operator=(const Rhombus &other);
    Rhombus &operator=(Rhombus &&other) noexcept;
    
};
#endif