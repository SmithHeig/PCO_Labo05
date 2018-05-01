/******************************************************************************
  \file display.h
  \author Yann Thoma
  \date 05.05.2011

  Fichier faisant partie du labo toboggan.
  ****************************************************************************/

#ifndef DISPLAY_H
#define DISPLAY_H

#include <QGraphicsView>
#include <QGraphicsItem>
#include <QSemaphore>


class KidItem :  public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
    Q_PROPERTY(QPointF pos READ pos WRITE setPos)
public:
    KidItem();

    unsigned int arrivalStep;
    QSemaphore sem;


};

KidItem *getKid(unsigned int kidId);


class TobogganDisplay : public QGraphicsView
{
    Q_OBJECT
public:
    TobogganDisplay(unsigned int nbStep,QWidget *parent=0);
    ~TobogganDisplay();
    unsigned int m_nbStep;
    QPointF *m_stepPos;
    KidItem *getKid(unsigned int kidId);
private:
    QGraphicsScene *m_scene;
    QList<KidItem *> m_kids;


public slots:
    void setKid(unsigned int step, unsigned int kidId);
    void travel(unsigned int KidId, unsigned int step2, unsigned int ms);
    void play(unsigned int KidId, unsigned int ms);
    void finishedAnimation();
};

#endif // DISPLAY_H
