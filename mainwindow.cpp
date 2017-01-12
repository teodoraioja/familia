#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
#include<QTextStream>
#include<QtDebug>
#include<iostream>
#include<string>
#include<fstream>

using namespace std;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_openFile_clicked()
{
QString filename= QFileDialog::getOpenFileName(
            this,
            tr("Open File"),
            "C://Users/teo/Documents/FamiliProject",
            "Text File(*.txt)"
            );
ui->textBrowser->setText(filename);

QFile file(filename);
char famili[100];
//QTextStream in(&file);
//QString str_Line = in.readLine();
//str_Line.trimmed();
//str_Line.simplified();
//qDebug() << str_Line;

if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    return;
int i=0;
while (!file.atEnd()) {
    QByteArray line = file.readLine();
famili[i]= *line.data();
i++;
}

for(int i=0;i<100;i++){
    qDebug() << famili[i];
}

QPushButton *trainButton = new QPushButton(this);
trainButton->setText(tr("Analyze Tree"));
trainButton->move(20, 90);
trainButton->show();

}


void MainWindow::on_trainButton_clicked()
{
ui->showBox->setText("apasat");
}
