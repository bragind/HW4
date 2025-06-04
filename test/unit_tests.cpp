#include <gtest/gtest.h>
#include "point.h"
#include "polygon.h"

TEST(PointTest, ConstructorAndGetters) {
    Point p(1.0, 2.0);
    EXPECT_DOUBLE_EQ(p.get_x(), 1.0);
    EXPECT_DOUBLE_EQ(p.get_y(), 2.0);
}

TEST(PointTest, DistanceTo) {
    Point a(0, 0), b(3, 4);
    EXPECT_DOUBLE_EQ(a.distance_to(b), 5.0);
}

TEST(PointTest, OperatorPlus) {
    Point a(1, 2), b(3, 4);
    Point c = a + b;
    EXPECT_DOUBLE_EQ(c.get_x(), 4.0);
    EXPECT_DOUBLE_EQ(c.get_y(), 6.0);
}

TEST(PolygonTest, AddVertexAndAccess) {
    Polygon p;
    p.add_vertex(Point(1, 2));
    EXPECT_DOUBLE_EQ(p[0].get_x(), 1.0);
    EXPECT_DOUBLE_EQ(p[0].get_y(), 2.0);
}

TEST(PolygonTest, Centroid) {
    Polygon p;
    p.add_vertex(Point(0, 0));
    p.add_vertex(Point(2, 0));
    p.add_vertex(Point(1, 2));
    Point c = p.centroid();
    EXPECT_NEAR(c.get_x(), 1.0, 1e-6);
    EXPECT_NEAR(c.get_y(), 2.0 / 3, 1e-6);
}

TEST(PolygonTest, RotateAroundOrigin) {
    Polygon p;
    p.add_vertex(Point(1, 0));
    p.rotate_around_point(Point(0, 0), 1); // 90 CCW -> (0, 1)
    EXPECT_NEAR(p[0].get_x(), 0.0, 1e-6);
    EXPECT_NEAR(p[0].get_y(), 1.0, 1e-6);
}