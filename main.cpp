#include <QtWidgets/QApplication>
// #include <vld.h>

#include "MainDialog.h"

int main(int argc, char *argv[]) {
	QApplication a(argc, argv);
	auto w = new MainDialog();
	w->show();
	return a.exec();
}
