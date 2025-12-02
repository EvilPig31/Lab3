#ifndef FIGURE_H
#define FIGURE_H

#include <string>
#include <vector>

class Figure{
public:
    virtual ~Figure() = default;
    virtual std::pair<double, double> calculateCenter() const = 0;
    virtual double calculateArea() const = 0;
    virtual void printVertices(std::ostream &os) const = 0;
    virtual void read(std::istream &is) = 0;
    virtual bool operator==(const Figure &other) const = 0;
    operator double() const{
        return calculateArea();
    }
};
std::ostream &operator<<(std::ostream &os, const Figure &figure);
std::istream &operator>>(std::istream &is, Figure &figure);
#endif