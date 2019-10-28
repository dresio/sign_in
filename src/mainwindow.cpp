#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QMainWindow::showFullScreen();

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionExit_triggered()
{
	this->close();
}

void MainWindow::run()
{
        QPushButton *button = this->findChild<QPushButton*>("click");
        QObject::connect(button, SIGNAL(clicked()),this, SLOT(clickedSlot()));
	show();
}

void MainWindow::clickedSlot()
{
	QString text = getTextBox();
	QMessageBox msgBox;
	msgBox.setText("Clicked");
	msgBox.exec();
}

bool MainWindow::writeToFile()
{
	return false;
}

QString MainWindow::getTextBox()
{
	QLineEdit *input = this->findChild<QLineEdit*>("input");
	QString text = input->text();
	return text;
}
