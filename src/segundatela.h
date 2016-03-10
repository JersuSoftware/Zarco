#ifndef SEGUNDATELA_H
#define SEGUNDATELA_H

#include <QDialog>

namespace Ui {
class SegundaTela;
}

class SegundaTela : public QDialog
{
    Q_OBJECT

public:
    explicit SegundaTela(QWidget *parent = 0);
    ~SegundaTela();

private:
    Ui::SegundaTela *ui;
};

#endif // SEGUNDATELA_H
