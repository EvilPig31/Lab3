#include "../include/Rhombus.h"

Rhombus::Rhombus(double d1, double d2, double x_pos, double y_pos) : diagonal1(d1), diagonal2(d2), x(x_pos), y(y_pos) {}
std::pair<double, double> Rhombus::calculateCenter() const{
    return {x, y};
}
double Rhombus::calculateArea() const{
    return (diagonal1 * diagonal2) / 2.0;
}
void Rhombus::printVertices(std::ostream &os) const{
    double half1 = diagonal1 / 2.0;
    double half2 = diagonal2 / 2.0;
    os << "Rjombus vertices";
    os << "(" << x << ", " << y + half2 << ")\n";
    os << "(" << x + half1 << ", " << y << ")\n";
    os << "(" << x << ", " << y - half2 << ")\n";
    os << "(" << x - half2 << ", " << y << ")\n";
}
void Rhombus::read(std::istream &is){
    std::cout << "Enter rhombus params (diagonal1, diagonal2 x, y)";
    is >> diagonal1 >> diagonal2 >> x >> y;
}
bool Rhombus::operator==(const Figure &other) const{
    const Rhombus *rhombus = dynamic_cast<const Rhombus*>(&other);
    if (!rhombus) return false;
    return diagonal1 == rhombus->diagonal1 && diagonal2 == rhombus->diagonal2 && x == rhombus->x && y == rhombus->y;
}
Rhombus &Rhombus::operator=(const Rhombus &other){
    if (this != &other){
        diagonal1 = other.diagonal1;
        diagonal2 = other.diagonal2;
        x = other.x;
        y = other.y;
    }
    return *this;
}
Rhombus &Rhombus::operator=(Rhombus &&other) noexcept {
    if(this != &other) {
        diagonal1 = std::move(other.diagonal1);
        diagonal2 = std::move(other.diagonal2);
        x = std::move(other.x);
        y = std::move(other.y);
    }
    return *this;
}