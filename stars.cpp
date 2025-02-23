#include "stars.h"
#include <QPainter>
#include "polygon.h"
#include <QPoint>

Stars::Stars(const QPoint& startPosition, const QPoint& end, int rays, const QColor& color)
    :Polygon(calculateVertices(startPosition, end, rays), color), numRays(rays)
{
    position = startPosition;
}

QVector<QPoint> Stars::calculateVertices(const QPoint& start, const QPoint& end,int rays)
{
    innerR = std::hypot(end.x() - start.x(), end.y() - start.y());
    outerR = innerR*2;
    QVector<QPoint> vertices;
    double angleStep = 2 * M_PI / rays;
    double offset = -M_PI / 2;
    for (int i = 0; i < rays; ++i) {
        // Внешняя точка
        double outerAngle = i * angleStep + offset;
        int outerX = static_cast<int>(start.x() + outerR * cos(outerAngle));
        int outerY = static_cast<int>(start.y() + outerR * sin(outerAngle));
        vertices << QPoint(outerX, outerY);

        // Внутренняя точка
        double innerAngle = outerAngle + angleStep / 2;
        int innerX = static_cast<int>(start.x() + innerR * cos(innerAngle));
        int innerY = static_cast<int>(start.y() + innerR * sin(innerAngle));
        vertices << QPoint(innerX, innerY);
    }
    return vertices;
}

void Stars::draw(QPainter& painter){
    QPolygon polygon(vertices);
    painter.drawPolygon(polygon);
}

double Stars::area()const{
    double result = 0.0;
    return result;
}
