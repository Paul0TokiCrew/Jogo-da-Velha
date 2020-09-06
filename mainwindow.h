#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    bool marcarArea(int &n);

    bool checarVitoria();

    bool checarEmpate();

    void resetarTabuleiro();

private slots:
    void on_pushButton_clicked();
    //Caso botão de marcar seja clickado

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
