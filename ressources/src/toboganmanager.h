#ifndef TOBOGANMANAGER_H
#define TOBOGANMANAGER_H

#include <QSemaphore>
#include "kid.h"
#include <iostream>
#include <QThread>

/**
 * @brief The toboganManager class
 *
 * Classe perettant la géstion de tobogans.
 * ELle créee un nombre d'enfants et les fait jouer sur le tobogan.
 * Elle s'assure que les enfant ne soient pas à plus que 1 sur un marche grace à un  tableau de semaphore(1 semaphore par marche)
 */
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
            // Test mais ça fonctionne pas aussi
            // gui_interface->setInitKid(gui_interface->nbSteps() +1, t);
            threads[t]->start();
        }
    }

private:
    unsigned int nbKids;
    PSlideInterface *gui_interface;

    // Tableau de référence sur des semaphore pour bloquer les marches quand un enfant y est.
    QSemaphore** mutexMarche;
    // Tableau d'anfants
    Kid** threads;

};

#endif // TOBOGANMANAGER_H
