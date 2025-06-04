#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <cmath>

class Point {
public:
    double x = 0.0;
    double y = 0.0;

    // Конструкторы
    Point() = default;
    Point(double x, double y);
    explicit Point(const double* coords);

    // Геттеры
    double get_x() const { return x; }
    double get_y() const { return y; }

    // Сеттеры
    void set_x(double x) { this->x = x; }
    void set_y(double y) { this->y = y; }

    // Расстояние до другой точки
    double distance_to(const Point& other) const;

    // Вращение точки на 90 градусов по часовой стрелке
    void rotate_90_deg_clockwise();

    // Операторы
    friend std::istream& operator>>(std::istream& is, Point& p);
    friend std::ostream& operator<<(std::ostream& os, const Point& p);

    Point operator+(const Point& other) const;
    Point operator-(const Point& other) const;
    Point operator/(double scalar) const;
};

#endif // POINT_H