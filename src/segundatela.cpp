#include "segundatela.h"
#include "ui_segundatela.h"

SegundaTela::SegundaTela(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SegundaTela)
{
    ui->setupUi(this);
}

SegundaTela::~SegundaTela()
{
    delete ui;
}
