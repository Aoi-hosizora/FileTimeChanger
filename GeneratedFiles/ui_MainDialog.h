/********************************************************************************
** Form generated from reading UI file 'MainDialog.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_MainDialogClass
{
public:

    void setupUi(QDialog *MainDialogClass)
    {
        if (MainDialogClass->objectName().isEmpty())
            MainDialogClass->setObjectName(QStringLiteral("MainDialogClass"));
        MainDialogClass->resize(600, 400);

        retranslateUi(MainDialogClass);

        QMetaObject::connectSlotsByName(MainDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MainDialogClass)
    {
        MainDialogClass->setWindowTitle(QApplication::translate("MainDialogClass", "FileTimeChanger", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialogClass: public Ui_MainDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
