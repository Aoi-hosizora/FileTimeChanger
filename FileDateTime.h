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

	bool operator==(FileDateTime fdt) {
		return this->FileDir == fdt.FileDir &&
			this->CreateTime == fdt.CreateTime &&
			this->UpdateTime == fdt.UpdateTime &&
			this->AccessTime == fdt.AccessTime;
	}
};

#endif // FILEDATETIME_H