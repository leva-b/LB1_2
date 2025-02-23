#ifndef CANVAS_H
#define CANVAS_H
#include <QWidget>
#include <QComboBox>
#include "shap.h"
class Canvas: public QWidget
{
protected:
    void mousePressEvent(QMouseEvent *event) override;
    void mouseMoveEvent(QMouseEvent *event) override;
    void mouseReleaseEvent(QMouseEvent *event) override;
    void paintEvent(QPaintEvent *event) override;
public:
    Canvas(QWidget *parent = nullptr);

    void setColor(const QColor &newColor);
    void clear();
private:
    bool drawing;
    QPoint startPoint;
    QPoint endPoint;
    QColor color;

    QComboBox *shapeComboBox;
    QList<Shap*> shapes;
private slots:
    void chooseColor();

};

#endif // CANVAS_H
