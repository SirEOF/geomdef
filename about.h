//////////////////////////////////////////////////////////////////////////////////
/// \file about.h
/// \author Grzegorz Kurek
/// \author grzesiek.kurek@gmail.com
/// \version 1.0.1
/// \date 20-01-2010
/// \brief Deklaracja klasy about - okna wyswietlającego informacje o programie. Plik naglowkowy.
///////////////////////////////////////////////////////////////////////////////////

#ifndef ABOUT_H
#define ABOUT_H

#include <QDialog>

/////////////////////////////////////////////////////////////////////////
/// \namespace Ui
/// \brief Przestrzen nazw Ui
/////////////////////////////////////////////////////////////////////////
namespace Ui {
    class about;
}


/////////////////////////////////////////////////////////////////////////
/// \class about
/// \brief Klasa oodpowiedzialna za glowne okno programu. Dziedzicy po QDialog.
/////////////////////////////////////////////////////////////////////////
class about : public QDialog {
    Q_OBJECT

public:
    ////////////////////////////////////////////////////////////////////////////////
    /// about
    /// \brief Konstruktor przyjmujacy jako parmetr rodzica QWidget.
    /// \param parent Parametr domniemany. Wskaźnik do rodzica typu QWidget.
    ////////////////////////////////////////////////////////////////////////////////
    about(QWidget *parent = 0);

    /////////////////////////////////////////////////////////////////////////
    /// Destruktor.
    /////////////////////////////////////////////////////////////////////////
    ~about();

protected:
    ////////////////////////////////////////////////////////////////////////////////
    // blabla
    ////////////////////////////////////////////////////////////////////////////////
    void changeEvent(QEvent *e);

private:
    ////////////////////////////////////////////////////////////////////////////////
    // wskaznik do obiektu about
    ////////////////////////////////////////////////////////////////////////////////
    Ui::about *ui;

private slots:
    ////////////////////////////////////////////////////////////////////////////////
    // slot do zamnkniecia okna
    ////////////////////////////////////////////////////////////////////////////////
    void on_pushButton_clicked();
};

#endif // ABOUT_H
