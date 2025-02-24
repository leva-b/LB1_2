#include "circle.h"
#include <QPainter>
#include <QPainterPath>
Circle::Circle(QPoint& start, QPoint& end, QColor& color) {
    radius = std::hypot(start.x() - end.x(), start.y() - end.y());
    this->color = color;
    this->originalColor = color;
    startPoint = start;
    endPoint = end;
    position = startPoint;
}

double Circle::area() const{
    return radius*radius*pi;
}

double Circle::perimeter() const{
    return 2*pi*radius;
}

void Circle::draw(QPainter& painter){
    painter.setPen(QPen(color,3));
    painter.drawEllipse(position.x() - radius, position.y() - radius, radius*2, radius*2);
}

void Circle::move(const QPoint& offset) {
    //startPoint = startPoint + offset;
    position = position + offset;
}
void Circle::scale(double factor, const QPoint& center){}

bool Circle::contains(const QPoint &point) const {

    QPainterPath path;
    path.addEllipse(position, radius, radius);

    return path.contains(point);
}
