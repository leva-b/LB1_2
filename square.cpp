#include "square.h"
#include <QPoint>
#include <QColor>

Square::Square(QPoint& start, QPoint& end, QColor& color):
    Rhomb(start, end, color){
    calculateVertices(start, end);
    position = start;
}

void Square::calculateVertices(const QPoint& start, const QPoint& end) {
    vertices.clear();
    //this->vertices.push_back(start);
    int sideLength = std::max(abs(start.x() - end.x()), abs(start.y() - end.y()));

    int centerX = start.x();
    int centerY = start.y();

    vertices.push_back(QPoint(centerX - sideLength, centerY - sideLength));
    vertices.push_back(QPoint(centerX + sideLength, centerY - sideLength));
    vertices.push_back(QPoint(centerX + sideLength, centerY + sideLength));
    vertices.push_back(QPoint(centerX - sideLength, centerY + sideLength));
}
