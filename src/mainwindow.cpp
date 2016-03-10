#include "mainwindow.h"
#include "ui_mainwindow.h"
//#include "segundatela.h"
#include "graph.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    inicio = 0;
    destino = 0;
    hideLabel();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_4_clicked()
{
    hideLabel();
    ui->label_distancia->setText("Distância:");
    ui->label_distancianum->setNum(grafo.dijkstra(inicio,destino));
    caminho.clear();
    caminho = grafo.getCaminho(destino);
    ui->label_2->setText("Número de ônibus: ");
    numerodeZarco = caminho.size()-1;
    ui->label->setNum(numerodeZarco);
    ui->label_5->show();

    for(unsigned int i = 0; i <  caminho.size(); ++i){
        switch (caminho[i]){
        case 0:
            ui->label_centro->show();
            switch (caminho[i+1]){
            case 1:
                ui->label_centronorte->show();
                break;
            case 2:
                ui->label_centrosul->show();
                break;
            case 3:
                ui->label_centrotupy->show();
                break;
            case 4:
                ui->label_centrovilanova->show();
                break;
            case 5:
                ui->label_centroiririu->show();
                break;
            case 6:
                ui->label_centroitaum->show();
                break;
            case 7:
                ui->label_centronovabrasilia->show();
                break;
            case 8:
                ui->label_centroguanabara->show();
                break;
            case 10:
                ui->label_centrocampus->show();
                break;
            default:
                break;
            }
            break;
        case 1:
            ui->label_norte->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centronorte->show();
                break;
            case 2:
                ui->label_nortesul->show();
                break;
            case 4:
                ui->label_nortevilanova->show();
                break;
            case 5:
                ui->label_norteiririu->show();
                break;
            case 9:
                ui->label_nortepirabeiraba->show();
                break;
            case 10:
                ui->label_campusnorte->show();
                break;
            default:
                break;
            }
            break;
        case 2:
            ui->label_sul->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centrosul->show();
                break;
            case 1:
                ui->label_nortesul->show();
                break;
            case 6:
                ui->label_sulitaum->show();
                break;
           /* case 9:
                ui->label_nortepirabeiraba->show();
                break;*/
            case 10:
                ui->label_campussul->show();
                break;
            default:
                break;
            }
            break;
        case 3:
            ui->label_tupy->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centrotupy->show();
                break;
            case 5:
                ui->label_tupyiririu->show();
                break;
            case 8:
                ui->label_tupyguanabara->show();
                break;
            default:
                break;
            }
            break;
        case 4:
            ui->label_vilanova->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centrovilanova->show();
                break;
            case 1:
                ui->label_nortevilanova->show();
                break;
            case 9:
                ui->label_pirabeirabavilanova->show();
            default:
                break;
            }
            break;
        case 5:
            ui->label_iririu->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centroiririu->show();
                break;
            case 1:
                ui->label_norteiririu->show();
                break;
            case 3:
                ui->label_tupyiririu->show();
                break;
            case 10:
                ui->label_campusiririu->show();
                break;
            default:
                break;
            }
            break;
        case 6:
            ui->label_itaum->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centroitaum->show();
                break;
            case 2:
                ui->label_sulitaum->show();
                break;
            case 10:
                ui->label_campusitaum->show();
                break;
            default:
                break;
            }
            break;
        case 7:
            ui->label_novabrasilia->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centronovabrasilia->show();
                break;
            default:
                break;
            }
            break;
        case 8:
            ui->label_guanabara->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centroguanabara->show();
                break;
            case 3:
                ui->label_tupyguanabara->show();
            default:
                break;
            }
            break;
        case 9:
            ui->label_pirabeiraba->show();
            switch (caminho[i+1]) {
            case 1:
                ui->label_nortepirabeiraba->show();
                break;
            case 4:
                ui->label_pirabeirabavilanova->show();
                break;
            default:
                break;
            }
            break;
        case 10:
            ui->label_campus->show();
            switch (caminho[i+1]) {
            case 0:
                ui->label_centrocampus->show();
                break;
            case 1:
                ui->label_campusnorte->show();
                break;
            case 2:
                ui->label_campussul->show();
                break;
            case 5:
                ui->label_campusiririu->show();
                break;
            case 6:
                ui->label_campusitaum->show();
                break;
            default:
                break;
            }
            break;
        }
    }
}

void MainWindow::on_comboBox_currentIndexChanged(int index)
{
    inicio = index-1;
}

void MainWindow::on_comboBox_2_currentIndexChanged(int index)
{
    destino = index-1;
}

void MainWindow::setGrafo(Graph grafo){
    this->grafo=grafo;
}

void MainWindow::hideLabel(){
    ui->label_centro->hide();
    ui->label_pirabeiraba->hide();
    ui->label_sul->hide();
    ui->label_norte->hide();
    ui->label_tupy->hide();
    ui->label_vilanova->hide();
    ui->label_iririu->hide();
    ui->label_itaum->hide();
    ui->label_novabrasilia->hide();
    ui->label_guanabara->hide();
    ui->label_campus->hide();
    ui->label_centrosul->hide();
    ui->label_centronorte->hide();
    ui->label_centrotupy->hide();
    ui->label_centrovilanova->hide();
    ui->label_centroiririu->hide();
    ui->label_centronovabrasilia->hide();
    ui->label_centroguanabara->hide();
    ui->label_centrocampus->hide();
    ui->label_centroitaum->hide();
    ui->label_nortesul->hide();
    ui->label_nortepirabeiraba->hide();   
    ui->label_nortevilanova->hide();
    ui->label_norteiririu->hide();
    ui->label_tupyguanabara->hide();
    ui->label_tupyiririu->hide();
    ui->label_sulitaum->hide();
    ui->label_campusitaum->hide();
    ui->label_campussul->hide();
    ui->label_campuscentro->hide();
    ui->label_campusnorte->hide();
    ui->label_campusiririu->hide();
    ui->label_pirabeirabavilanova->hide();
    ui->label_5->hide();
}
