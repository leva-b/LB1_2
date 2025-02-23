#ifndef RHOMB_H
#define RHOMB_H
#include "polygon.h"

class Rhomb: public Polygon
{
public:
    Rhomb(const QPoint& start, const QPoint& end, const QColor& color = Qt::blue);
    void draw(QPainter& painter) override;
private:
    double area() const override;
    QVector<QPoint> calculateVertices(const QPoint& start, const QPoint& end);
};

#endif // RHOMB_H
