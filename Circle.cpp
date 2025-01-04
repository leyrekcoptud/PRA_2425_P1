#include "Circle.h"
#include <cmath>

// Constructor por defecto. Crea un círculo de color rojo, centro (0,0) y radio 1.
Circle::Circle() : Shape(), center(Point2D(0, 0)), radius(1) {}

// Constructor con parámetros. Crea un círculo con los parámetros especificados.
Circle::Circle(std::string color, Point2D center, double radius) : Shape(color), center(center), radius(radius) {}

// Método consultor del atributo center
Point2D Circle::get_center() const {
    return center;
}

// Método modificador del atributo center
void Circle::set_center(Point2D p) {
    center = p;
}

// Método consultor del atributo radius
double Circle::get_radius() const {
    return radius;
}

// Método modificador del atributo radius
void Circle::set_radius(double r) {
    radius = r;
}

// Implementación del método print() de Shape
void Circle::print() {
    std::cout << "[" << "Circle: color = " << color << ", center = " << center << ", radius = " << radius << "]" << std::endl;
}

// Implementación del método area() de Shape
double Circle::area() const {
    return 3.141592 * std::pow(radius, 2);
}

// Implementación del método perimeter() de Shape
double Circle::perimeter() const {
    return 2 * 3.141592 * radius;
}

// Implementación del método translate() de Shape
void Circle::translate(double incX, double incY) {
    center.x += incX;
    center.y += incY;
}

// Sobrecarga del operador <<
std::ostream& operator<<(std::ostream& out, const Circle& c) {
    out << "["  << "Circle: color = " << c.color << ", center = " << c.center << ", radius = " << c.radius << "]";
    return out;
}

