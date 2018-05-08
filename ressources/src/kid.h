/******************************************************************************
  \file main.cpp
  \author Yann Thoma
  \modified J.Chatillon, J.Smith
  \date 16.02.2018

  Ce fichier propose un squelette pour l'application de modélisation de toboggan.
  Il est évident qu'il doit être grandement modifié pour respecter la donnée,
  mais vous y trouvez des exemples d'appels de fonctions de l'interface.
  ****************************************************************************/



#ifndef KID_H
#define KID_H

#include <QThread>
#include <QSemaphore>

#include "pslideinterface.h"


/**
  Tâche illustrant les différents appels pouvant être faits à l'interface
  graphique.
  */
class Kid: public QThread
{
public:
    Kid(unsigned int id, PSlideInterface *interface, QSemaphore*** ref) : id(id), gui_interface(interface), ref(ref) {}

    void run() Q_DECL_OVERRIDE {
        unsigned int t = id;
        qsrand(t);

        // Affichage d'un message
        gui_interface->consoleAppendText(t,"Salut");

        while(1) {
            {
                unsigned int step = 0;
                for(step = 0; step < gui_interface->nbSteps() + 1; step++){
                    if(step == 0){
                        (*ref)[step]->acquire();
                    }
                    // Déplacement d'un enfant
                    gui_interface->travel(t,             // ID de l'enfant
                                          (step)%(gui_interface->nbSteps()+1), // marche d'arrivée
                                          (t+1)*100);   // Temps en millisecondes
                    if(step != 0)
                        (*ref)[step-1]->release();

                    QThread::usleep(qrand()*t % 100000);

                    if(step != gui_interface->nbSteps()){
                        (*ref)[step+1]->acquire();
                    }
                }
                (*ref)[step-1]->release();
            }


            // Va jouer un moment
            gui_interface->play(t,(t+1)*1000);

            // Attend un peu
            QThread::usleep(1000000);

            // Est prêt à repartir sur le toboggan
        }
    }

private:
    unsigned int id;
    PSlideInterface *gui_interface;
    QSemaphore*** ref;
};


#endif // KID_H
