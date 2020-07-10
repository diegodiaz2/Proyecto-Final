#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    //Deshabilitamos el boton de para cerrar la ventana, asi el usuario debera ingresar o registrarse
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowContextHelpButtonHint);
    this->setWindowFlags(this->windowFlags() & ~Qt::WindowCloseButtonHint);
    ui->setupUi(this);
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
        if(iniciar(susuario,scontrasena)) close();
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
    //Se verifica que la contraseña o usuario no tenga espacios
    for(int i=0;susuario[i]!='\0';i++){
        if(susuario[i]==' ')n=0;
    }
    for(int i=0;scontrasena[i]!='\0';i++){
        if(scontrasena[i]==' ')n=0;
    }
    if(n){
        //Si se logra hacer un registro existoso se permite ingresar al juego
        if(!registrar(susuario,scontrasena)) close();
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
        //close();
    }
    else QMessageBox::about(this,"Error","Usuario o contraseña no valida");
    return n;
}

bool Dialog::registrar(string susuario,string scontrasena)
{
    bool n=0;
    string inf;
    ifstream k("../KYLLERFLYER/cuentas.txt");//"../Parcial1/productos.txt"
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
