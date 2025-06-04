#include "polygon.h"
#include <stdexcept>
#include <algorithm>

Polygon::Polygon() = default;

Polygon::Polygon(const Point& p) {
    add_vertex(p);
}

Polygon::Polygon(size_t count, const Point* points) {
    for (size_t i = 0; i < count; ++i)
        add_vertex(points[i]);
}

void Polygon::copy_from(const Polygon& other) {
    vertices = new Point[other.capacity];
    size = other.size;
    capacity = other.capacity;
    std::copy(other.vertices, other.vertices + size, vertices);
}

Polygon::Polygon(const Polygon& other) {
    copy_from(other);
}

Polygon::Polygon(Polygon&& other) noexcept {
    move_from(std::move(other));
}

Polygon::~Polygon() {
    delete[] vertices;
}

Polygon& Polygon::operator=(const Polygon& other) {
    if (this != &other) {
        delete[] vertices;
        copy_from(other);
    }
    return *this;
}

Polygon& Polygon::operator=(Polygon&& other) noexcept {
    if (this != &other) {
        delete[] vertices;
        move_from(std::move(other));
    }
    return *this;
}

void Polygon::add_vertex(const Point& p) {
    if (size >= capacity) {
        size_t new_cap = capacity == 0 ? 1 : capacity * 2;
        Point* new_vertices = new Point[new_cap];
        std::copy(vertices, vertices + size, new_vertices);
        delete[] vertices;
        vertices = new_vertices;
        capacity = new_cap;
    }
    vertices[size++] = p;
}

Point& Polygon::operator[](size_t index) {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return vertices[index];
}

const Point& Polygon::operator[](size_t index) const {
    if (index >= size)
        throw std::out_of_range("Index out of range");
    return vertices[index];
}

std::istream& operator>>(std::istream& is, Polygon& poly) {
    size_t n;
    is >> n;
    for (size_t i = 0; i < n; ++i) {
        Point p;
        is >> p;
        poly.add_vertex(p);
    }
    return is;
}

std::ostream& operator<<(std::ostream& os, const Polygon& poly) {
    os << "Polygon (" << poly.size << " vertices):\n";
    for (size_t i = 0; i < poly.size; ++i)
        os << "  " << poly.vertices[i] << "\n";
    return os;
}

Point Polygon::centroid() const {
    if (size == 0)
        throw std::runtime_error("Cannot compute centroid of empty polygon");

    Point sum;
    for (size_t i = 0; i < size; ++i) {
        sum = sum + vertices[i];
    }
    return Point(sum.x / size, sum.y / size);
}

void Polygon::rotate_around_point(const Point& center, int times_90_deg_ccw) {
    times_90_deg_ccw = ((times_90_deg_ccw % 4) + 4) % 4;
    for (size_t i = 0; i < size; ++i) {
        Point rel = vertices[i] - center;
        for (int t = 0; t < times_90_deg_ccw; ++t)
            rel.rotate_90_deg_clockwise();
        vertices[i] = rel + center;
    }
}

void Polygon::move_by_vector(const Point& vector) {
    for (size_t i = 0; i < size; ++i)
        vertices[i] = vertices[i] + vector;
}

void Polygon::move_from(Polygon&& other) noexcept {
    vertices = other.vertices;
    size = other.size;
    capacity = other.capacity;
    other.vertices = nullptr;
    other.size = 0;
    other.capacity = 0;
}