/******************************************************************************
  \file mainwindow.cpp
  \author Yann Thoma
  \date 05.05.2011

  Fichier faisant partie du labo toboggan.
  ****************************************************************************/


#include "mainwindow.h"

#define min(a,b) ((a<b)?(a):(b))

MainWindow::MainWindow(unsigned int nbConsoles,unsigned int nbStep,
                       QWidget *parent)
    : QMainWindow(parent)
{
    m_nbConsoles=nbConsoles;
    m_consoles=new QTextEdit*[nbConsoles];
    for(unsigned int i=0;i<nbConsoles;i++) {
        m_consoles[i]=new QTextEdit(this);
        m_consoles[i]->setMinimumWidth(200);
    }
    m_docks=new QDockWidget*[nbConsoles];
    for(unsigned int i=0;i<nbConsoles;i++) {
        m_docks[i]=new QDockWidget(this);
        m_docks[i]->setWidget(m_consoles[i]);
    }
    for(unsigned int i=0;i<nbConsoles/2;i++) {
        this->addDockWidget(Qt::LeftDockWidgetArea,m_docks[i]);
    }
    for(unsigned int i=nbConsoles/2;i<nbConsoles;i++) {
        this->addDockWidget(Qt::RightDockWidgetArea,m_docks[i]);
    }

    for(unsigned int i=0;i<nbConsoles;i++)
        setConsoleTitle(i,QString("Console number : %1").arg(i));
    m_display=new TobogganDisplay(nbStep,this);
    setCentralWidget(m_display);
}


void MainWindow::setConsoleTitle(unsigned int consoleId,QString title)
{
    if (consoleId>=m_nbConsoles)
        return;
    m_docks[consoleId]->setWindowTitle(title);
}

void MainWindow::consoleAppendText(unsigned int consoleId,QString text)
{
    if (consoleId>=m_nbConsoles)
        return;
    m_consoles[consoleId]->append(text);
}


void MainWindow::setKid(unsigned int step, unsigned int KidId)
{
    m_display->setKid(step,KidId);
}

void MainWindow::travel(unsigned int KidId, unsigned int step2, unsigned int ms)
{
    m_display->travel(KidId,step2,ms);
}

void MainWindow::play(unsigned int KidId, unsigned int ms)
{
    m_display->play(KidId,ms);
}


MainWindow::~MainWindow()
{

}
