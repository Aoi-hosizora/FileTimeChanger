#include "DropableListWidget.h"

#include <QMouseEvent>
#include <QApplication>
#include <QDrag>
#include <QMimeData>

DropableListWidget::DropableListWidget(QWidget *parent) : QListWidget(parent) {
	this->setAcceptDrops(true);
}