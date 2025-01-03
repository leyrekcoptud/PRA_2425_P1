#ifndef POINT2D_H
#define POINT2D_H

#include <iostream>
#include <cmath>

class Point2D {
public:
    double x; // Coordenada x
    double y; // Coordenada y

    // Constructor
    Point2D(double x = 0, double y = 0) : x(x), y(y) {}

    // Método estático para calcular la distancia euclidiana entre dos puntos
    static double distance(const Point2D& a, const Point2D& b) {
        return std::sqrt(std::pow(a.x - b.x, 2) + std::pow(a.y - b.y, 2));
    }

    // Sobrecarga del operador ==
    friend bool operator==(const Point2D& a, const Point2D& b) {
        return a.x == b.x && a.y == b.y;
    }

    // Sobrecarga del operador !=
    friend bool operator!=(const Point2D& a, const Point2D& b) {
        return !(a == b);
    }

    // Sobrecarga del operador <<
    friend std::ostream& operator<<(std::ostream& out, const Point2D& p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }
};

#endif // POINT2D_H

