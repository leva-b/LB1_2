#ifndef CIRCLE_H
#define CIRCLE_H
#include <shap.h>
class Circle: public Shap
{
    double radius;
    bool contains(const QPoint &point) const override;
public:
    void draw(QPainter& painter) override;
    Circle(QPoint& start, QPoint& end, QColor& color);
    double area() const override;
    double perimeter() const override;
    void move(const QPoint& offset) override;
    void rotate(double angle, const QPoint& pivot) override {Q_UNUSED(angle) Q_UNUSED(pivot)};
    void scale(double factor, const QPoint& center) override;
};

#endif // CIRCLE_H
