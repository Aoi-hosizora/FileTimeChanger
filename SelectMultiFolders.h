#ifndef MYFILESELECT_H
#define MYFILESELECT_H

#include <QWidget>
#include <QFileDialog>
#include <QListView>
#include <QTreeView>
#include <QDialogButtonBox>
class myFileSelect :public QFileDialog
{
	Q_OBJECT
public:
	explicit myFileSelect(QWidget *parent = 0);

signals:

	public slots:
		void go();
};

#endif // MYFILESELECT_H