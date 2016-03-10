#include "mainwindow.h"
#include "graph.h"
#include <QApplication>
#include "vector"
#include "iostream"
#include "set"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    Graph grafo = Graph();
    w.setGrafo(grafo);
    w.show();

    return a.exec();
}
