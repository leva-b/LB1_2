#include "hexagon.h"
#include <QPolygon>

Hexagon::Hexagon(const QPoint& start, const QPoint& end, const QColor& color): Polygon(calculateVertices(start,end), color)
{
    position = start;
    startPoint = start;
    endPoint = end;
}

QVector<QPoint> Hexagon::calculateVertices(const QPoint& start, const QPoint& end)
{
    QVector<QPoint> vertices;

    QPoint center(start);

    double radius = QLineF(start, end).length();

    for (int i = 0; i < 6; ++i) {
        double angle = 2 * M_PI * i / 6; // угол для вершины
        int x = center.x() + radius * cos(angle);
        int y = center.y() + radius * sin(angle);
        vertices.push_back(QPoint(x, y));
    }

    return vertices;
}

void Hexagon::draw(QPainter& painter) {
    painter.setPen(QPen(color, 3));
    QPolygon polygon;
    for(const QPoint& vertice: vertices){
        polygon << (vertice - position)*scaleFactor + position;
    }
    painter.drawPolygon(polygon);
}

double Hexagon::area() const{
    double result = 0;
    for(int i = 0; i < vertices.size(); i++){
        result += TriangleArea(position, vertices[i], vertices[(i+1)%vertices.size()]);
    }
    return result*scaleFactor*scaleFactor;
}

void Hexagon::scale(double factor, const QPoint& center){
    Q_UNUSED(center);
    if(scaleFactor * factor > 10)scaleFactor = 10;
    else if(scaleFactor * factor < 0.1)scaleFactor = 0.1;
    else scaleFactor *= factor;
}
