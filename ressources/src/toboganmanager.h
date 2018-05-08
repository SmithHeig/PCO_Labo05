#ifndef TOBOGANMANAGER_H
#define TOBOGANMANAGER_H

#include <QSemaphore>
#include "kid.h"
#include <iostream>
#include <QThread>

class toboganManager: public QThread
{
public:
    toboganManager(unsigned int nbKids, PSlideInterface *interface): nbKids(nbKids), gui_interface(interface) {
        mutexMarche = new QSemaphore*[gui_interface->nbSteps() + 1];


        tabValidity = new bool[gui_interface->nbSteps() + 1];
        for(int i = 0; i < gui_interface->nbSteps() + 1; ++i){
            tabValidity[i] = false;
            mutexMarche[i] = new QSemaphore(1);
        }

        threads = new Kid*[nbKids];
        for(int t=0; t < nbKids; t++){
            std::cout << "Création du thread " << t << std::endl;
            threads[t] = new Kid(t, gui_interface, &mutexMarche);
            gui_interface->setInitKid(gui_interface->nbSteps() +1, t);
        }
    }

    void run() Q_DECL_OVERRIDE {
        for(int t=0; t<nbKids; t++){
            threads[t]->start();
        }
    }

private:
    unsigned int nbKids;
    PSlideInterface *gui_interface;

    QSemaphore** mutexMarche;
    bool* tabValidity;
    Kid** threads;

};

#endif // TOBOGANMANAGER_H
