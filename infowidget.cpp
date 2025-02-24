#include "infowidget.h"

#include <QWidget>

InfoWidget::InfoWidget(QWidget *parent) : QWidget(parent) {

    areaLabel = new QLabel("Площадь: ", this);
    perimeterLabel = new QLabel("Периметр: ", this);
    coordinatesLabel = new QLabel("Координаты: ", this);

    xInput = new QLineEdit(this);
    yInput = new QLineEdit(this);
    updateButton = new QPushButton("Изменить координаты", this);

    // Установка компоновщика
    QVBoxLayout *layout = new QVBoxLayout(this);
    layout->addWidget(areaLabel);
    layout->addWidget(perimeterLabel);
    layout->addWidget(coordinatesLabel);
    layout->addWidget(new QLabel("X:", this));
    layout->addWidget(xInput);
    layout->addWidget(new QLabel("Y:", this));
    layout->addWidget(yInput);
    layout->addWidget(updateButton);

    setLayout(layout);

    // Подключение сигнала к слоту
    connect(updateButton, &QPushButton::clicked, this, &InfoWidget::updateCoordinates);
}

void InfoWidget::updateCoordinates() {
    QString x = xInput->text();
    QString y = yInput->text();
    coordinatesLabel->setText("Координаты: (" + x + ", " + y + ")");
    // Здесь можно добавить логику для обновления площади и периметра
}
