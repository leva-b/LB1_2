#include "ellipse.h"
#include <QPainter>
#include <QPainterPath>

Ellipse::Ellipse(QPoint& start, QPoint& end, QColor& color){
    startPoint = start;
    endPoint = end;
    position = QPoint(startPoint.x() - R1, startPoint.y() - R2);
    R1 = startPoint.x() - endPoint.x();
    R2 = startPoint.y() - endPoint.y();
    this->color = color;
    this->originalColor = color;
}

double Ellipse::area() const {
    return pi*R1*R2;
}

double Ellipse::perimeter() const {
    return pi*(3*(R1 + R2) - sqrt((3*R1 + R2)*(3*R2 + R1)));
}

void Ellipse::draw(QPainter& painter){
    painter.setPen(QPen(color,3));
    painter.drawEllipse(startPoint.x() - R1, startPoint.y() - R2, 2*R1, 2*R2);
}

void Ellipse::move(const QPoint& offset) {
    startPoint = startPoint + offset;
    position = position + offset;
}
void Ellipse::rotate(double angle, const QPoint& pivot){Q_UNUSED(pivot); Q_UNUSED(angle)}
void Ellipse::scale(double factor, const QPoint& center){}

bool Ellipse::contains(const QPoint &point) const {

    QPainterPath path;
    path.addEllipse(position, R1, R2);

    return path.contains(point);
}
