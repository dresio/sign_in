#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>
#include <iostream>
#include <fstream>

namespace Ui{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow(); 

    void run();

private slots:
    void on_actionExit_triggered();
	void clickedSlot();
	bool writeToFile(QString text);
	QString getTextBox();

private:
    Ui::MainWindow *ui;
};

#endif
