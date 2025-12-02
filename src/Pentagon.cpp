#include "../include/Pentagon.h"

Pentagon::Pentagon(double s, double x_pos, double y_pos) : side(s), x(x_pos), y(y_pos) {}
std::pair<double, double> Pentagon::calculateCenter() const{
    return {x, y};
}
double Pentagon::calculateArea() const{
    return (5.0 * side * side) / (4.0 * tan(M_PI / 5.0));
}
void Pentagon::printVertices(std::ostream &os) const{
    os << "Pentagon vertices";
    for(int i = 0; i < 5; ++i){
        double angle = 2.0 * M_PI * i / 5.0 - M_PI / 2.0;
        double vert_x = x + side * cos(angle);
        double vert_y = y + side * sin(angle);
        os << "(" << vert_x << ", " << vert_y << ")\n";
    }
}
void Pentagon::read(std::istream &is){
    std::cout << "Enter pentagon params (side, x, y)";
    is >> side >> x >> y;
}
bool Pentagon::operator==(const Figure &other) const{
    const Pentagon *pentagon = dynamic_cast<const Pentagon*>(&other);
    if (!pentagon) return false;
    return side == pentagon->side && x == pentagon->x && y == pentagon->y;
}
Pentagon &Pentagon::operator=(const Pentagon &other){
    if (this != &other){
        side = other.side;
        x = other.x;
        y = other.y;
    }
    return *this;
}
Pentagon &Pentagon::operator=(Pentagon &&other) noexcept {
    if(this != &other) {
        side = std::move(other.side);
        x = std::move(other.x);
        y = std::move(other.y);
    }
    return *this;
}