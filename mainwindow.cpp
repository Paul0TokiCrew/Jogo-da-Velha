#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QSpinBox>
#include <QMessageBox>

static int jogadorN = 1;
//jogadorN fala se é o jogador 1 ou 0 que está jogando
//Essa variável ajuda o programa a saber se deve marcar X ou O

static int areaTab[9] = {
    1, 2, 3,
    4, 5, 6,
    7, 8, 9
};
//areaTab representa o tabuleiro. Essa array
//serve para determinar quais áreas estão
//livres ou marcadas. Isso vai evitar que um
//mesmo espaço poder ser marcado várias vezes

static QString sym;
//sym é o símbolo que marcará a área, que no caso será X ou O

bool checar(int area[], int i, int n) {
  if(area[i] == n)
      return true;
  else
      return false;
};

bool checarSeq(int area[], int i1, int i2, int i3, int n) {
    if(checar(area, i1, n) && checar(area, i2, n) && checar(area, i3, n))
        return true;
    else
        return false;
}

bool percorrerTab(int area[]) {
    bool tabEstaPreenchido;
    for(int C = 0; C < 9; C++) {
        if(area[C] == 0 || area[C] == -1)
            tabEstaPreenchido = true;
        else {
            tabEstaPreenchido = false;
            break;
        }
    }

    return tabEstaPreenchido;
}

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow) {
    ui->setupUi(this);
}

MainWindow::~MainWindow() {
    delete ui;
}


void MainWindow::on_pushButton_clicked() {
    int n = ui->spinBox->QSpinBox::value();
    //n pega o valor da área que está sendo marcada

    if(marcarArea(n)) { //Se a área for marcada com sucesso...
        jogadorN++;
        jogadorN %= 2;
        areaTab[n - 1] = jogadorN - 1;
        //Esse procedimento faz a vez passar
        //e marca a área na array, respectivamente

        if(checarVitoria()) { //Se houver uma vitória...
            QMessageBox::about(this, "Fim de Jogo", "Jogador " + sym + " ganhou");
            resetarTabuleiro();

        } else if(checarEmpate()) { //Senão, deve ver se há empate
            QMessageBox::about(this, "Fim de Jogo", "O jogo empatou");
            resetarTabuleiro();
        } //Senão, o jogo continua

    } //Senão, nada muda e o jogador não perde a vez

}

bool MainWindow::marcarArea(int &n) {

    jogadorN == 0 ? sym = "X" : sym = "O";
    //sym receberá um valor de acordo
    //com o jogador atual rodada

    if(areaTab[n - 1] != 0 && areaTab[n - 1] != -1) { //Checa se a área que o jogador deseja marcar
                                                         //já não está marcada. Se a área estiver livre...

        switch(n) { //switch pega n e marca a área
                    //correspondente ao valor de n e
                    //retorna true para indicar que
                    //a área foi marcada com sucesso

        case 1:
            ui->label1->setText(sym);
            return true;
            break;

        case 2:
            ui->label2->setText(sym);
            return true;
            break;

        case 3:
            ui->label3->setText(sym);
            return true;
            break;

        case 4:
            ui->label4->setText(sym);
            return true;
            break;

        case 5:
            ui->label5->setText(sym);
            return true;
            break;

        case 6:
            ui->label6->setText(sym);
            return true;
            break;

        case 7:
            ui->label7->setText(sym);
            return true;
            break;

        case 8:
            ui->label8->setText(sym);
            return true;
            break;

        case 9:
            ui->label9->setText(sym);
            return true;
            break;

        }

    }else //Se a área já estiver marcada...
        return false;

}

bool MainWindow::checarVitoria() {
    static int seq[9];
    //Array que irá criar sequências

    int C = 0;
    while(C < 9) { //Criação e atualização de sequência

        if(checar(areaTab, C, 0))       //X
            seq[C] = 0;
        else if(checar(areaTab, C, -1)) //O
            seq[C] = -1;
        else                            //Nem X nem O
            seq[C] = 1;

        C++;
    }

    sym == "X" ? C = 0 : C = -1;
    if(checarSeq(seq, 0, 1, 2, C))      //Sequências horizontais
        return true;
    else if(checarSeq(seq, 3, 4, 5, C))
        return true;
    else if(checarSeq(seq, 6, 7, 8, C))
        return true;

    else if(checarSeq(seq, 0, 3, 6, C)) //Sequências verticais
        return true;
    else if(checarSeq(seq, 1, 4, 7, C))
        return true;
    else if(checarSeq(seq, 2, 5, 8, C))
        return true;

    else if(checarSeq(seq, 0, 4, 8, C)) //Sequências diagonais
        return true;
    else if(checarSeq(seq, 2, 4, 6, C))
        return true;
    else
       return false;

}

bool MainWindow::checarEmpate() {
    if(!(checarVitoria()) && percorrerTab(areaTab))
        return true;
    else
        return false;
}

void MainWindow::resetarTabuleiro() {
    ui->label1->setText("1");
    ui->label2->setText("2");
    ui->label3->setText("3");
    ui->label4->setText("4");
    ui->label5->setText("5");
    ui->label6->setText("6");
    ui->label7->setText("7");
    ui->label8->setText("8");
    ui->label9->setText("9");

    for(int C = 0; C < 9; C++) {
        areaTab[C] = C + 1;
    }
}
