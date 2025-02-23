    #include "triangle.h"
#include <QPainter>
#include <QPolygon>

Triangle::Triangle(const QPoint& point1, const QPoint& point2, const QPoint& point3, const QColor& color):
    Polygon({point1, point2, point3}, color){}


double Triangle::area() const {
    double p = this->perimeter();
    double result = sqrt(p*(p - std::hypot(vertices[0].x() - vertices[1].x(),vertices[0].x() - vertices[1].x()))*
                         (p - std::hypot(vertices[1].x() - vertices[2].x(),vertices[0].x() - vertices[2].x()))*
                         (p - std::hypot(vertices[2].x() - vertices[0].x(),vertices[2].x() - vertices[0].x())));
    return result;
}

void Triangle::draw(QPainter& painter) {
    painter.setPen(QPen(color, 3));

    QPolygon polygon(vertices);
    painter.drawPolygon(polygon);
}
