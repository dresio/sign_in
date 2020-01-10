#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <ctime>
#include <string.h>
#include <QTimer>
#include <QTime>

MainWindow::MainWindow(QWidget *parent):QMainWindow(parent), ui(new Ui::MainWindow)
{
	ui->setupUi(this);

	QMainWindow::showFullScreen();

	timer_1s = new QTimer(this);
	QObject::connect(timer_1s, SIGNAL(timeout()), this, SLOT(UpdateTime()));
    timer_1s->start(1000);

}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_actionExit_triggered()
{
	this->close();
}

void MainWindow::UpdateTime()
{
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	//time stream
	int year = now->tm_year+1900;
	int mon = now->tm_mon+1;
	int day = now->tm_mday;

    ui->lbl_time->setText(QTime::currentTime().toString("hh:mm"));

	std::string date;
	date = std::to_string(day) + "/" + std::to_string(mon) + "/" + std::to_string(year);

	QString qstr = QString::fromStdString(date);

	ui->lbl_date->setText(qstr);
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
	writeToFile(text);

}

//Format will be {user,timeIn,timeOut}
//timeOut will be -1 if user hasn't signed out yet
//Link users file will be used to parse same user using multiple IDs
bool MainWindow::writeToFile(QString name)
{
	QFile data("ledger.csv");
	std::time_t time = std::time(0);
	std::tm* now = std::localtime(&time);
	//time stream
	int year = now->tm_year+1900;
	int mon = now->tm_mon+1;
	int day = now->tm_mday;
	int hour = now->tm_hour;
	int min = now->tm_min;

	if (data.open(QFile::ReadWrite | QIODevice::Append)) {
    	QTextStream out(&data);

    	out << name << ',' << year << '-' << mon << '-' << day << '-' << hour << '-' << min << '\n';
	}
	return true;
}

QString MainWindow::getTextBox()
{
	QLineEdit *input = this->findChild<QLineEdit*>("input");
	QString text = input->text();
	return text;
}
