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
    return radius*scaleFactor*scaleFactor*radius*pi;
}

double Circle::perimeter() const{
    return 2*pi*radius*scaleFactor;
}

void Circle::draw(QPainter& painter){
    painter.setPen(QPen(color,3));
    painter.drawEllipse(position.x() - radius*scaleFactor, position.y() - radius*scaleFactor, radius*2*scaleFactor, radius*2*scaleFactor);
}

void Circle::move(const QPoint& offset) {
    //startPoint = startPoint + offset;
    position = position + offset;
}
void Circle::scale(double factor, const QPoint& center){
    Q_UNUSED(center);
    if(scaleFactor * factor > 10)scaleFactor = 10;
    else if(scaleFactor * factor < 0.1)scaleFactor = 0.1;
    else scaleFactor *= factor;
}

bool Circle::contains(const QPoint &point) const {
    qDebug() << "point:" << point << "position:" << position;
    QPainterPath path;
    path.addEllipse(position, radius*scaleFactor, radius*scaleFactor);

    return path.contains(point);
}
