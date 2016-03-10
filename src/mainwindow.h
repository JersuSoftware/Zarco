#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "graph.h"
#include <vector>

using namespace std;

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
     int inicio;
     int destino;
     int numerodeZarco;
     vector<int> caminho;
     Graph grafo;
     void setGrafo(Graph grafo);
     void hideLabel();

private slots:
    void on_novatela_clicked();

    void on_pushButton_4_clicked();

    void on_comboBox_currentIndexChanged(int index);

    void on_comboBox_2_currentIndexChanged(int index);

    void on_webView_loadStarted();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
