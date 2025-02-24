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
        double angle = 2 * M_PI * i / 6; // Угол для каждой вершины
        int x = center.x() + radius * cos(angle);
        int y = center.y() + radius * sin(angle);
        vertices.push_back(QPoint(x, y));
    }

    return vertices;
}

void Hexagon::draw(QPainter& painter) {
    painter.setPen(QPen(color, 3));
    QPolygon polygon(vertices);
    painter.drawPolygon(polygon);
}

double Hexagon::area() const{
    double result;
    return result;
}
