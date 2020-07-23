#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "fstream"
#include "iostream"
using namespace std;

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();


private slots:
    void on_iniciarsesion_clicked();

    void on_registrar_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


    void on_pushButton_4_clicked();

private:
    bool iniciar(string susuario,string scontrasena);
    bool registrar(string susuario,string scontrasena);
    void menu_principal();
    void cargar();
    Ui::Dialog *ui;
    string us;

};

#endif // DIALOG_H
