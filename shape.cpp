#include "shape.h"


Coords::Coords(double x, double y)
    : x(x), y(y)
{}

void Coords::setX(double x) {
    this->x = x;
}

void Coords::setY(double y) {
    this->y = y;
}

double Coords::getX() const {
    return x;
}

double Coords::getY() const {
    return y;
}


void Shape::addCoords(double x, double y) {
    this->coords.emplace_back(x, y);
}

Coords& Shape::getCoords(unsigned i) {
    return coords[i];
}

void Shape::setCoords(unsigned i, double newX, double newY) {
    coords[i].setX(newX);
    coords[i].setY(newY);
}

unsigned Shape::getQuantity() const {
    return coords.size();
}

void Shape::clear() {
    coords.clear();
}