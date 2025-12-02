#include "../include/Trapezoid.h"

Trapezoid::Trapezoid(double b1, double b2, double h, double x_pos, double y_pos) : base1(b1), base2(b2), height(h), x(x_pos), y(y_pos) {}
std::pair<double, double> Trapezoid::calculateCenter() const{
    return {x, y + height / 2.0};
}
double Trapezoid::calculateArea() const{
    return (base1 + base2) * height / 2.0;
}
void Trapezoid::printVertices(std::ostream &os) const{
    double half1 = base1 / 2.0;
    double half2 = base2 / 2.0;
    os << "Trapezoid vertices";
    os << "(" << x - half1 << ", " << y << ")\n";
    os << "(" << x + half1 << ", " << y << ")\n";
    os << "(" << x + half2 << ", " << y + height << ")\n";
    os << "(" << x - half2 << ", " << y + height << ")\n";
}
void Trapezoid::read(std::istream &is){
    std::cout << "Enter trapezoid params (base1, base2, height, x, y)";
    is >> base1 >> base2 >> height >> x >> y;
}
bool Trapezoid::operator==(const Figure &other) const{
    const Trapezoid *trapezoid = dynamic_cast<const Trapezoid*>(&other);
    if (!trapezoid) return false;
    return base1 == trapezoid->base1 && base2 == trapezoid->base2 && height == trapezoid->height && x == trapezoid->x && y == trapezoid->y;
}
Trapezoid &Trapezoid::operator=(const Trapezoid &other){
    if (this != &other){
        base1 = other.base1;
        base2 = other.base2;
        height = other.height;
        x = other.x;
        y = other.y;
    }
    return *this;
}
Trapezoid &Trapezoid::operator=(Trapezoid &&other) noexcept {
    if(this != &other) {
        base1 = std::move(other.base1);
        base2 = std::move(other.base2);
        height = std::move(other.height);
        x = std::move(other.x);
        y = std::move(other.y);
    }
    return *this;
}