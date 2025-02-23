    #ifndef POLYGON_H
#define POLYGON_H
#include "shap.h"

class Polygon: public Shap
{
    Q_OBJECT
public:
    Polygon(const QVector<QPoint>& vertices, const QColor& color = Qt::blue);

protected:
    QVector<QPoint> vertices;
    void move(const QPoint& offset) override;
    double perimeter() const override;
    void rotate(double angle, const QPoint& center) override;
    void scale(double factor, const QPoint& center) override;
    void draw(QPainter& painter) override = 0;
};

#endif // POLYGON_H
