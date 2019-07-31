#include <QtCore/QDateTime>
#include <QtWidgets/QFileDialog>
#include <QDebug>
#include <QtCore/QProcess>

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

// 打开 QFileDlg 选择文件
QList<QString> MainDialog::openFileDlg() {
	auto openFileDlg = new QFileDialog(this);
	openFileDlg->setWindowTitle(tr("ファイルを選択..."));
	openFileDlg->setNameFilter(tr("ファイル(*.*)"));
	openFileDlg->setFileMode(QFileDialog::ExistingFiles);
	// openFileDlg->setAcceptMode(QFileDialog::AcceptOpen);

	if (openFileDlg->exec()) 
		return openFileDlg->selectedFiles();
	else
		return *(new QList<QString>());
}

// 从 QString[] 中获得 FileDateTime[]
QList<FileDateTime> MainDialog::getFileProps(QList<QString> fileNames) {
	QList<FileDateTime> ret;
	foreach (QString fileName, fileNames) {
		auto file = new QFile(fileName);
		auto finfo = new QFileInfo(*file);

		QDateTime createTime = finfo->created();
		QDateTime updateTime = finfo->lastModified();
		QDateTime accessTime = finfo->lastRead();

		auto item = new FileDateTime(fileName, createTime, updateTime, accessTime);
		ret.append(*item);
	}
	return ret;
}

// 選択...(&O)
void MainDialog::on_Button_SelectFiles_clicked() {
	auto filenameList = openFileDlg();
	if (!filenameList.empty()) {
		ui.ListView_Files->clear();
		FileLists.clear();
		addFileToListView(getFileProps(filenameList));
	}
}

// 追加...(&A)
void MainDialog::on_Button_AddFiles_clicked() {
	auto filenameList = openFileDlg();
	if (!filenameList.empty()) {
		addFileToListView(getFileProps(filenameList));
	}
}

// 削除(&D)
void MainDialog::on_Button_DeleteFile_clicked() {
	if (getSelectedItemCount())
		foreach (QListWidgetItem *item, ui.ListView_Files->selectedItems()) 
			ui.ListView_Files->takeItem(ui.ListView_Files->row(item));
	updateListLabel();
}

// 場所を開く...(&F)
void MainDialog::on_Button_OpenDir_clicked() {
	QString url = ui.ListView_Files->selectedItems().at(0)->text();

	QProcess process;
	process.startDetached(QString("explorer /select, \"%1\"").arg(QString(url).replace("/", "\\")));
}

#pragma endregion FileList

// 列表操作
#pragma region ListView

// 将 FileDateTime[] 不重复添加到列表中
void MainDialog::addFileToListView(QList<FileDateTime> fileprops) {
	foreach (FileDateTime fileprop, fileprops) 
		if (ui.ListView_Files->findItems(fileprop.FileDir, Qt::MatchExactly).isEmpty()) {
			ui.ListView_Files->addItem(fileprop.FileDir);
			FileLists.append(fileprop);
		}
	updateListLabel();
}

// 更新列表标签显示内容
void MainDialog::updateListLabel() {
	int selcnt = getSelectedItemCount();
	int allcnt = ui.ListView_Files->count();
	ui.Label_FileListCnt->setText(tr("ファイルリスト (%1/%2)(&L):").arg(selcnt).arg(allcnt));
}

// 列表选择更改
void MainDialog::on_ListView_Files_itemSelectionChanged() {
	ui.Button_OpenDir->setEnabled(getSelectedItemCount() == 1);
	ui.Button_DeleteFile->setEnabled(getSelectedItemCount() != 0);
	updateListLabel();
}

// 获得选中长度
int MainDialog::getSelectedItemCount() {
	return ui.ListView_Files->selectedItems().size();
}

// 获得选中路径
QList<QString> MainDialog::getSelectedFileDir() {
	QList<QString> ret;
	foreach (auto item, ui.ListView_Files->selectedItems())
		ret.append(item->text());
	return ret;
}

// 获得选中时间信息
QList<FileDateTime> MainDialog::getSelectedFileDateTime() {
	QList<FileDateTime> ret;
	// TODO 算法待改
	foreach (QString dir, getSelectedFileDir()) {
		foreach (FileDateTime dft, FileLists) {
			if (dft.FileDir == dir) {
				ret.append(dft);
				break;
			}
		}
	}
	return ret;
}

#pragma endregion ListView

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

// 配置操作和一些 UI 交互
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
