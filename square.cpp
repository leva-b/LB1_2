#include "square.h"
#include <QPoint>
#include <QColor>

Square::Square(QPoint& start, QPoint& end, QColor& color):
    Rhomb(start, end, color){
    calculateVertices(start, end);
}

void Square::calculateVertices(const QPoint& start, const QPoint& end) {
    vertices.clear();
    //this->vertices.push_back(start);
    int sideLength = std::max(abs(start.x() - end.x()), abs(start.y() - end.y()));

    int centerX = (start.x() + end.x()) / 2;
    int centerY = (start.y() + end.y()) / 2;


    vertices.push_back(QPoint(centerX - sideLength / 2, centerY - sideLength / 2)); // верхний левый
    vertices.push_back(QPoint(centerX + sideLength / 2, centerY - sideLength / 2)); // верхний правый
    vertices.push_back(QPoint(centerX + sideLength / 2, centerY + sideLength / 2)); // нижний правый
    vertices.push_back(QPoint(centerX - sideLength / 2, centerY + sideLength / 2)); // нижний левый


}


