#include "mainwindow.h"
#include <QApplication>

/**
 * Format for saving info: <Last name>,<First name>,<ID>,<Time in>,<Time out>
 * 
 * TODO
 * -Get input from user
 * -Check if exists in server file
 * --ftp file connect
 * -prompt user for sign in/out
 * -time stamp on UI
 * --send info to server
**/

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	MainWindow w;
	
	w.run();

	return a.exec();
	
}

