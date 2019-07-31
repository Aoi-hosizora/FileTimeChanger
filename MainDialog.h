#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#ifdef WIN32  
#pragma execution_character_set("utf-8")  
#endif

#include <QtWidgets/QDialog>

#include "ui_MainDialog.h"
#include "FileDateTime.h"

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

	void on_Button_CreateDefault_clicked();
	void on_Button_UpdateDefault_clicked();
	void on_Button_AccessDefault_clicked();

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

	// ListView
	void on_ListView_Files_itemSelectionChanged();
	void updateDateTime();
	
private:
	Ui::MainDialogClass ui;
	QList<FileDateTime> FileLists;

	QList<QString> openFileDlg();
	QList<FileDateTime> getFileProps(QList<QString>);
	void addFileToListView(QList<FileDateTime>);
	void updateListLabel();
	int getSelectedItemCount();
	QList<QString> getSelectedFileDir();
	QList<FileDateTime> getSelectedFileDateTime();
	FileDateTime *getSelectedFirstFileDateTime();
	FileDateTime *getFileDateTimeFromDir(QString);
	void setDateTimeOfOneFile(FileDateTime);
};

#endif // MAINDIALOG_H
