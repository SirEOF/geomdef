//////////////////////////////////////////////////////////////////////////////////
/// \file rotateo.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy rotate - okna dialogowego
///////////////////////////////////////////////////////////////////////////////////


#ifndef ROTATEO_H
#define ROTATEO_H

#include <QtGui>
#include <QDialog>

/////////////////////////////////////////////////////////////////////////
/// \namespace Ui
/// Przestrzen nazw Ui
/////////////////////////////////////////////////////////////////////////
namespace Ui {
    class rotateo;
}
class AxisRotate;

/////////////////////////////////////////////////////////////////////////
/// \class rotateo
/// Klasa oodpowiedzialna za glowne okno programu. Dziedzicy po QMainWindow.
/////////////////////////////////////////////////////////////////////////
class rotateo : public QDialog {
    Q_OBJECT
public:

    /**
      *  Konstruktor
      * \brief Konstruktor rotateo
      * \param parent wska�nik do rodzica typu QWidget.
      */
       rotateo(QImage* img,QWidget *parent = 0);

       /**
         * Destruktor
         */
    ~rotateo();

protected:
    void changeEvent(QEvent *e);

private:
    Ui::rotateo *ui;
     QGraphicsScene *scene;
     AxisRotate *rimg;
     void clearScene();

private slots:
    void on_pushButton_3_clicked();
    void on_dial_3_valueChanged(int value);
    void on_dial_2_valueChanged(int value);
    void on_dial_valueChanged(int value);
    void on_pushButton_clicked();

signals:
    void CloseSignalOK(int x, int y, int z);
     void CloseSignalCancel();
};

#endif // ROTATEO_H