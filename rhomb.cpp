#include "rhomb.h"
#include <QPainter>
Rhomb::Rhomb(const QPoint& start, const QPoint& end, const QColor& color):
    Polygon(calculateVertices(start, end), color){}

void Rhomb::draw(QPainter& painter)
{
    painter.setPen(QPen(color, 3));
    painter.setBrush(Qt::NoBrush);
    QPolygon polygon;
    for(int i = 0; i < 4; i++)
        polygon << vertices[i];
    painter.drawPolygon(polygon);
}

double Rhomb::area() const{
    return 1;
}

QVector<QPoint> Rhomb::calculateVertices(const QPoint& start, const QPoint& end){
    return QVector<QPoint>{start, end, QPoint(start.x(), end.y() - start.y() + end.y()), QPoint(2*start.x() - end.x(), end.y())};
}
