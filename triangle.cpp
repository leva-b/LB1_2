#include "triangle.h"
#include <QPainter>
#include <QPolygon>

Triangle::Triangle(const QPoint& point1, const QPoint& point2, const QPoint& point3, const QColor& color):
    Polygon({point1, point2, point3}, color){
    if(point1.y() < point2.y())
        position = QPoint(point1.x(), (point2.y()-point1.y())*2/3+point1.y());
    else
        position = QPoint(point1.x(), (point1.y()-point2.y())/3 + point2.y());
}


double Triangle::area() const {
    double p = this->perimeter()/2/scaleFactor;
    double result = scaleFactor*scaleFactor*sqrt(p*(p - std::hypot(vertices[0].x() - vertices[1].x(),vertices[0].y() - vertices[1].y()))*
                         (p - std::hypot(vertices[1].x() - vertices[2].x(),vertices[1].y() - vertices[2].y()))*
                         (p - std::hypot(vertices[2].x() - vertices[0].x(),vertices[2].y() - vertices[0].y())));
    return result;
}

void Triangle::draw(QPainter& painter) {
    painter.setPen(QPen(color, 3));

    QPolygon polygon;
    for(const QPoint& vertice: vertices){
        polygon << (vertice - position)*scaleFactor + position;
    }
    painter.drawPolygon(polygon);
}

void Triangle::scale(double factor, const QPoint& center){
    Q_UNUSED(center);
    if(scaleFactor * factor > 10)scaleFactor = 10;
    else if(scaleFactor * factor < 0.1)scaleFactor = 0.1;
    else scaleFactor *= factor;
}
