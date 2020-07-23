#include "dialog.h"
#include "ui_dialog.h"
#include "mainwindow.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //Deshabilitamos el boton de para cerrar la ventana, asi el usuario debera ingresar o registrarse
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
    ui->pushButton->setVisible(false);
    ui->pushButton_2->setVisible(false);
    ui->pushButton_3->setVisible(false);
    ui->comboBox->setVisible(false);
    ui->pushButton_4->setVisible(false);

}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::on_iniciarsesion_clicked()
{
    bool n=1;
    //Sacamos el usuario y la contraseña dada por el jugador
    QString usuario,contrasena;
    usuario=ui->usuario->text();
    contrasena=ui->lineEdit_2->text();
    //convertimos los QString a string
    std::string susuario=usuario.toStdString();
    std::string scontrasena=contrasena.toStdString();
    us=susuario;
    //Se verifica que la contraseña o usuario no tenga espacios
    for(int i=0;susuario[i]!='\0';i++){
        if(susuario[i]==' ')n=0;
    }
    for(int i=0;scontrasena[i]!='\0';i++){
        if(scontrasena[i]==' ')n=0;
    }
    //Si el usuario y la contraseña son correctas se permite ingresar al juego
    if(n){
        //Si se logra hacer un registro existoso se permite ingresar al juego
        if(iniciar(susuario,scontrasena)) menu_principal();
    }
    else QMessageBox::about(this,"Error","No se permite el ingreso de espacios");
}

void Dialog::on_registrar_clicked()
{
    bool n=1;
    //Sacamos el usuario y la contraseña dada por el jugador
    QString usuario,contrasena;
    usuario=ui->usuario->text();
    contrasena=ui->lineEdit_2->text();
    //convertimos los QString a string
    std::string susuario=usuario.toStdString();
    std::string scontrasena=contrasena.toStdString();
    us=susuario;
    //Se verifica que la contraseña o usuario no tenga espacios
    for(int i=0;susuario[i]!='\0';i++){
        if(susuario[i]==' ')n=0;
    }
    for(int i=0;scontrasena[i]!='\0';i++){
        if(scontrasena[i]==' ')n=0;
    }
    if(n){
        //Si se logra hacer un registro existoso se permite ingresar al juego
        if(!registrar(susuario,scontrasena)) menu_principal();
    }
    else QMessageBox::about(this,"Error","No se permite el ingreso de espacios");
}

bool Dialog::iniciar(string susuario,string scontrasena)
{
    bool n=0;
    string inf;
    ifstream k("../KYLLERFLYER/cuentas.txt");//"../Parcial1/productos.txt"
    while(!k.eof()){
        k>>inf;
        //Se verifica que el usuario sea el mismo
        if(inf==susuario){
            k>>inf;
            //Se verifica que la contraseña sea la misma
            if(inf==scontrasena){
                n=1;
            }
        }
        else k>>inf;
    }
    k.close();
    if(n){
        QMessageBox::about(this,"Informacion","Ingreso exitoso");
    }
    else QMessageBox::about(this,"Error","Usuario o contraseña no valida");
    return n;
}

bool Dialog::registrar(string susuario,string scontrasena)
{
    bool n=0;
    string inf;
    ifstream k("../KYLLERFLYER/cuentas.txt"); //"../Parcial1/productos.txt"
    while(!k.eof()){
        k>>inf;
        //Se verifica si ya existe alguna cuenta con ese usuario
        if(inf==susuario){
            k>>inf;
            n=1;
        }
        else k>>inf;
    }
    k.close();
    if(n) QMessageBox::about(this,"Error","Este usuario ya existe");
    //En dado caso de que no exista lo guarda
    else {
        inf=susuario+" "+scontrasena+"\n";
        ofstream k("../KYLLERFLYER/cuentas.txt",ios::app);
        k<<inf;
        k.close();
        QMessageBox::about(this,"Informacion","Registro exitoso");
    }
    return n;
}

//Funcion donde va a aparecer el menu principal luego de registrarse o iniciar sesion

void Dialog::menu_principal()
{
   //Se quita la visibilidad del menu de inicio de sesion
   ui->label->setVisible(false);
   ui->label_2->setVisible(false);
   ui->usuario->setVisible(false);
   ui->registrar->setVisible(false);
   ui->lineEdit_2->setVisible(false);
   ui->iniciarsesion->setVisible(false);
   //Se muestran los botones del menu que nos va a permitir acceder a la jugabilidad
   ui->pushButton->setVisible(true);
   ui->pushButton_2->setVisible(true);
   ui->pushButton_3->setVisible(true);
}

void Dialog::cargar()
{
    string inf;
    ifstream k("../KYLLERFLYER/"+us+".txt");
    if (k.good()){
        while(!k.eof()){
            k>>inf;
            ui->comboBox->addItem(QString::fromStdString(inf));
            k>>inf;
            k>>inf;
            k>>inf;
        }
        ui->pushButton_4->setVisible(true);
    }
    else {
        QMessageBox::about(this, "Error", "Este usuario no tiene partidas guardadas");
    }

}

void Dialog::on_pushButton_clicked()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    mv->n_usuario=us;
    mv->tipo=1;
    mv->timer->start(5000);
    close();
}

void Dialog::on_pushButton_2_clicked()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    mv->tipo=2;
    mv->n_usuario=us;
    mv->timer->start(5000);
    close();
}

void Dialog::on_pushButton_3_clicked()
{
    ui->pushButton_3->setEnabled(false);
    ui->comboBox->setVisible(true);
    cargar();


}

void Dialog::on_pushButton_4_clicked()
{
    MainWindow *mv=MainWindow::getMainWinPtr();
    mv->n_usuario=us;
    string inf;
    std::string nombre=ui->comboBox->currentText().toStdString();
    ifstream k("../KYLLERFLYER/"+us+".txt");
    if (k.good()){
        while(!k.eof()){
            k>>inf;
            if(inf==nombre){
                k>>inf;
                mv->puntaje=stoi(inf)-10;
                k>>inf;
                mv->vidas=stoi(inf)+10;
                k>>inf;
                mv->tipo=stoi(inf);
            }
            else{
                k>>inf;
                k>>inf;
                k>>inf;

            }
        }
    }
    mv->vida();
    mv->score();
    close();
}
