#include "canvas.h"
#include <QWidget>
#include <QPainter>
#include <QMouseEvent>
#include <QColorDialog>
#include <QPushButton>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QList>
#include "rectangle.h"
#include "triangle.h"
#include "hexagon.h"
#include "rhomb.h"
#include "square.h"
#include "circle.h"
#include "ellipse.h"
#include "stars.h"

Canvas::Canvas(QWidget *parent)
    : QWidget(parent), drawing(false), color(Qt::white), selectedShape(nullptr) {

    shapeComboBox = new QComboBox(this);
    shapeComboBox->addItem("Прямоугольник");
    shapeComboBox->addItem("Треугольник");
    shapeComboBox->addItem("Круг");
    shapeComboBox->addItem("Шестиугольник");
    shapeComboBox->addItem("Ромб");
    shapeComboBox->addItem("Квадрат");
    shapeComboBox->addItem("Эллипс");
    shapeComboBox->addItem("Восьмиконечная звезда");
    shapeComboBox->addItem("Пятиконечная звезда");
    shapeComboBox->addItem("Шестиконечная звезда");

    QPushButton *colorButton = new QPushButton("Выбрать цвет", this);
    connect(colorButton, &QPushButton::clicked, this, &Canvas::chooseColor);

    // Создаем кнопку для очистки холста
    QPushButton *clearButton = new QPushButton("Очистить", this);
    connect(clearButton, &QPushButton::clicked, this, &Canvas::clear);
    shapeComboBox->setStyleSheet("QComboBox {"
                                 "background-color: #8B00FF;"
                                 "color: white;"
                                 "padding: 10px;"
                                 "border-radius: 5px;"
                                 "}"
                                 "QComboBox:hover {"
                                 "background-color: #9B59B6;"
                                 "}");

    colorButton->setStyleSheet("QPushButton {"
                               "background-color: #4CAF50;"
                               "color: white;"
                               "border: none;"
                               "padding: 10px;"
                               "border-radius: 5px;"
                               "}"
                               "QPushButton:hover {"
                               "background-color: #45a049;"
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #388e3c;"
                               "}");

    clearButton->setStyleSheet("QPushButton {"
                               "background-color: #e81313;"
                               "color: white;"
                               "border: none;"
                               "padding: 10px;"
                               "border-radius: 5px;"
                               "}"
                               "QPushButton:hover {"
                               "background-color: #e20606;"
                               "}"
                               "QPushButton:pressed {"
                               "background-color: #c00707;"
                               "}");

    QHBoxLayout *buttonLayout = new QHBoxLayout();
    buttonLayout->addStretch();
    buttonLayout->addWidget(colorButton);
    buttonLayout->addWidget(clearButton);
    buttonLayout->addWidget(shapeComboBox);

    QVBoxLayout *mainLayout = new QVBoxLayout(this);
    mainLayout->addLayout(buttonLayout);
    mainLayout->addStretch();

    setLayout(mainLayout);
}

void Canvas::chooseColor() {
    QColor newColor = QColorDialog::getColor(color, this, "Выберите цвет");
    if (newColor.isValid()) {
        setColor(newColor);
    }
}

void Canvas::setColor(const QColor &newColor) {
    color = newColor;
}

void Canvas::clear() {
    shapes.clear();
    update();
}

void Canvas::mousePressEvent(QMouseEvent *event) {
    if (event->button() == Qt::LeftButton) {
        for (auto &shape : shapes) {
            if (shape->contains(event->pos())) {
                qDebug() << "Shape selected:" << typeid(*shape).name();
                if (selectedShape) {
                    selectedShape->changeSelection();
                }
                endPoint = event->pos();
                selectedShape = shape;
                shape->changeSelection();
                update();
                return;
            }
        }


    if (selectedShape) {
        selectedShape->changeSelection();
        selectedShape = nullptr;
        update();
    }
        drawing = true;
        startPoint = event->pos();
        endPoint = event->pos();
    }
}

void Canvas::mouseMoveEvent(QMouseEvent *event) {
    if (drawing) {
        if (!rect().contains(event->pos())) {
            endPoint = event->pos();
            QString selectedShape = shapeComboBox->currentText();
            if (selectedShape == "Прямоугольник") {
                shapes.append(new Rectangle(startPoint, endPoint, color));
            }else if(selectedShape == "Треугольник") {
                shapes.append(new Triangle(startPoint, endPoint, QPoint(startPoint.x() - (endPoint.x() - startPoint.x()),endPoint.y()), color));
            }else if(selectedShape == "Шестиугольник"){
                shapes.append(new Hexagon(startPoint, endPoint, color));
            }
            drawing = false;
            update();
            return;
        }
        endPoint = event->pos();
        update();
    }else if(selectedShape){
        qDebug() << "move";
        QPoint different = event->pos() - endPoint;

        // Перемещаем выбранную фигуру
        selectedShape->move(different);

        endPoint = event->pos();

        update();

    }
}

void Canvas::mouseReleaseEvent(QMouseEvent* event) {
    if (event->button() == Qt::LeftButton && drawing) {
        drawing = false;
        endPoint = event->pos();

        QString selectedShape = shapeComboBox->currentText();
        Shap* shape = nullptr;

        if (selectedShape == "Прямоугольник") {
            shape = new Rectangle(startPoint, endPoint, color);
        }else if (selectedShape == "Треугольник") {
            shape = new Triangle(startPoint, endPoint, QPoint(startPoint.x() - (endPoint.x() - startPoint.x()),endPoint.y()), color);
        }else if(selectedShape == "Шестиугольник")
        {
            shape = new Hexagon(startPoint, endPoint, color);
        }else if(selectedShape == "Ромб"){
            shape = new Rhomb(startPoint, endPoint, color);
        }else if(selectedShape == "Квадрат"){
            shape = new Square(startPoint, endPoint, color);
        }else if (selectedShape == "Круг") {
            shape = new Circle(startPoint, endPoint, color);
        }else if (selectedShape == "Эллипс"){
            shape = new Ellipse(startPoint, endPoint, color);
        }else if(selectedShape == "Восьмиконечная звезда"){
            shape = new Stars(startPoint, endPoint, 8, color);
        }else if(selectedShape == "Пятиконечная звезда"){
            shape = new Stars(startPoint, endPoint, 5, color);
        }else if(selectedShape == "Шестиконечная звезда"){
            shape = new Stars(startPoint, endPoint, 6, color);
        }


        if (shape) {
            shapes.append(shape);
        }

        update();
    }
}

void Canvas::paintEvent(QPaintEvent* event) {
    Q_UNUSED(event);

    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    // Рисуем
    for (const auto& shape : shapes) {
        shape->draw(painter);
    }
    if (selectedShape) {
        QPoint center = selectedShape->center();
        painter.setBrush(Qt::green); // Зеленый цвет для центра масс
        painter.setPen(Qt::black);   // Черный контур
        painter.drawEllipse(center, 4, 4); // Рисуем круг радиусом 5 пикселей
    }

    // рисуем текущую фигуру(процесс рисования)
    if (drawing) {
        QString selectedShape = shapeComboBox->currentText();
        if (selectedShape == "Прямоугольник") {
            Rectangle tempRect(startPoint, endPoint, color);
            tempRect.draw(painter);
        }else if (selectedShape == "Треугольник") {
            Triangle tempTriangle(startPoint, endPoint, QPoint(startPoint.x() + startPoint.x() - endPoint.x(),endPoint.y()), color);
            tempTriangle.draw(painter);
        }else if(selectedShape == "Шестиугольник"){
            Hexagon tempHexagon(startPoint, endPoint, color);
            tempHexagon.draw(painter);
        }else if(selectedShape == "Ромб"){
            Rhomb tempRhomb(startPoint, endPoint, color);
            tempRhomb.draw(painter);
        }else if(selectedShape == "Квадрат"){
            Square tempSquare(startPoint, endPoint, color);
            tempSquare.draw(painter);
        }else if (selectedShape == "Круг") {
            Circle tempCircle(startPoint, endPoint, color);
            tempCircle.draw(painter);
        }else if (selectedShape == "Эллипс") {
            Ellipse tempEllipse(startPoint, endPoint, color);
            tempEllipse.draw(painter);
        }else if(selectedShape == "Восьмиконечная звезда"){
            Stars tempEightPStar(startPoint, endPoint, 8, color);
            tempEightPStar.draw(painter);
        }else if(selectedShape == "Пятиконечная звезда"){
            Stars tempEightPStar(startPoint, endPoint, 5, color);
            tempEightPStar.draw(painter);
        }else if(selectedShape == "Шестиконечная звезда"){
            Stars tempSixPStar(startPoint, endPoint, 6, color);
            tempSixPStar.draw(painter);
        }
    }
}
