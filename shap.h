#ifndef SHAP_H
#define SHAP_H
#include <QWidget>

class Shap: public QWidget
{
    Q_OBJECT
protected:
    Shap(const QPoint& center);
    Shap() = default;
    Shap(const QColor& color) {
        this->color = color;
    }

    static double pi;
    QColor color;
    QPoint position;
    double rotation = 0;
    double scaleFactor = 1;

    QPoint startPoint;
    QPoint endPoint;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;


    virtual void move(const QPoint& offset) = 0;
    virtual void rotate(double angle, const QPoint& pivot) = 0;
    virtual void scale(double factor, const QPoint& center) = 0;

    void setColor(const QColor& color);
    QColor getColor() const;

public:
    virtual void draw(QPainter& painter) = 0;
};



#endif // SHAP_H
