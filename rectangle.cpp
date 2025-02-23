#include "rectangle.h"

Rectangle::Rectangle(const QPoint& topLeft, const QPoint& bottomRight, const QColor& color)
    : Polygon({topLeft, QPoint(bottomRight.x(), topLeft.y()), bottomRight, QPoint(topLeft.x(), bottomRight.y())}, color) {}

double Rectangle::area() const {
    double result = std::abs((vertices[1].x() - vertices[0].x())* (vertices[2].y() - vertices[1].y()));
    return result;
}

void Rectangle::draw(QPainter& painter) {
    painter.setPen(QPen(color, 3));
    painter.setBrush(Qt::NoBrush);
    painter.drawRect(QRect(vertices[0], vertices[2]));
}
