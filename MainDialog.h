#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QtWidgets/QDialog>

#include "ui_MainDialog.h"

class MainDialog : public QDialog {
	Q_OBJECT

public:
	MainDialog(QWidget *parent = nullptr);
	~MainDialog();

private slots:
	// Buttons
	void on_Button_SelectFiles_clicked();
	void on_Button_AddFiles_clicked();
	void on_Button_DeleteFile_clicked();
	void on_Button_OpenDir_clicked();

	void on_Button_CreateNow_clicked();
	void on_Button_UpdateNow_clicked();
	void on_Button_AccessNow_clicked();

	void on_Button_Transform_clicked();

	// Toggled
	void on_RadioButton_AllFileProp_toggled(bool);
	void on_RadioButton_OneFileProp_toggled(bool);

	void on_CheckButton_CreateDateTime_toggled(bool);
	void on_RadioButton_Create_Create_toggled(bool);
	void on_RadioButton_Create_Update_toggled(bool);
	void on_RadioButton_Create_Access_toggled(bool);

	void on_CheckButton_UpdateDateTime_toggled(bool);
	void on_RadioButton_Update_Update_toggled(bool);
	void on_RadioButton_Update_Create_toggled(bool);
	void on_RadioButton_Update_Access_toggled(bool);

	void on_CheckButton_AccessDateTime_toggled(bool);
	void on_RadioButton_Access_Access_toggled(bool);
	void on_RadioButton_Access_Create_toggled(bool);
	void on_RadioButton_Access_Update_toggled(bool);

	void on_CheckButton_TransformFolderAlso_toggled(bool);
	void on_CheckButton_TransformRecursion_toggled(bool);
	
private:
	Ui::MainDialogClass ui;
};

#endif // MAINDIALOG_H
