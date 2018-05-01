/******************************************************************************
  \file display.cpp
  \author Yann Thoma
  \date 05.05.2011

  Fichier faisant partie du labo toboggan.
  ****************************************************************************/

#include "display.h"

#include <QPaintEvent>
#include <QPainter>

#include <QParallelAnimationGroup>
#include <QSequentialAnimationGroup>
#include <QPropertyAnimation>
#include <QEventLoop>
#include <QMutex>


#include <math.h>

#define RADIUS 250.0
#define SCENEOFFSET 0.0
#define STEPRADIUS 25.0
#define KIDWIDTH 30.0

#define VANWIDTH 50.0

#define NBKIDICONS 30

static TobogganDisplay* theDisplay;

KidItem::KidItem()
{

}

KidItem *getKid(unsigned int id)
{
    return theDisplay->getKid(id);
}

TobogganDisplay::TobogganDisplay(unsigned int nbStep,QWidget *parent):
    QGraphicsView(parent)
{
    theDisplay = this;
    m_stepPos=new QPointF[nbStep+1];
    for(unsigned int i=0;i<nbStep;i++)
    {
        m_stepPos[i]=
                QPointF(SCENEOFFSET+STEPRADIUS*i,
                        SCENEOFFSET-STEPRADIUS*(i+1)-10);
    }
    m_stepPos[nbStep]=
            QPointF(SCENEOFFSET+STEPRADIUS*nbStep*2,
                    SCENEOFFSET- STEPRADIUS - 10);
    m_scene=new QGraphicsScene(this);
    this->setRenderHints(QPainter::Antialiasing |
                         QPainter::SmoothPixmapTransform);
    this->setMinimumHeight(2*SCENEOFFSET+2*RADIUS+10.0);
    this->setMinimumWidth(2*SCENEOFFSET+2*RADIUS+10.0);
//    m_scene->setSceneRect(0,-nbStep * STEPRADIUS,2*SCENEOFFSET+2*RADIUS,0);
    this->setScene(m_scene);
    m_nbStep=nbStep;

    QPen pen;
    QBrush brush(QColor(100,255,100));
    QPolygonF path;
    path << QPointF(SCENEOFFSET,SCENEOFFSET);
    path << QPointF(SCENEOFFSET+STEPRADIUS,SCENEOFFSET);
    for(unsigned int i=1;i<nbStep;i++) {
        path << QPointF(SCENEOFFSET + i*STEPRADIUS,SCENEOFFSET - i*STEPRADIUS);
        path << QPointF(SCENEOFFSET + (i+1)*STEPRADIUS,SCENEOFFSET - i*STEPRADIUS);
    }
    path << QPointF(SCENEOFFSET+STEPRADIUS*nbStep*2,
                    SCENEOFFSET);
    m_scene->addPolygon(path,pen,brush);
}

TobogganDisplay::~TobogganDisplay()
{
    while (m_kids.size() > 0) {
        KidItem *p = m_kids.at(0);
        p->sem.release();
        m_kids.removeFirst();
        delete p;
    }
}

void TobogganDisplay::setKid(unsigned int step, unsigned int kidId)
{
    KidItem *kid = getKid(kidId);
    QPointF curPos = m_stepPos[step];
    float angle = rand();
    kid->setPos(curPos.x() + 40*cos(angle),curPos.y() + 40*sin(angle));
    kid->show();
}


KidItem *TobogganDisplay::getKid(unsigned int kidId)
{
    static QMutex mutex;
    mutex.lock();
    while ((unsigned int)(m_kids.size()) <= kidId)
    {
        QPixmap img(QString(":images/32x32/p%1.png").arg(m_kids.size() % NBKIDICONS));
        QPixmap kidPixmap;
        kidPixmap=img.scaledToWidth(KIDWIDTH);
        KidItem *kid=new KidItem();
        kid->setPixmap(kidPixmap);
        m_scene->addItem(kid);
        m_kids.append(kid);
        kid->hide();
    }
    mutex.unlock();
    return m_kids.at(kidId);
}


void TobogganDisplay::travel(unsigned int kidId, unsigned int step2, unsigned int ms)
{
    static QMutex mutex;
    mutex.lock();


    QParallelAnimationGroup *group=new QParallelAnimationGroup(this);

    {
        KidItem *kid=getKid(kidId);
        kid->arrivalStep = step2;
        kid->show();
        QPropertyAnimation *animation=new QPropertyAnimation(kid, "pos");
        animation->setDuration(ms-10);
        animation->setStartValue(kid->pos());
        animation->setEndValue(m_stepPos[step2]);
        if (kid->arrivalStep == m_nbStep)
            animation->setEasingCurve(QEasingCurve::InCubic);

        group->addAnimation(animation);
    }

    group->start();

    QObject::connect(group, SIGNAL(finished()), this,
                     SLOT(finishedAnimation()));

    mutex.unlock();
}

void TobogganDisplay::play(unsigned int kidId, unsigned int ms)
{
    unsigned int step1 = m_nbStep;
    unsigned int step2 = 0;
    static QMutex mutex;
    mutex.lock();


    QParallelAnimationGroup *group=new QParallelAnimationGroup(this);

    {
        KidItem *kid=getKid(kidId);
        kid->show();
        kid->arrivalStep = 0;

        QPropertyAnimation *animation=new QPropertyAnimation(kid, "pos");
        animation->setDuration(ms-10);
        animation->setStartValue(m_stepPos[step1]);

        QPointF curPos = m_stepPos[step2]+ QPointF(KIDWIDTH/2,KIDWIDTH*1.2);
        float angle = rand();
        curPos = QPointF(curPos.x() + 40*cos(angle),curPos.y() + abs(40*sin(angle)));


        animation->setEndValue(curPos);
        group->addAnimation(animation);
    }


    group->start();

    QObject::connect(group, SIGNAL(finished()), this,
                     SLOT(finishedAnimation()));

    mutex.unlock();
}

void TobogganDisplay::finishedAnimation()
{
    QAnimationGroup *group=dynamic_cast<QAnimationGroup*>(sender());
    for(int i=0;i<group->animationCount();i++) {
        QPropertyAnimation *animation=dynamic_cast<QPropertyAnimation*>(group->animationAt(i));
        KidItem *kid=dynamic_cast<KidItem*>(animation->targetObject());
        if (kid) {
            kid->sem.release();
        }
    }
    delete group;
}


