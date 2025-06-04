#include "point.h"

Point::Point(double x, double y) : x(x), y(y) {}

Point::Point(const double* coords) {
    if (coords) {
        x = coords[0];
        y = coords[1];
    }
}

double Point::distance_to(const Point& other) const {
    double dx = x - other.x;
    double dy = y - other.y;
    return std::sqrt(dx * dx + dy * dy);
}

void Point::rotate_90_deg_clockwise() {
    double temp = x;
    x = y;
    y = -temp;
}

std::istream& operator>>(std::istream& is, Point& p) {
    is >> p.x >> p.y;
    return is;
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

Point Point::operator+(const Point& other) const {
    return Point(x + other.x, y + other.y);
}

Point Point::operator-(const Point& other) const {
    return Point(x - other.x, y - other.y);
}

Point Point::operator/(double scalar) const {
    if (scalar == 0.0)
        throw std::invalid_argument("Division by zero");
    return Point(x / scalar, y / scalar);
}