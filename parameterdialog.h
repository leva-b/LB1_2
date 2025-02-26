#ifndef PARAMETERDIALOG_H
#define PARAMETERDIALOG_H
#include <QDialog>
#include <QVBoxLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
class ParameterDialog : public QDialog {
    Q_OBJECT

public:
    ParameterDialog(const QStringList &labels, const QList<double> &initialValues, QWidget *parent = nullptr);
    ParameterDialog(const QStringList &labels, const QList<QPoint> &initialVertices, QWidget *parent = nullptr);
    QList<double> values() const;
    QComboBox *pointSelector; // Селектор для выбора номера точки

private slots:
    void updateCoordinates(int index); // Слот для обновления координат

private:
    QList<QLineEdit*> inputs;
    QList<QPoint> vertices; // Координаты вершин
};

#endif // PARAMETERDIALOG_H
