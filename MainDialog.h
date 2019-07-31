#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_MainDialog.h"

class MainDialog : public QDialog {
	Q_OBJECT

public:
	MainDialog(QWidget *parent = nullptr);
	~MainDialog();

private:
	Ui::MainDialogClass ui;
};

#endif // MAINDIALOG_H
