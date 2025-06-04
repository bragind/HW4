#include <iostream>
#include "polygon.h"

void show_menu() {
    std::cout << "\n--- Polygon Demo ---\n";
    std::cout << "1. Create polygon from input\n";
    std::cout << "2. Show centroid\n";
    std::cout << "3. Rotate around origin\n";
    std::cout << "4. Move by vector\n";
    std::cout << "5. Print polygon\n";
    std::cout << "0. Exit\n";
    std::cout << "Choose: ";
}

int main() {
    try {
        Polygon poly;
        while (true) {
            show_menu();
            int choice;
            std::cin >> choice;

            if (choice == 0) break;

            switch (choice) {
                case 1: {
                    std::cout << "Enter number of points: ";
                    size_t n;
                    std::cin >> n;
                    Polygon temp;
                    for (size_t i = 0; i < n; ++i) {
                        Point p;
                        std::cin >> p;
                        temp.add_vertex(p);
                    }
                    poly = std::move(temp);
                    break;
                }
                case 2: {
                    std::cout << "Centroid: " << poly.centroid() << "\n";
                    break;
                }
                case 3: {
                    std::cout << "How many times to rotate 90° CCW? ";
                    int times;
                    std::cin >> times;
                    poly.rotate_around_point(Point(0, 0), times);
                    break;
                }
                case 4: {
                    Point vec;
                    std::cout << "Enter vector (x y): ";
                    std::cin >> vec;
                    poly.move_by_vector(vec);
                    break;
                }
                case 5: {
                    std::cout << poly << "\n";
                    break;
                }
                default:
                    std::cerr << "Invalid choice.\n";
            }
        }
    } catch (const std::exception& e) {
        std::cerr << "[Error] " << e.what() << "\n";
    }

    return 0;
}