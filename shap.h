#ifndef SHAP_H
#define SHAP_H
#include <QWidget>
#include <QLabel>
#include <QPainter>
#include <QLineEdit>
class Shap: public QWidget
{
    Q_OBJECT
    bool selectedShape = false;


    QLineEdit* CMx = nullptr;
    QLineEdit* CMy = nullptr;
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


public:
    virtual void rotate(double angle) = 0;
    virtual void scale(double factor, const QPoint& center) = 0;
    void updatePositionFromText() {
        bool okX, okY;
        int x = CMx->text().toInt(&okX);
        int y = CMy->text().toInt(&okY);
        if (okX && okY) {
            position = QPoint(x, y);
            update();
        }
    }

    void updatePosition(const QPoint& newPosition) {
        position = newPosition; // Обновляем позицию фигуры
        update(); // Перерисовываем фигуру
    }

    void showInformation(QPainter& painter, int height) {
        // Отображение периметра и площади
        painter.setPen(Qt::red);
        QRect rect(20, height - 43, 100, 20);
        painter.drawText(rect, Qt::AlignLeft, QString("P: ") + QString::number(this->perimeter(), 'f', 2));

        QRect rect2(20, height - 22, 100, 20);
        painter.drawText(rect2, Qt::AlignLeft, QString("S: ") + QString::number(this->area(), 'f', 2));

    }
    //virtual void showMoreInformation() override = 0;

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
