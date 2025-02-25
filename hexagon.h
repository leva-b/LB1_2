#ifndef HEXAGON_H
#define HEXAGON_H
#include <QPoint>
#include <QColor>
#include <QPainter>
#include "polygon.h"
class Hexagon: public Polygon
{
public:
    explicit Hexagon(const QPoint& start, const QPoint& end, const QColor& color);
    void draw(QPainter& painter) override;
    double area() const override;
private:
    QVector<QPoint> calculateVertices(const QPoint& start, const QPoint& end);
    void scale(double factor, const QPoint& center) override;
};

#endif // HEXAGON_H
