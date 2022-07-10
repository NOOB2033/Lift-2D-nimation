#include <QPainter>
#include <QTimerEvent>
#include <math.h>


#include "area.h"


Area::Area(QWidget* parent)
    : QWidget(parent)
{
    start_coords();
    setFixedSize(QSize(500, 500));
}

void Area::paintEvent(QPaintEvent*)
{
    QPainter painter(this);
    painter.setPen(Qt::darkYellow);
    Matrix leafMatrix;
    leafMatrix.getMatrix()[0] = 1;
    leafMatrix.getMatrix()[4] = 1;
    leafMatrix.getMatrix()[8] = 1;
    double centerX = 0, centerY = 0;
    for (unsigned i = 0; i < 4; ++i) {
        centerX += leaf.getCoords(i).getX();
        centerY += leaf.getCoords(i).getY();
    }

    Coords leafCenter(centerX / 4, centerY / 4);
    translateShape(leafMatrix, leafCenter);
    scaleShape(leafMatrix, scale);
    rotateShape(leafMatrix);
    Coords reverseCenterSquare(-leafCenter.getX(), -leafCenter.getY());
    translateShape(leafMatrix, reverseCenterSquare);
    shiftShape(leafMatrix, leafCenter.getX(),leafCenter.getY());
    setNewCoords(leafMatrix);


    for (unsigned i = 0; i < leaf.getQuantity() - 1; ++i) {
        if (i < 4) {
            Coords& first = leaf.getCoords(i);
            Coords& second = leaf.getCoords((i + 1));
            painter.drawLine(first.getX(), first.getY(), second.getX(), second.getY());
        } else {
            Coords& first = leaf.getCoords(i);
            Coords& second = leaf.getCoords((i + 1));
            painter.drawLine(first.getX(), first.getY(), second.getX(), second.getY());
        }
    }
}

void Area::timerEvent(QTimerEvent* event) {
    update();
}

void Area::start() {
    myTimer = startTimer(50);
}

void Area::setNewCoords(Matrix& changeMatrix) {
    Matrix newMatrix;
    for (unsigned i = 0; i < leaf.getQuantity(); ++i) {
        newMatrix.getMatrix()[0] = leaf.getCoords(i).getX();
        newMatrix.getMatrix()[1] = leaf.getCoords(i).getY();
        newMatrix.getMatrix()[2] = 1;
        newMatrix *= changeMatrix;
        leaf.setCoords(i, newMatrix.getMatrix()[0], newMatrix.getMatrix()[1]);
    }
}

void Area::translateShape(Matrix& oldMatrix, Coords& value) {
    Matrix newMatrix;
    newMatrix.getMatrix()[0] = 1;
    newMatrix.getMatrix()[4] = 1;
    newMatrix.getMatrix()[8] = 1;
    newMatrix.getMatrix()[6] = -value.getX();
    newMatrix.getMatrix()[7] = -value.getY();
    oldMatrix *= newMatrix;
}

void Area::rotateShape(Matrix& oldMatrix) {
    Matrix newMatrix;
    newMatrix.getMatrix()[0] = 1;
    newMatrix.getMatrix()[4] = 1;
    newMatrix.getMatrix()[8] = 1;

    newMatrix.getMatrix()[0] = cos(angle);
    newMatrix.getMatrix()[1] = sin(angle);
    newMatrix.getMatrix()[3] = -sin(angle);
    newMatrix.getMatrix()[4] = cos(angle);
    oldMatrix *= newMatrix;
}

void Area::scaleShape(Matrix& oldMatrix, double value) {
    Matrix newMatrix;
    newMatrix.getMatrix()[0] = 1;
    newMatrix.getMatrix()[4] = 1;
    newMatrix.getMatrix()[8] = 1;
    newMatrix.getMatrix()[0] = value;
    newMatrix.getMatrix()[4] = value;
    oldMatrix *= newMatrix;
}

void Area::shiftShape(Matrix& oldMatrix, double X, double Y) {
    Matrix newMatrix;
    newMatrix.getMatrix()[0] = 1;
    newMatrix.getMatrix()[4] = 1;
    newMatrix.getMatrix()[8] = 1;
    if(Y > 480)
    {
        clear();
        start_coords();
    }
    if(!side)
    {
        if(X < 15)
        {
            side = !side;
            angle = -angle;
        }
    }
    else {
        if(X > 470)
        {
                side = !side;
                angle = -angle;
        }
    }
    if(side)
    {
        newMatrix.getMatrix()[6] = 7;
        newMatrix.getMatrix()[7] = 2;
    }
    else
    {
        newMatrix.getMatrix()[6] = -7;
        newMatrix.getMatrix()[7] = 2;
    }
    oldMatrix *= newMatrix;
}

void Area::start_coords()
{
    leaf.addCoords(480, 20);
    leaf.addCoords(480, 40);
    leaf.addCoords(445, 55);
    leaf.addCoords(460, 20);
    leaf.addCoords(480, 20);
    leaf.addCoords(470, 30);
    leaf.addCoords(490, 10);
    side = false;
    angle = 0.02;
    scale = 1.005;
}

void Area::clear()
{
    leaf.clear();
}

Area:: ~Area()
{
    clear();
}