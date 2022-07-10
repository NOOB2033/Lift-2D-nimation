#ifndef SHAPE_H
#define SHAPE_H


#include <vector>
#include <memory>


class Coords {

public:

    Coords(double x, double y);
    ~Coords() = default;

    void setX(double x);
    void setY(double y);
    double getX() const;
    double getY() const;

private:

    double x;
    double y;

};


class Shape {

public:

    Shape() = default;
    ~Shape() = default;

    void addCoords(double x, double y);
    Coords& getCoords(unsigned i);
    void setCoords(unsigned i, double newX, double newY);
    unsigned getQuantity() const;
    void clear();

private:

    std::vector<Coords> coords;

};


#endif // SHAPE_H