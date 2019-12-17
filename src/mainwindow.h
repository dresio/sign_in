#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLineEdit>
#include <QMessageBox>
#include <QString>
#include <QFile>
#include <QTextStream>

#include "gtest/gtest.h"   // Google Test Framework
#include "ftpclient-cpp/TestFTP/test_utils.h"    // Helpers for tests

// Test subject (SUT)
#include "ftpclient-cpp/FTP/FTPClient.h"

#define PRINT_LOG [](const std::string& strLogMsg) { std::cout << strLogMsg << std::endl;  }

namespace Ui {
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
