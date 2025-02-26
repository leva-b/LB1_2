#include "rhomb.h"
#include <QPainter>
Rhomb::Rhomb(const QPoint& start, const QPoint& end, const QColor& color):
    Polygon(calculateVertices(start, end), color){
    position = QPoint(start.x(), end.y());
}

void Rhomb::draw(QPainter& painter)
{

    painter.setPen(QPen(color, 3));
    painter.setBrush(Qt::NoBrush);
    QPolygon polygon;
    for(int i = 0; i < 4; i++)
        polygon << (vertices[i]- position)*scaleFactor + position;
    painter.drawPolygon(polygon);
}


double Rhomb::area() const{
    double result = std::hypot(vertices[0].x() - vertices[2].x(), vertices[0].y() - vertices[2].y())
                   *std::hypot(vertices[1].x() - vertices[3].x(), vertices[1].y() - vertices[3].y())/2;
    return result*scaleFactor*scaleFactor;
}

QVector<QPoint> Rhomb::calculateVertices(const QPoint& start, const QPoint& end){
    return QVector<QPoint>{start, end, QPoint(start.x(), end.y() - start.y() + end.y()), QPoint(2*start.x() - end.x(), end.y())};
}

void Rhomb::scale(double factor, const QPoint& center){
    Q_UNUSED(center);
    if(scaleFactor * factor > 10)scaleFactor = 10;
    else if(scaleFactor * factor < 0.1)scaleFactor = 0.1;
    else scaleFactor *= factor;
}
