#ifndef FILEDATETIME_H
#define FILEDATETIME_H

class FileDateTime {

public:
	FileDateTime(QString fileDir, QDateTime createTime, QDateTime updateTime, QDateTime accessTime) : 
		FileDir(fileDir), CreateTime(createTime), UpdateTime(updateTime), AccessTime(accessTime) {};

	QString FileDir;

	QDateTime CreateTime;
	QDateTime UpdateTime;
	QDateTime AccessTime;
};

#endif // FILEDATETIME_H