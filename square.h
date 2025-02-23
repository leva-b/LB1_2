#ifndef SQUARE_H
#define SQUARE_H
#include <QColor>
#include <QPoint>
#include "rhomb.h"
class Square: public Rhomb
{
public:
    Square(QPoint& start, QPoint& end, QColor& color);
    void calculateVertices(const QPoint& start, const QPoint& end);
};

#endif // SQUARE_H
