#include "ellipse.h"
#include <QPainter>
#include <QPainterPath>

Ellipse::Ellipse(QPoint& start, QPoint& end, QColor& color){
    startPoint = start;
    endPoint = end;
    position = startPoint;
    R1 = startPoint.x() - endPoint.x();
    R2 = startPoint.y() - endPoint.y();
    this->color = color;
    this->originalColor = color;
}

double Ellipse::area() const {
    return pi*R1*R2*scaleFactor*scaleFactor;
}

double Ellipse::perimeter() const {
    int R1 = this->R1*scaleFactor;
    int R2 = this->R2*scaleFactor;
    return pi*(3*(std::abs(R1) + std::abs(R2)) - sqrt((3*std::abs(R1) + std::abs(R2))*(3*std::abs(R2) + std::abs(R1))));
}

void Ellipse::draw(QPainter& painter){
    painter.setPen(QPen(color,3));
    painter.drawEllipse(startPoint.x() - R1*scaleFactor, startPoint.y() - R2*scaleFactor, 2*R1*scaleFactor, 2*R2*scaleFactor);
}

void Ellipse::move(const QPoint& offset) {
    startPoint = startPoint + offset;
    position = position + offset;
}

void Ellipse::scale(double factor, const QPoint& center){
    if(scaleFactor * factor > 10)scaleFactor = 10;
    else if(scaleFactor * factor < 0.1)scaleFactor = 0.1;
    else scaleFactor *= factor;
}

bool Ellipse::contains(const QPoint &point) const {
     qDebug() << "point:" << point << "position:" << position;
    QPainterPath path;
    path.addEllipse(position, R1*scaleFactor, R2*scaleFactor);

    return path.contains(point);
}
