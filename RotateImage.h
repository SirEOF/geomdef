//////////////////////////////////////////////////////////////////////////////////
/// \file RotateImage.h
/// \author Daniel Matras
/// \author 7matras@novell.ftj.agh.edu.pl
/// \version 1.0.1
/// \date 16-01-2010
/// \brief Deklaracja klasy RotatedImage sluzacej do obrotu obrazu wokol.
/// \brief dowolnej osi prostopadłej do płaszczyzny rejestrującej. Plik naglowkowy.
///////////////////////////////////////////////////////////////////////////////////

#ifndef ROTATEIMAGE_H
#define ROTATEIMAGE_H

#include <QObject>
#include <QGenericMatrix>
#include <QImage>

//////////////////////////////////////////////////////////////////////////////////////
/// \class RotateImage
/// \brief Klasa definujaca obrot obrazu. Dziedzyczy po klasie QObject oraz Transform.
//////////////////////////////////////////////////////////////////////////////////////
class RotateImage : public QObject
{
    Q_OBJECT

public:
    ////////////////////////////////////////////////////////////////////////////////
    /// RotateImage
    /// \brief Konstruktor przyjmujacy jako parmetry obraz oraz rodzica QWidget.
    /// \param im obraz przyjmowany jest jako referencja do QImage.
    /// \param parent Parametr domniemany. Wskaźnik do rodzica typu QWidget.
    ////////////////////////////////////////////////////////////////////////////////
    RotateImage(const QImage &im,QWidget *parent = 0);

    ///////////////////////////////////////////////////////////////////////////////
    /// Destruktor.
    //////////////////////////////////////////////////////////////////////////////
    ~RotateImage();

    ////////////////////////////////////////////////////////////////////////////////
    /// rotateCutBackground
    /// \brief Metoda rotateCutBackground odpowiad za obrot i obcinanie nadmiarowego tla.
    /// \param alpha kat obrotu.
    /// \return zwraca obrocony obraz. Obiekt typu QImage.
    ////////////////////////////////////////////////////////////////////////////////
    QImage rotateCutBackground(const qreal alpha);

    ////////////////////////////////////////////////////////////////////////////////
    /// rotateAnyPoint
    /// \brief Metoda rotateAnyPoint odpowiad za obrot wokol dowolnego punktu.
    /// \param alpha kat obrotu.
    /// \param x wspolrzedna x-owa punktu.
    /// \param y wspolrzedna y-owa punktu.
    /// \param w szerokosc obrazka.
    /// \param h wysokosc obrazka.
    /// \return zwraca obrocony obraz. Obiekt typu QImage.
    ////////////////////////////////////////////////////////////////////////////////
    QImage rotateAnyPoint(const qreal alpha, const qreal x, const qreal y, const int w, const int h);

private:
    ////////////////////////////////////////////////////////////////////////////////
    // macierze obrotu i przesuniecia
    ////////////////////////////////////////////////////////////////////////////////
    QMatrix3x3 matrix,move;

    ////////////////////////////////////////////////////////////////////////////////
    // wektory punktow
    ////////////////////////////////////////////////////////////////////////////////
    QGenericMatrix<1,3,qreal> vector,result;

    ////////////////////////////////////////////////////////////////////////////////
    // wektor pixela  vec*matrix
    ////////////////////////////////////////////////////////////////////////////////
    qreal *rawVec;

    ////////////////////////////////////////////////////////////////////////////////
    // wskazniki do pixela obrazka
    ////////////////////////////////////////////////////////////////////////////////
    qreal *rawResult;

    ////////////////////////////////////////////////////////////////////////////////
    // obrazek obrocony
    ////////////////////////////////////////////////////////////////////////////////
    QImage rotatedImage;

    ////////////////////////////////////////////////////////////////////////////////
    // obrazek wejsciowy
    ////////////////////////////////////////////////////////////////////////////////
    QImage image;

    ////////////////////////////////////////////////////////////////////////////////
    // wskaznik do pierwszego pixela obrazka wjesciowego
    ////////////////////////////////////////////////////////////////////////////////
    const uchar *imageData;

    ////////////////////////////////////////////////////////////////////////////////
    // szerokosc i wysokosc obrazka
    ////////////////////////////////////////////////////////////////////////////////
    const int w,h;

};

#endif // ROTATEIMAGE_H
