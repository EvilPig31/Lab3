#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <iostream>
#include <utility>
#include <cmath>

class Pentagon : public Figure{
private:
    double side, x, y;

public:
    Pentagon(double s = 0, double x_pos = 0, double y_pos = 0);
    std::pair<double, double> calculateCenter() const override;
    double calculateArea() const override;
    void printVertices(std::ostream &os) const override;
    void read(std::istream &is) override;
    bool operator==(const Figure &other) const override;
    Pentagon &operator=(const Pentagon &other);
    Pentagon &operator=(Pentagon &&other) noexcept;
};
#endif