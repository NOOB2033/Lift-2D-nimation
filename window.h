#ifndef WINDOW_H
#define WINDOW_H


#include <QtGui>
#include <QPushButton>
#include <QObject>
#include <QVBoxLayout>


#include "area.h"


class Window : public QWidget
{

    Q_OBJECT

public:

    Window();
    ~Window() = default;

public slots:

    void start();

protected:

    std::unique_ptr<Area> area;
    std::unique_ptr<QPushButton> startBtn;
    std::unique_ptr<QPushButton> exitBtn;
    std::unique_ptr<QVBoxLayout> vLayout;

};


#endif // WINDOW_H