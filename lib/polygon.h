#ifndef POLYGON_H
#define POLYGON_H

#include "point.h"
#include <vector>

class Polygon {
private:
    Point* vertices = nullptr;
    size_t capacity = 0;
    size_t size = 0;

    void copy_from(const Polygon& other);
    void move_from(Polygon&& other) noexcept;

public:
    // Конструкторы
    Polygon();
    explicit Polygon(const Point& p);
    Polygon(size_t count, const Point* points);
    Polygon(const Polygon& other);
    Polygon(Polygon&& other) noexcept;
    ~Polygon();

    // Операторы
    Polygon& operator=(const Polygon& other);
    Polygon& operator=(Polygon&& other) noexcept;

    // Методы
    void add_vertex(const Point& p);
    Point& operator[](size_t index);
    const Point& operator[](size_t index) const;
    Point centroid() const;
    void rotate_around_point(const Point& center, int times_90_deg_ccw);
    void move_by_vector(const Point& vector);

    // Ввод/вывод
    friend std::istream& operator>>(std::istream& is, Polygon& poly);
    friend std::ostream& operator<<(std::ostream& os, const Polygon& poly);
};

#endif // POLYGON_H