#include "triangle.h"
#include <QPainter>
#include <QPolygon>

Triangle::Triangle(const QPoint& point1, const QPoint& point2, const QPoint& point3, const QColor& color):
    Polygon({point1, point2, point3}, color){}


double Triangle::area() const {
    return 1;
}

void Triangle::draw(QPainter& painter) {
    painter.setPen(QPen(color, 3));

    QPolygon polygon(vertices);
    painter.drawPolygon(polygon);
}
