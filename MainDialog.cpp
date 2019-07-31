#include "MainDialog.h"
#include "FileDateTime.h"
#include "Config.hpp"

MainDialog::MainDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);
}

MainDialog::~MainDialog() {

}

// 文件操作
#pragma region FileList 

// 選択...(&O)
void MainDialog::on_Button_SelectFiles_clicked() {

}

// 追加...(&A)
void MainDialog::on_Button_AddFiles_clicked() {

}

// 削除(&D)
void MainDialog::on_Button_DeleteFile_clicked() {

}

// 場所を開く...(&F)
void MainDialog::on_Button_OpenDir_clicked() {

}

#pragma endregion FileList

// 日期操作
#pragma region DateTime

// 作成日時(&C) 現在日時に
void MainDialog::on_Button_CreateNow_clicked() {
	ui.DateEdit_CreateDate->setDate(QDate::currentDate());
	ui.TimeEdit_CreateTime->setTime(QTime::currentTime());
}

// 更新日時(&U) 現在日時に
void MainDialog::on_Button_UpdateNow_clicked() {
	ui.DateEdit_UpdateDate->setDate(QDate::currentDate());
	ui.TimeEdit_UpdateTime->setTime(QTime::currentTime());
}

// ｱｸｾｽ日時(&E) 現在日時に
void MainDialog::on_Button_AccessNow_clicked() {
	ui.DateEdit_AccessDate->setDate(QDate::currentDate());
	ui.TimeEdit_AccessTime->setTime(QTime::currentTime());
}

#pragma endregion DateTime

// 配置操作
#pragma region Toggled

// すべてのファイルを同一の日時に変更する
void MainDialog::on_RadioButton_AllFileProp_toggled(bool isChecked) {
	Config::IsAllFileProp = isChecked;
}

// ファイルごとに別々の日時に変更する
void MainDialog::on_RadioButton_OneFileProp_toggled(bool isChecked) {
	Config::IsAllFileProp = isChecked;
}

// 作成日時(&C) UI <<
void MainDialog::on_CheckButton_CreateDateTime_toggled(bool isChecked) {
	Config::IsCreateDateTimeTransform = isChecked;

	ui.DateEdit_CreateDate->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);
	ui.TimeEdit_CreateTime->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);
	ui.Button_CreateNow->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);
}

// 更新日時(&U) UI <<
void MainDialog::on_CheckButton_UpdateDateTime_toggled(bool isChecked) {
	Config::IsUpdateDateTimeTransform = isChecked;

	ui.DateEdit_UpdateDate->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);
	ui.TimeEdit_UpdateTime->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);
	ui.Button_UpdateNow->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);
}

// ｱｸｾｽ日時(&E) UI <<
void MainDialog::on_CheckButton_AccessDateTime_toggled(bool isChecked) {
	Config::IsAccessDateTimeTransform = isChecked;

	ui.DateEdit_AccessDate->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);
	ui.TimeEdit_AccessTime->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);
	ui.Button_AccessNow->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);
}

// 作成日時(&C) 別の日時
void MainDialog::on_RadioButton_Create_Create_toggled(bool isChecked) {
	Config::IsCreateDateTimeUseCreate = isChecked;
}

// 作成日時(&C) 更新日時と合わせ
void MainDialog::on_RadioButton_Create_Update_toggled(bool isChecked) {
	Config::IsCreateDateTimeUseUpdate = isChecked;
}

// 作成日時(&C) ｱｸｾｽ日時と合わせ
void MainDialog::on_RadioButton_Create_Access_toggled(bool isChecked) {
	Config::IsCreateDateTimeUseAccess = isChecked;
}

// 更新日時(&U) 別の日時
void MainDialog::on_RadioButton_Update_Update_toggled(bool isChecked) {
	Config::IsUpdateDateTimeUseUpdate = isChecked;
}

// 更新日時(&U) 作成日時と合わせ
void MainDialog::on_RadioButton_Update_Create_toggled(bool isChecked) {
	Config::IsUpdateDateTimeUseCreate = isChecked;
}

// 更新日時(&U) ｱｸｾｽ日時と合わせ
void MainDialog::on_RadioButton_Update_Access_toggled(bool isChecked) {
	Config::IsUpdateDateTimeUseAccess = isChecked;
}

// ｱｸｾｽ日時(&E) 別の日時
void MainDialog::on_RadioButton_Access_Access_toggled(bool isChecked) {
	Config::IsAccessDateTimeUseAccess = isChecked;
}

// ｱｸｾｽ日時(&E) 作成日時と合わせ
void MainDialog::on_RadioButton_Access_Create_toggled(bool isChecked) {
	Config::IsAccessDateTimeUseCreate = isChecked;
}

// ｱｸｾｽ日時(&E) 更新日時と合わせ
void MainDialog::on_RadioButton_Access_Update_toggled(bool isChecked) {
	Config::IsAccessDateTimeUseUpdate = isChecked;
}

// フォルダーの日時を変更する
void MainDialog::on_CheckButton_TransformFolderAlso_toggled(bool isChecked) {
	Config::IsTransformFolderAlso = isChecked;
}

// フォルダー内のファイルの日時も変更する
void MainDialog::on_CheckButton_TransformRecursion_toggled(bool isChecked) {
	Config::IsTransformRecursion = isChecked;
}

#pragma endregion Toggled

// 转换操作
#pragma region Transform

// 変更(&T)
void MainDialog::on_Button_Transform_clicked() {

}

#pragma endregion Transform
