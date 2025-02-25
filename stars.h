#ifndef STARS_H
#define STARS_H

#include "polygon.h"
class Stars: public Polygon
{
public:
    Stars(const QPoint& startPosition, const QPoint& end, int rays, const QColor& color);
    void draw(QPainter &painter) override;
    double area() const override;
    void scale(double factor, const QPoint& center) override;


private:
    int numRays;       // количество лучей
    double innerR;     // внутренний радиус
    double outerR;

    QVector<QPoint> calculateVertices(const QPoint& start);
    QVector<QPoint> calculateVertices(const QPoint& start,const QPoint& end, int rays);
};

#endif // STARS_H
