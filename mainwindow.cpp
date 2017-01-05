#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QFileDialog>
#include<QMessageBox>
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
QPushButton *trainButton = new QPushButton(this);
trainButton->setText(tr("Analyze Tree"));
trainButton->move(20, 90);
trainButton->show();

}


void MainWindow::on_trainButton_clicked()
{
ui->textBrowser->setText("apasat");
}
