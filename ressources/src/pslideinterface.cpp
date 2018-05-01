#include <iostream>
#include <stdlib.h>

using namespace std;

#include "pslideinterface.h"
#include "display.h"
#include <QMessageBox>
#include <QThread>

bool PSlideInterface::sm_didInitialize   = false;
MainWindow *PSlideInterface::mainWindow  = 0;
unsigned int PSlideInterface::sm_nbSteps = 0;

PSlideInterface::PSlideInterface()
{
    if (!sm_didInitialize) {
        cout << "Vous devez appeler PSlideInterface::initialize()" << endl;
        QMessageBox::warning(0,"Erreur","Vous devez appeler "
                             "PSlideInterface::initialize() avant de créer un "
                             "objet PSlideInterface");
        exit(-1);
    }

    QObject::connect(this,
                     SIGNAL(sig_consoleAppendText(unsigned int,QString)),
                     mainWindow,
                     SLOT(consoleAppendText(unsigned int,QString)));
    QObject::connect(this,
                     SIGNAL(sig_travel(unsigned int,unsigned int,unsigned int)),
                     mainWindow,
                     SLOT(travel(unsigned int,unsigned int,unsigned int)));
    QObject::connect(this,
                     SIGNAL(sig_play(uint,uint)),
                     mainWindow,
                     SLOT(play(unsigned int,unsigned int)));

}


unsigned int PSlideInterface::nbSteps()
{
    return sm_nbSteps;
}

#include <QTest>

void PSlideInterface::travel(unsigned int KidId, unsigned int step2,
                             unsigned int ms)
{
    emit sig_travel(KidId,step2,ms);
    getKid(KidId)->sem.acquire();
    //QTest::qSleep(ms);
}

void PSlideInterface::play(unsigned int KidId, unsigned int ms)
{
    emit sig_play(KidId,ms);
    getKid(KidId)->sem.acquire();
    //QTest::qSleep(ms);
}


void PSlideInterface::consoleAppendText(unsigned int consoleId,QString text) {
    emit sig_consoleAppendText(consoleId,text);
}


void PSlideInterface::setInitKid(unsigned int step, unsigned int KidId) {
    mainWindow->setKid(step, KidId);
}

void PSlideInterface::initialize(unsigned int nbConsoles, unsigned int nbStep)
{
    if (sm_didInitialize) {
        cout << "Vous devez ne devriez appeler PSlideInterface::initialize()"
             << " qu'une seule fois" << endl;
        QMessageBox::warning(0,"Erreur","Vous ne devriez appeler "
                             "PSlideInterface::initialize() "
                             "qu'une seule fois");
        return;
    }
    sm_nbSteps = nbStep;
    mainWindow= new MainWindow(nbConsoles,nbStep,0);
    mainWindow->show();
    sm_didInitialize=true;
}
