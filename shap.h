#ifndef SHAP_H
#define SHAP_H
#include <QWidget>

class Shap: public QWidget
{
    Q_OBJECT
    bool selectedShape = false;
protected:
    Shap(const QPoint& center);
    Shap() = default;
    Shap(const QColor& color) {
        this->color = color;
    }

    static double pi;

    QColor color;
    QColor originalColor;
    QPoint position;
    double rotation = 0;
    double scaleFactor = 1;

    QPoint startPoint;
    QPoint endPoint;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;

    virtual void rotate(double angle, const QPoint& pivot) = 0;
    virtual void scale(double factor, const QPoint& center) = 0;

    public:
    virtual void move(const QPoint& offset) = 0;
    void changeSelection() {
        selectedShape = !selectedShape;
        if (selectedShape) {
            color = Qt::green;
        } else {
            color = originalColor;
        }
    }
    QColor getColor() const{
        return color;
    }
    void setColor(const QColor& color){
        this->color = color;
    }
    void setOriginalColor(const QColor &originalColor) {
        this->originalColor = originalColor;
    }

    QColor getOriginalColor() const {
        return originalColor;
    }

    virtual QPoint center() const{
        return position;
    }
    virtual bool contains(const QPoint &point) const = 0;

    virtual void draw(QPainter& painter) = 0;
};



#endif // SHAP_H
