#include <iostream>

#include <QApplication>
#include <QCommandLineParser>


#include "pslideinterface.h"
#include "kid.h"
#include "toboganmanager.h"

#define NBSTEPS 8
#define NBKIDS 10

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QCommandLineParser parser;
    QCommandLineOption stepNumber(QStringList() << "s" << "steps",
                                  QCoreApplication::translate("main",
                                       "Number or steps on toboggan, "
                                       "the slider is considered as a step, minimum 2"),
                                  QCoreApplication::translate("main", "steps"));

    QCommandLineOption kidNumber(QStringList() << "k" << "kids",
                                 QCoreApplication::translate("main",
                                                             "Number of kids on the toboggan, minimun 1"),
                                 QCoreApplication::translate("main", "kids"));

    parser.addOption(stepNumber);
    parser.addOption(kidNumber);
    parser.process(a);

    int nbSteps = parser.value(stepNumber).toInt();
    int nbKids = parser.value(kidNumber).toInt();

     std::cout << "Number of steps from cmd line: " << nbSteps << std::endl;
     std::cout << "Number of kids from cmd line: " << nbKids << std::endl;

    if (nbKids < 1) {
        nbKids = NBKIDS;
        std::cout << "Number of kids passed in commande line argument invalid."
                     " Using default value:"<< nbKids << std::endl;
    }

    if (nbSteps < 2) {
        nbSteps = NBSTEPS;
        std::cout << "Number of steps passed in commande line argument invalid."
                     " Using default value:"<< nbSteps << std::endl;
    }

     /* Max number not checked */

    // Inteface pour l'envoi de commandes à l'interface graphique.
    PSlideInterface *gui_interface;

    // Initialisation de la partie graphique de l'application
    PSlideInterface::initialize(nbKids,nbSteps);
    // Création de l'interface pour les commandes à la partie graphique
    gui_interface=new PSlideInterface();

    // Création de threads
    /*
    Kid* threads[nbKids];
    for(int t=0; t<nbKids; t++){
        std::cout << "Création du thread "<< t << std::endl;
        threads[t] = new Kid(t, gui_interface);
        threads[t]->start();
    }
    */
    toboganManager* tb = new toboganManager(nbKids, gui_interface);
    tb->start();

    // Attention, il est obligatoire d'exécuter l'instruction suivante.
    // C'est elle qui permet la gestion de la boucle des évévements de
    // l'application graphique.
    return a.exec();
}


