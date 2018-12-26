#ifndef MATRICE_INPUT_H
#define MATRICE_INPUT_H
#include"../Parte_logica/matrice.h"
#include"../Parte_logica/square_matrice.h"
#include"../Parte_logica/scalar_matrice.h"
#include"../Parte_logica/vector.h"
#include "../Parte_logica/diagonal_matrice.h"
#include <QWidget>
#include <QTableWidget>
#include <QLabel>
#include <QString>

#include "tastiera.h"

class Tastiera;

class Matrice_Input : public QWidget
{
    Q_OBJECT
private:
    matrice<double>* mat;
    QTableWidget* tab;
    QLabel* det;
    QLabel* tipo;
    Tastiera* tast;
public:
    explicit Matrice_Input(int r, int c, QWidget* parent=nullptr);
    QString detText()const;
    QString tipoText()const;
    matrice<double>* getMat()const;
    void tabRes(int h,int l);
    static void warning(const QString& qs);

signals:

public slots:

    void rectify();
    void matResize(int r, int c);

    void plusRow();
    void minRow();
    void plusColumns();
    void minColumns();

    void upMat();
    void newMat(int r, int c);
    void model(QTableWidgetItem* item);

    void trasposta();
    void powX(double d);
    void norm();
    void scala();
};

#endif // MATRICE_INPUT_H
