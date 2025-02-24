#ifndef INFOWIDGET_H
#define INFOWIDGET_H
#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class InfoWidget : public QWidget {
    Q_OBJECT

public:
    InfoWidget(QWidget *parent = nullptr);

public slots:
    void updateCoordinates();

private:
    QLabel *areaLabel;
    QLabel *perimeterLabel;
    QLabel *coordinatesLabel;
    QLineEdit *xInput;
    QLineEdit *yInput;
    QPushButton *updateButton;
};


#endif // INFOWIDGET_H
