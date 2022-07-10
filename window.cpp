#include "window.h"


Window::Window()
{
    area = std::make_unique<Area>(this);
    startBtn = std::make_unique<QPushButton>("Start", this);
    exitBtn = std::make_unique<QPushButton>("Exit", this); //создаем кнопку
    vLayout = std::make_unique<QVBoxLayout>(this);
    vLayout->addWidget(area.get());
    vLayout->addWidget(startBtn.get());
    vLayout->addWidget(exitBtn.get());
    connect(startBtn.get(), SIGNAL(clicked(bool)), area.get(), SLOT(start()));
    connect(exitBtn.get(), SIGNAL(clicked(bool)), this, SLOT(close()));
}

void Window::start() {
    area->start();
}