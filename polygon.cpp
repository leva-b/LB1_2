#include "polygon.h"
#include <QWidget>
#include <QPoint>

Polygon::Polygon(const QVector<QPoint>& vertices, const QColor& color)
    : Shap(color), vertices(vertices) {
    this->originalColor = color;
}

double Polygon::perimeter() const {
    double perimeter = 0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        const QPoint& p1 = vertices[i];
        const QPoint& p2 = vertices[(i + 1) % n];
        perimeter += std::hypot(p2.x() - p1.x(), p2.y() - p1.y());
    }
    return perimeter;
}

void Polygon::move(const QPoint& offset) {
    for (QPoint& vertex : vertices) {
        vertex += offset;
    }
    position += offset;
}

void Polygon::rotate(double angle, const QPoint& center) {
    double rad = angle * M_PI / 180;
    double cosA = std::cos(rad);
    double sinA = std::sin(rad);

    for (QPoint& vertex : vertices) {
        QPoint relative = vertex - center;
        vertex.setX(center.x() + relative.x() * cosA - relative.y() * sinA);
        vertex.setY(center.y() + relative.x() * sinA + relative.y() * cosA);
    }
}

void Polygon::scale(double factor, const QPoint& center) {
    for (QPoint& vertex : vertices) {
        QPoint relative = vertex - center;
        vertex = center + relative * factor;
    }
}


bool Polygon::contains(const QPoint &point) const{
    QPolygon polygon(vertices);
    qDebug() << "point:" << point << "rectangle:";

    // if(polygon.contains(point))
    //     return true;
    // else
    //     return false;
    return polygon.containsPoint(point, Qt::OddEvenFill);
}
