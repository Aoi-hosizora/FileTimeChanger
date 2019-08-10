#include <QtCore/QDateTime>
#include <QtWidgets/QFileDialog>
#include <QDebug>
#include <QtCore/QProcess>
#include <QtWidgets/QMessageBox>
#include <QtGui>
#include <QtCore/QMimeData>
#include <QtWidgets/QTreeView>

#include "MainDialog.h"
#include "FileDateTime.h"
#include "Config.hpp"
#include "Util.hpp"

MainDialog::MainDialog(QWidget *parent) : QDialog(parent) {
	ui.setupUi(this);

	setWindowFlags(Qt::Window
		| Qt::WindowCloseButtonHint
		| Qt::WindowMinimizeButtonHint 
		| Qt::WindowStaysOnTopHint);

	on_ListView_Files_itemSelectionChanged();

	connect(ui.DateEdit_CreateDate, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateTime()));
	connect(ui.TimeEdit_CreateTime, SIGNAL(timeChanged(QTime)), this, SLOT(updateDateTime()));
	connect(ui.DateEdit_UpdateDate, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateTime()));
	connect(ui.TimeEdit_UpdateTime, SIGNAL(timeChanged(QTime)), this, SLOT(updateDateTime()));
	connect(ui.DateEdit_AccessDate, SIGNAL(dateChanged(QDate)), this, SLOT(updateDateTime()));
	connect(ui.TimeEdit_AccessTime, SIGNAL(timeChanged(QTime)), this, SLOT(updateDateTime()));

	ui.Button_SelectFiles->setDefault(false);
	ui.CheckButton_CreateDateTime->setChecked(false);
	ui.CheckButton_UpdateDateTime->setChecked(false);
	ui.CheckButton_AccessDateTime->setChecked(false);

	ui.ListView_Files->setAcceptDrops(true);

	// TODO
	ui.CheckButton_TransformRecursion->setEnabled(false);
}

// 列表拖放
#pragma region Drops

void MainDialog::on_ListView_Files_dragEnterEvent(QDragEnterEvent *event) {
	if (event->mimeData()->hasFormat("text/uri-list"))
		event->acceptProposedAction();

	event->setDropAction(Qt::CopyAction);
	event->accept();
}

void MainDialog::on_ListView_Files_dragMoveEvent(QDragMoveEvent *event) {
	event->setDropAction(Qt::CopyAction);
	event->accept();
}

void MainDialog::on_ListView_Files_dropEvent(QDropEvent *event) {
	QList<QUrl> urls = event->mimeData()->urls();
	if(urls.isEmpty())
		return;

	addFileToListView(Util::getFileProps(urls));

	event->setDropAction(Qt::CopyAction);
	event->accept();
}

#pragma endregion Drops

// 文件操作
// openFileDlg Button_SelectFiles Button_AddFiles Button_DeleteFile Button_OpenDir
#pragma region FileList 

// 打开 QFileDlg 选择文件
QList<QString> MainDialog::openFileDlg() {
	auto openFileDlg = new QFileDialog(this);
	openFileDlg->setWindowTitle(tr("ファイルを選択..."));
	openFileDlg->setNameFilter(tr("ファイル(*.*)"));
	openFileDlg->setFileMode(QFileDialog::ExistingFiles);
	// openFileDlg->setAcceptMode(QFileDialog::AcceptOpen);

	if (openFileDlg->exec()) 
		return openFileDlg->selectedFiles().replaceInStrings("/", "\\");
	else
		return *(new QList<QString>());
}

// 選択...(&O)
void MainDialog::on_Button_SelectFiles_clicked() {
	auto filenameList = openFileDlg();
	if (!filenameList.empty()) {
		ui.ListView_Files->clear();
		FileLists.clear();
		addFileToListView(Util::getFileProps(filenameList));
	}
}

// 追加...(&A)
void MainDialog::on_Button_AddFiles_clicked() {
	auto filenameList = openFileDlg();
	if (!filenameList.empty()) {
		addFileToListView(Util::getFileProps(filenameList));
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
// addFileToListView updateListLabel updateListContain ListView_Files
// getSelectedItemCount getSelectedFileDir getSelectedFileDateTime getSelectedFirstFileDateTime getFileDateTimeFromDir
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

// 修改后将数据修改
void MainDialog::updateListContain(FileDateTime fileprop1, FileDateTime fileprop2) {
	FileLists.replace(FileLists.indexOf(fileprop1), fileprop2);
}

// 列表选择更改
void MainDialog::on_ListView_Files_itemSelectionChanged() {
	int cnt = getSelectedItemCount();
	ui.Button_OpenDir->setEnabled(cnt == 1);

	ui.Button_DeleteFile->setEnabled(cnt != 0);
	ui.GroupBox_TimeProp->setEnabled(cnt != 0);
	ui.Button_Transform->setEnabled(cnt != 0);

	ui.RadioButton_AllFileProp->setEnabled(cnt != 1 && cnt != 0);
	ui.RadioButton_OneFileProp->setEnabled(cnt != 1 && cnt != 0);

	if (cnt != 0) {
		FileDateTime *fdt = getSelectedFirstFileDateTime();	
		if (fdt != nullptr)
			setDateTimeOfOneFile(*fdt);
	}
	if (cnt == 1)
		ui.RadioButton_AllFileProp->setChecked(true);

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
	foreach (QString dir, getSelectedFileDir()) {
		FileDateTime *fdt = getFileDateTimeFromDir(dir);
		if (fdt != nullptr)
			ret.append(*fdt);
	}
	return ret;
}

// 获得选中的第一条信息
FileDateTime *MainDialog::getSelectedFirstFileDateTime() {
	if (ui.ListView_Files->selectedItems().length() > 0) {
		QString dir = ui.ListView_Files->selectedItems().at(0)->text();
		return getFileDateTimeFromDir(dir);
	}
	return nullptr;
}

// 根据文件路径获取时间信息
FileDateTime *MainDialog::getFileDateTimeFromDir(QString dir) {
	// TODO 算法待改
	for (int i = 0; i < FileLists.count(); i++) 
		if (dir == FileLists.at(i).FileDir)
			return const_cast<FileDateTime *>(&(FileLists.at(i)));
	return nullptr;
}

#pragma endregion ListView

// 日期操作
// Button_CreateNow Button_UpdateNow Button_AccessNow Button_CreateDefault Button_UpdateDefault Button_AccessDefault
// setDateTimeOfOneFile updateDateTime
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

// 作成日時(&C) デフォルト
void MainDialog::on_Button_CreateDefault_clicked() {
	FileDateTime *fdt = getSelectedFirstFileDateTime();
	if (fdt != nullptr) {
		ui.DateEdit_CreateDate->setDateTime(fdt->CreateTime);
		ui.TimeEdit_CreateTime->setDateTime(fdt->CreateTime);
	}
}

// 更新日時(&U) デフォルト
void MainDialog::on_Button_UpdateDefault_clicked() {
	FileDateTime *fdt = getSelectedFirstFileDateTime();
	if (fdt != nullptr) {
		ui.DateEdit_UpdateDate->setDateTime(fdt->UpdateTime);
		ui.TimeEdit_UpdateTime->setDateTime(fdt->UpdateTime);
	}
}

// ｱｸｾｽ日時(&E) デフォルト
void MainDialog::on_Button_AccessDefault_clicked() {
	FileDateTime *fdt = getSelectedFirstFileDateTime();
	if (fdt != nullptr) {
		ui.DateEdit_AccessDate->setDateTime(fdt->AccessTime);
		ui.TimeEdit_AccessTime->setDateTime(fdt->AccessTime);
	}
}

void MainDialog::setDateTimeOfOneFile(FileDateTime fdt) {
	ui.DateEdit_CreateDate->setDateTime(fdt.CreateTime);
	ui.TimeEdit_CreateTime->setDateTime(fdt.CreateTime);
	ui.DateEdit_UpdateDate->setDateTime(fdt.UpdateTime);
	ui.TimeEdit_UpdateTime->setDateTime(fdt.UpdateTime);
	ui.DateEdit_AccessDate->setDateTime(fdt.AccessTime);
	ui.TimeEdit_AccessTime->setDateTime(fdt.AccessTime);
};

// 根据 Config 同步更新数据
void MainDialog::updateDateTime() {

	if (Config::IsCreateDateTimeUseUpdate) {
		ui.DateEdit_CreateDate->setDateTime(ui.DateEdit_UpdateDate->dateTime());
		ui.TimeEdit_CreateTime->setDateTime(ui.TimeEdit_UpdateTime->dateTime());
	}
	else if (Config::IsCreateDateTimeUseAccess) {
		ui.DateEdit_CreateDate->setDateTime(ui.DateEdit_AccessDate->dateTime());
		ui.TimeEdit_CreateTime->setDateTime(ui.TimeEdit_AccessTime->dateTime());
	}

	if (Config::IsUpdateDateTimeUseCreate) {
		ui.DateEdit_UpdateDate->setDateTime(ui.DateEdit_CreateDate->dateTime());
		ui.TimeEdit_UpdateTime->setDateTime(ui.TimeEdit_CreateTime->dateTime());
	}
	else if (Config::IsUpdateDateTimeUseAccess) {
		ui.DateEdit_UpdateDate->setDateTime(ui.DateEdit_AccessDate->dateTime());
		ui.TimeEdit_UpdateTime->setDateTime(ui.TimeEdit_AccessTime->dateTime());
	}

	if (Config::IsAccessDateTimeUseCreate) {
		ui.DateEdit_AccessDate->setDateTime(ui.DateEdit_CreateDate->dateTime());
		ui.TimeEdit_AccessTime->setDateTime(ui.TimeEdit_CreateTime->dateTime());
	}
	else if (Config::IsAccessDateTimeUseUpdate) {
		ui.DateEdit_AccessDate->setDateTime(ui.DateEdit_UpdateDate->dateTime());
		ui.TimeEdit_AccessTime->setDateTime(ui.TimeEdit_UpdateTime->dateTime());
	}
}

#pragma endregion DateTime

// 配置操作和一些 UI 交互
// RadioButton CheckButton
#pragma region Toggled

// すべてのファイルを同一の日時に変更する
void MainDialog::on_RadioButton_AllFileProp_toggled(bool isChecked) {
	Config::IsAllFileProp = isChecked;

	ui.RadioButton_Create_Create->setEnabled(Config::IsCreateDateTimeTransform && isChecked);
	ui.RadioButton_Update_Update->setEnabled(Config::IsUpdateDateTimeTransform && isChecked);
	ui.RadioButton_Access_Access->setEnabled(Config::IsAccessDateTimeTransform && isChecked);
}

// ファイルごとに別々の日時に変更する
void MainDialog::on_RadioButton_OneFileProp_toggled(bool isChecked) {
	Config::IsAllFileProp = !isChecked;
}

// 作成日時(&C) UI <<
void MainDialog::on_CheckButton_CreateDateTime_toggled(bool isChecked) {
	Config::IsCreateDateTimeTransform = isChecked;

	ui.DateEdit_CreateDate->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);
	ui.TimeEdit_CreateTime->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);
	ui.Button_CreateNow->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);
	ui.Button_CreateDefault->setEnabled(Config::IsCreateDateTimeUseCreate && isChecked);

	ui.RadioButton_Create_Create->setEnabled(Config::IsAllFileProp && isChecked);
}

// 更新日時(&U) UI <<
void MainDialog::on_CheckButton_UpdateDateTime_toggled(bool isChecked) {
	Config::IsUpdateDateTimeTransform = isChecked;

	ui.DateEdit_UpdateDate->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);
	ui.TimeEdit_UpdateTime->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);
	ui.Button_UpdateNow->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);
	ui.Button_UpdateDefault->setEnabled(Config::IsUpdateDateTimeUseUpdate && isChecked);

	ui.RadioButton_Update_Update->setEnabled(Config::IsAllFileProp && isChecked);
}

// ｱｸｾｽ日時(&E) UI <<
void MainDialog::on_CheckButton_AccessDateTime_toggled(bool isChecked) {
	Config::IsAccessDateTimeTransform = isChecked;

	ui.DateEdit_AccessDate->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);
	ui.TimeEdit_AccessTime->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);
	ui.Button_AccessNow->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);
	ui.Button_AccessDefault->setEnabled(Config::IsAccessDateTimeUseAccess && isChecked);

	ui.RadioButton_Access_Access->setEnabled(Config::IsAllFileProp && isChecked);
}

// 作成日時(&C) 別の日時
void MainDialog::on_RadioButton_Create_Create_toggled(bool isChecked) {
	Config::IsCreateDateTimeUseCreate = isChecked;
	updateDateTime();
}

// 作成日時(&C) 更新日時と合わせ
void MainDialog::on_RadioButton_Create_Update_toggled(bool isChecked) {
	Config::IsCreateDateTimeUseUpdate = isChecked;
	updateDateTime();
}

// 作成日時(&C) ｱｸｾｽ日時と合わせ
void MainDialog::on_RadioButton_Create_Access_toggled(bool isChecked) {
	Config::IsCreateDateTimeUseAccess = isChecked;
	updateDateTime();
}

// 更新日時(&U) 別の日時
void MainDialog::on_RadioButton_Update_Update_toggled(bool isChecked) {
	Config::IsUpdateDateTimeUseUpdate = isChecked;
	updateDateTime();
}

// 更新日時(&U) 作成日時と合わせ
void MainDialog::on_RadioButton_Update_Create_toggled(bool isChecked) {
	Config::IsUpdateDateTimeUseCreate = isChecked;
	updateDateTime();
}

// 更新日時(&U) ｱｸｾｽ日時と合わせ
void MainDialog::on_RadioButton_Update_Access_toggled(bool isChecked) {
	Config::IsUpdateDateTimeUseAccess = isChecked;
	updateDateTime();
}

// ｱｸｾｽ日時(&E) 別の日時
void MainDialog::on_RadioButton_Access_Access_toggled(bool isChecked) {
	Config::IsAccessDateTimeUseAccess = isChecked;
	updateDateTime();
}

// ｱｸｾｽ日時(&E) 作成日時と合わせ
void MainDialog::on_RadioButton_Access_Create_toggled(bool isChecked) {
	Config::IsAccessDateTimeUseCreate = isChecked;
	updateDateTime();
}

// ｱｸｾｽ日時(&E) 更新日時と合わせ
void MainDialog::on_RadioButton_Access_Update_toggled(bool isChecked) {
	Config::IsAccessDateTimeUseUpdate = isChecked;
	updateDateTime();
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
// transformAllFiles transformOneFile Button_Transform
#pragma region Transform

// すべてのファイルを同一の日時に変更する
void MainDialog::transformAllFiles() {
	QDateTime *CreatePDT = nullptr;
	QDateTime *UpdatePDT = nullptr;
	QDateTime *AccessPDT = nullptr;

	if (Config::IsCreateDateTimeTransform)
		CreatePDT = new QDateTime(ui.DateEdit_CreateDate->date(), ui.TimeEdit_CreateTime->time());
	if (Config::IsUpdateDateTimeTransform)
		UpdatePDT = new QDateTime(ui.DateEdit_UpdateDate->date(), ui.TimeEdit_UpdateTime->time());
	if (Config::IsAccessDateTimeTransform)
		AccessPDT = new QDateTime(ui.DateEdit_AccessDate->date(), ui.TimeEdit_AccessTime->time());

	QList<QString> failedItems;
	auto allFileItems = getSelectedFileDateTime();
	foreach (auto fdt, allFileItems) {

		// フォルダーの日時を変更する
		if (!(Config::IsTransformFolderAlso) && Util::isFolder(fdt.FileDir))
			continue;

		// Update Prop
		// fdt = getOneFileProp(fdt.FileDir);

		CreatePDT = (CreatePDT == nullptr) ? &fdt.CreateTime : CreatePDT;
		UpdatePDT = (UpdatePDT == nullptr) ? &fdt.UpdateTime : UpdatePDT;
		AccessPDT = (AccessPDT == nullptr) ? &fdt.AccessTime : AccessPDT;

		if (!(Util::SetFileDateTime(fdt.FileDir, CreatePDT, UpdatePDT, AccessPDT))) {
			QMessageBox::critical(this, tr("エラー"), tr("ファイル \"%1\" の日時の変更は失敗しました。").arg(fdt.FileDir));
			failedItems.append(fdt.FileDir);
		}
		else 
			updateListContain(fdt, *(new FileDateTime(fdt.FileDir, *CreatePDT, *UpdatePDT, *AccessPDT)));
	}
	QString msg = tr("完了しました。%1 個のファイルの変更は成功して、%2 個のファイルの変更は失敗しました。")
		.arg(allFileItems.size() - failedItems.size())
		.arg(failedItems.size());
	if (!(failedItems.isEmpty())) {
		msg.append(tr("失敗項目は下記：\n"));
		foreach (auto item, failedItems) {
			msg.append(QString("\n%1").arg(item));
		}
		QMessageBox::information(this, tr("エラー"), msg, QMessageBox::Yes);
	}
	else
		QMessageBox::information(this, tr("成功"), msg, QMessageBox::Yes);
	delete CreatePDT, UpdatePDT, AccessPDT;
}

// ファイルごとに別々の日時に変更する
void MainDialog::transformOneFile() {
	QList<QString> failedItems;
	auto allFileItems = getSelectedFileDateTime();
	foreach (auto fdt, allFileItems) {

		// フォルダーの日時を変更する
		if (!(Config::IsTransformFolderAlso) && Util::isFolder(fdt.FileDir))
			continue;

		// Update Prop
		// fdt = getOneFileProp(fdt.FileDir);

		QDateTime *CreatePDT = &(fdt.CreateTime);
		QDateTime *UpdatePDT = &(fdt.UpdateTime);
		QDateTime *AccessPDT = &(fdt.AccessTime);

		if (Config::IsCreateDateTimeTransform)
			if (Config::IsCreateDateTimeUseUpdate)
				CreatePDT = &(fdt.UpdateTime);
			else if (Config::IsCreateDateTimeUseAccess)
				CreatePDT = &(fdt.AccessTime);

		if (Config::IsUpdateDateTimeTransform)
			if (Config::IsUpdateDateTimeUseCreate)
				UpdatePDT = &(fdt.CreateTime);
			else if (Config::IsUpdateDateTimeUseAccess)
				UpdatePDT = &(fdt.AccessTime);

		if (Config::IsAccessDateTimeTransform)
			if (Config::IsAccessDateTimeUseCreate)
				AccessPDT = &(fdt.CreateTime);
			else if (Config::IsAccessDateTimeUseUpdate)
				AccessPDT = &(fdt.UpdateTime);

		if (!(Util::SetFileDateTime(fdt.FileDir, CreatePDT, UpdatePDT, AccessPDT))) {
			QMessageBox::critical(this, tr("エラー"), tr("ファイル \"%1\" の日時の変更は失敗しました。").arg(fdt.FileDir));
			failedItems.append(fdt.FileDir);
		}
		else {
			CreatePDT = (CreatePDT == nullptr) ? &fdt.CreateTime : CreatePDT;
			UpdatePDT = (UpdatePDT == nullptr) ? &fdt.UpdateTime : UpdatePDT;
			AccessPDT = (AccessPDT == nullptr) ? &fdt.AccessTime : AccessPDT;
			updateListContain(fdt, *(new FileDateTime(fdt.FileDir, *CreatePDT, *UpdatePDT, *AccessPDT)));
		}

		// delete CreatePDT, UpdatePDT, AccessPDT;
	}
	QString msg = tr("完了しました。%1 個のファイルの変更は成功して、%2 個のファイルの変更は失敗しました。")
		.arg(allFileItems.size() - failedItems.size())
		.arg(failedItems.size());
	if (!(failedItems.isEmpty())) {
		msg.append(tr("失敗項目は下記：\n"));
		foreach (auto item, failedItems) {
			msg.append(QString("\n%1").arg(item));
		}
		QMessageBox::information(this, tr("エラー"), msg, QMessageBox::Yes);
	}
	else
		QMessageBox::information(this, tr("成功"), msg, QMessageBox::Yes);
}

// 変更(&T)
void MainDialog::on_Button_Transform_clicked() {
	if (Config::IsAllFileProp) 
		// 直接将UI数据写入
		transformAllFiles();
	else 
		// 为每个文件更新
		transformOneFile();
}

#pragma endregion Transform