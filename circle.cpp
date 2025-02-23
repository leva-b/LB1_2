#include "circle.h"
#include <QPainter>

Circle::Circle(QPoint& start, QPoint& end, QColor& color) {
    radius = std::hypot(start.x() - end.x(), start.y() - end.y());
    this->color = color;
    startPoint = start;
    endPoint = end;
}

double Circle::area() const{
    return radius*radius*pi;
}

double Circle::perimeter() const{
    return 2*pi*radius;
}

void Circle::draw(QPainter& painter){
    painter.drawEllipse(startPoint.x() - radius, startPoint.y() - radius, radius*2, radius*2);
}

void Circle::move(const QPoint& offset) {}
void Circle::scale(double factor, const QPoint& center){}
