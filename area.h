#ifndef AREA_H
#define AREA_H


#include <QWidget>


#include "shape.h"
#include "matrix.h"


class Area : public QWidget
{

    Q_OBJECT

public:

    Area(QWidget* parent = nullptr);
    ~Area();

public slots:

    void start();

protected:

    void paintEvent(QPaintEvent* event); //событие перерисовки
    void timerEvent(QTimerEvent* event); //событие таймера

private:

    Shape leaf;
    int myTimer;
    bool side;
    double angle;
    double scale;
    void setNewCoords(Matrix& changeMatrix);
    void translateShape(Matrix& oldMatrix, Coords& value);
    void rotateShape(Matrix& oldMatrix);
    void scaleShape(Matrix& oldMatrix, double value);
    void shiftShape(Matrix& oldMatrix, double X, double Y);
    void start_coords();
    void clear();

};


#endif // AREA_H