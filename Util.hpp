#include <QtCore/QFile>
#include <QtCore/QUrl>
#include <QtCore/QFileInfo>
#include <QtCore/QDateTime>
#include <Windows.h>
#include <QDebug>

#include "FileDateTime.h"

class Util {

public:

	// 获得一个文件的属性
	static FileDateTime getOneFileProp(QString fileName) {
		QFile file(fileName);
		QFileInfo finfo(file);

		QDateTime createTime = finfo.created();
		QDateTime updateTime = finfo.lastModified();
		QDateTime accessTime = finfo.lastRead();

		FileDateTime ret(fileName, createTime, updateTime, accessTime);
		return ret;
	}

	// 从 QString[] 中获得 FileDateTime[]
	static QList<FileDateTime> getFileProps(QList<QString> fileNames) {
		QList<FileDateTime> ret;
		foreach (QString fileName, fileNames)
			ret.append(getOneFileProp(fileName));
		return ret;
	}

	// 从 QUrl[] 中获得 FileDateTime[]
	static QList<FileDateTime> getFileProps(QList<QUrl> urls) {
		QList<FileDateTime> ret;
		foreach (QUrl url, urls) {
			QString fileName = url.toLocalFile().replace("/", "\\");
			ret.append(getOneFileProp(fileName));
		}
		return ret;
	}

	// QFileTime * -> FILETIME *
	// https://stackoverflow.com/questions/19704817/qdatetime-to-filetime
	static FILETIME *toWinFileTime(const QDateTime *dateTime) {
		if (dateTime == nullptr)
			return nullptr;

		// Definition of FILETIME from MSDN:
		// Contains a 64-bit value representing the number of 100-nanosecond intervals since January 1, 1601 (UTC).
		QDateTime origin(QDate(1601, 1, 1), QTime(0, 0, 0, 0), Qt::UTC);
		// Get offset - note we need 100-nanosecond intervals, hence we multiply by
		// 10000.
		qint64 _100nanosecs = 10000 * origin.msecsTo(*dateTime);
		// Pack _100nanosecs into the structure.
		auto pfileTime = new FILETIME();
		pfileTime->dwLowDateTime = _100nanosecs;
		pfileTime->dwHighDateTime = (_100nanosecs >> 32);
		return pfileTime;
	}

	static bool SetFileDateTime(QString dir, QDateTime *CreateDT, QDateTime *UpdateDT, QDateTime *AccessDT) {
		HANDLE hFile = CreateFile(dir.toStdWString().c_str(), GENERIC_READ|GENERIC_WRITE, FILE_SHARE_READ|FILE_SHARE_DELETE, NULL, OPEN_EXISTING, FILE_FLAG_BACKUP_SEMANTICS, NULL);
		if (hFile == INVALID_HANDLE_VALUE) return false;
		FILETIME *CreateFT = toWinFileTime(CreateDT);
		FILETIME *UpdateFT = toWinFileTime(UpdateDT);
		FILETIME *AccessFT = toWinFileTime(AccessDT);
		bool ret = SetFileTime(hFile, CreateFT, AccessFT, UpdateFT);
		if (hFile != NULL)
			CloseHandle(hFile);
		delete CreateFT, UpdateFT, AccessFT;
		return ret;
	}
};