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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTimeEdit>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MainDialogClass
{
public:
    QVBoxLayout *verticalLayout_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *Label_FileListCnt;
    QSpacerItem *horizontalSpacer_11;
    QListWidget *ListView_Files;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *Button_SelectFiles;
    QPushButton *Button_AddFiles;
    QPushButton *Button_DeleteFile;
    QPushButton *Button_OpenDir;
    QHBoxLayout *horizontalLayout_7;
    QFrame *frame_4;
    QVBoxLayout *verticalLayout;
    QRadioButton *RadioButton_AllFileProp;
    QRadioButton *RadioButton_OneFileProp;
    QSpacerItem *horizontalSpacer_10;
    QFrame *line;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_6;
    QFrame *frame;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QCheckBox *CheckButton_CreateDateTime;
    QSpacerItem *horizontalSpacer_6;
    QDateEdit *DateEdit_CreateDate;
    QTimeEdit *TimeEdit_CreateTime;
    QPushButton *Button_CreateNow;
    QHBoxLayout *horizontalLayout_9;
    QSpacerItem *horizontalSpacer_3;
    QRadioButton *RadioButton_Create_Create;
    QRadioButton *RadioButton_Create_Update;
    QRadioButton *RadioButton_Create_Access;
    QFrame *line_2;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *CheckButton_UpdateDateTime;
    QSpacerItem *horizontalSpacer_7;
    QDateEdit *DateEdit_UpdateDate;
    QTimeEdit *TimeEdit_UpdateTime;
    QPushButton *Button_UpdateNow;
    QHBoxLayout *horizontalLayout_10;
    QSpacerItem *horizontalSpacer_4;
    QRadioButton *RadioButton_Update_Update;
    QRadioButton *RadioButton_Update_Create;
    QRadioButton *RadioButton_Update_Access;
    QFrame *line_3;
    QFrame *frame_3;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *CheckButton_AccessDateTime;
    QSpacerItem *horizontalSpacer_8;
    QDateEdit *DateEdit_AccessDate;
    QTimeEdit *TimeEdit_AccessTime;
    QPushButton *Button_AccessNow;
    QHBoxLayout *horizontalLayout_11;
    QSpacerItem *horizontalSpacer_5;
    QRadioButton *RadioButton_Access_Access;
    QRadioButton *RadioButton_Access_Create;
    QRadioButton *RadioButton_Access_Update;
    QHBoxLayout *horizontalLayout_6;
    QFrame *frame_5;
    QVBoxLayout *verticalLayout_5;
    QCheckBox *CheckButton_TransformFolderAlso;
    QCheckBox *CheckButton_TransformRecursion;
    QSpacerItem *horizontalSpacer_9;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *Button_Transform;
    QPushButton *Button_Cancel;

    void setupUi(QDialog *MainDialogClass)
    {
        if (MainDialogClass->objectName().isEmpty())
            MainDialogClass->setObjectName(QStringLiteral("MainDialogClass"));
        MainDialogClass->resize(429, 663);
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI"));
        MainDialogClass->setFont(font);
        verticalLayout_7 = new QVBoxLayout(MainDialogClass);
        verticalLayout_7->setSpacing(6);
        verticalLayout_7->setContentsMargins(11, 11, 11, 11);
        verticalLayout_7->setObjectName(QStringLiteral("verticalLayout_7"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        Label_FileListCnt = new QLabel(MainDialogClass);
        Label_FileListCnt->setObjectName(QStringLiteral("Label_FileListCnt"));

        horizontalLayout_8->addWidget(Label_FileListCnt);

        horizontalSpacer_11 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_11);


        verticalLayout_7->addLayout(horizontalLayout_8);

        ListView_Files = new QListWidget(MainDialogClass);
        ListView_Files->setObjectName(QStringLiteral("ListView_Files"));
        ListView_Files->setSelectionMode(QAbstractItemView::ExtendedSelection);

        verticalLayout_7->addWidget(ListView_Files);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        Button_SelectFiles = new QPushButton(MainDialogClass);
        Button_SelectFiles->setObjectName(QStringLiteral("Button_SelectFiles"));

        horizontalLayout_2->addWidget(Button_SelectFiles);

        Button_AddFiles = new QPushButton(MainDialogClass);
        Button_AddFiles->setObjectName(QStringLiteral("Button_AddFiles"));

        horizontalLayout_2->addWidget(Button_AddFiles);

        Button_DeleteFile = new QPushButton(MainDialogClass);
        Button_DeleteFile->setObjectName(QStringLiteral("Button_DeleteFile"));
        Button_DeleteFile->setEnabled(false);

        horizontalLayout_2->addWidget(Button_DeleteFile);

        Button_OpenDir = new QPushButton(MainDialogClass);
        Button_OpenDir->setObjectName(QStringLiteral("Button_OpenDir"));
        Button_OpenDir->setEnabled(false);

        horizontalLayout_2->addWidget(Button_OpenDir);


        verticalLayout_7->addLayout(horizontalLayout_2);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        frame_4 = new QFrame(MainDialogClass);
        frame_4->setObjectName(QStringLiteral("frame_4"));
        frame_4->setFrameShape(QFrame::StyledPanel);
        frame_4->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame_4);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(1, 1, 1, 1);
        RadioButton_AllFileProp = new QRadioButton(frame_4);
        RadioButton_AllFileProp->setObjectName(QStringLiteral("RadioButton_AllFileProp"));
        RadioButton_AllFileProp->setChecked(true);

        verticalLayout->addWidget(RadioButton_AllFileProp);

        RadioButton_OneFileProp = new QRadioButton(frame_4);
        RadioButton_OneFileProp->setObjectName(QStringLiteral("RadioButton_OneFileProp"));

        verticalLayout->addWidget(RadioButton_OneFileProp);


        horizontalLayout_7->addWidget(frame_4);

        horizontalSpacer_10 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_10);


        verticalLayout_7->addLayout(horizontalLayout_7);

        line = new QFrame(MainDialogClass);
        line->setObjectName(QStringLiteral("line"));
        line->setFrameShape(QFrame::HLine);
        line->setFrameShadow(QFrame::Sunken);

        verticalLayout_7->addWidget(line);

        groupBox = new QGroupBox(MainDialogClass);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_6 = new QVBoxLayout(groupBox);
        verticalLayout_6->setSpacing(6);
        verticalLayout_6->setContentsMargins(11, 11, 11, 11);
        verticalLayout_6->setObjectName(QStringLiteral("verticalLayout_6"));
        frame = new QFrame(groupBox);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        CheckButton_CreateDateTime = new QCheckBox(frame);
        CheckButton_CreateDateTime->setObjectName(QStringLiteral("CheckButton_CreateDateTime"));
        CheckButton_CreateDateTime->setChecked(true);

        horizontalLayout_3->addWidget(CheckButton_CreateDateTime);

        horizontalSpacer_6 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_6);

        DateEdit_CreateDate = new QDateEdit(frame);
        DateEdit_CreateDate->setObjectName(QStringLiteral("DateEdit_CreateDate"));

        horizontalLayout_3->addWidget(DateEdit_CreateDate);

        TimeEdit_CreateTime = new QTimeEdit(frame);
        TimeEdit_CreateTime->setObjectName(QStringLiteral("TimeEdit_CreateTime"));

        horizontalLayout_3->addWidget(TimeEdit_CreateTime);

        Button_CreateNow = new QPushButton(frame);
        Button_CreateNow->setObjectName(QStringLiteral("Button_CreateNow"));

        horizontalLayout_3->addWidget(Button_CreateNow);


        verticalLayout_2->addLayout(horizontalLayout_3);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_9->addItem(horizontalSpacer_3);

        RadioButton_Create_Create = new QRadioButton(frame);
        RadioButton_Create_Create->setObjectName(QStringLiteral("RadioButton_Create_Create"));
        RadioButton_Create_Create->setChecked(true);

        horizontalLayout_9->addWidget(RadioButton_Create_Create);

        RadioButton_Create_Update = new QRadioButton(frame);
        RadioButton_Create_Update->setObjectName(QStringLiteral("RadioButton_Create_Update"));

        horizontalLayout_9->addWidget(RadioButton_Create_Update);

        RadioButton_Create_Access = new QRadioButton(frame);
        RadioButton_Create_Access->setObjectName(QStringLiteral("RadioButton_Create_Access"));

        horizontalLayout_9->addWidget(RadioButton_Create_Access);


        verticalLayout_2->addLayout(horizontalLayout_9);


        verticalLayout_6->addWidget(frame);

        line_2 = new QFrame(groupBox);
        line_2->setObjectName(QStringLiteral("line_2"));
        line_2->setFrameShape(QFrame::HLine);
        line_2->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_2);

        frame_2 = new QFrame(groupBox);
        frame_2->setObjectName(QStringLiteral("frame_2"));
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_3 = new QVBoxLayout(frame_2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        CheckButton_UpdateDateTime = new QCheckBox(frame_2);
        CheckButton_UpdateDateTime->setObjectName(QStringLiteral("CheckButton_UpdateDateTime"));
        CheckButton_UpdateDateTime->setChecked(true);

        horizontalLayout_4->addWidget(CheckButton_UpdateDateTime);

        horizontalSpacer_7 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_7);

        DateEdit_UpdateDate = new QDateEdit(frame_2);
        DateEdit_UpdateDate->setObjectName(QStringLiteral("DateEdit_UpdateDate"));

        horizontalLayout_4->addWidget(DateEdit_UpdateDate);

        TimeEdit_UpdateTime = new QTimeEdit(frame_2);
        TimeEdit_UpdateTime->setObjectName(QStringLiteral("TimeEdit_UpdateTime"));

        horizontalLayout_4->addWidget(TimeEdit_UpdateTime);

        Button_UpdateNow = new QPushButton(frame_2);
        Button_UpdateNow->setObjectName(QStringLiteral("Button_UpdateNow"));

        horizontalLayout_4->addWidget(Button_UpdateNow);


        verticalLayout_3->addLayout(horizontalLayout_4);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalSpacer_4 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_10->addItem(horizontalSpacer_4);

        RadioButton_Update_Update = new QRadioButton(frame_2);
        RadioButton_Update_Update->setObjectName(QStringLiteral("RadioButton_Update_Update"));
        RadioButton_Update_Update->setChecked(true);

        horizontalLayout_10->addWidget(RadioButton_Update_Update);

        RadioButton_Update_Create = new QRadioButton(frame_2);
        RadioButton_Update_Create->setObjectName(QStringLiteral("RadioButton_Update_Create"));

        horizontalLayout_10->addWidget(RadioButton_Update_Create);

        RadioButton_Update_Access = new QRadioButton(frame_2);
        RadioButton_Update_Access->setObjectName(QStringLiteral("RadioButton_Update_Access"));

        horizontalLayout_10->addWidget(RadioButton_Update_Access);


        verticalLayout_3->addLayout(horizontalLayout_10);


        verticalLayout_6->addWidget(frame_2);

        line_3 = new QFrame(groupBox);
        line_3->setObjectName(QStringLiteral("line_3"));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);

        verticalLayout_6->addWidget(line_3);

        frame_3 = new QFrame(groupBox);
        frame_3->setObjectName(QStringLiteral("frame_3"));
        frame_3->setFrameShape(QFrame::StyledPanel);
        frame_3->setFrameShadow(QFrame::Raised);
        verticalLayout_4 = new QVBoxLayout(frame_3);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(1, 1, 1, 1);
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        CheckButton_AccessDateTime = new QCheckBox(frame_3);
        CheckButton_AccessDateTime->setObjectName(QStringLiteral("CheckButton_AccessDateTime"));
        CheckButton_AccessDateTime->setChecked(true);

        horizontalLayout_5->addWidget(CheckButton_AccessDateTime);

        horizontalSpacer_8 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer_8);

        DateEdit_AccessDate = new QDateEdit(frame_3);
        DateEdit_AccessDate->setObjectName(QStringLiteral("DateEdit_AccessDate"));

        horizontalLayout_5->addWidget(DateEdit_AccessDate);

        TimeEdit_AccessTime = new QTimeEdit(frame_3);
        TimeEdit_AccessTime->setObjectName(QStringLiteral("TimeEdit_AccessTime"));

        horizontalLayout_5->addWidget(TimeEdit_AccessTime);

        Button_AccessNow = new QPushButton(frame_3);
        Button_AccessNow->setObjectName(QStringLiteral("Button_AccessNow"));

        horizontalLayout_5->addWidget(Button_AccessNow);


        verticalLayout_4->addLayout(horizontalLayout_5);

        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalSpacer_5 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_11->addItem(horizontalSpacer_5);

        RadioButton_Access_Access = new QRadioButton(frame_3);
        RadioButton_Access_Access->setObjectName(QStringLiteral("RadioButton_Access_Access"));
        RadioButton_Access_Access->setChecked(true);

        horizontalLayout_11->addWidget(RadioButton_Access_Access);

        RadioButton_Access_Create = new QRadioButton(frame_3);
        RadioButton_Access_Create->setObjectName(QStringLiteral("RadioButton_Access_Create"));

        horizontalLayout_11->addWidget(RadioButton_Access_Create);

        RadioButton_Access_Update = new QRadioButton(frame_3);
        RadioButton_Access_Update->setObjectName(QStringLiteral("RadioButton_Access_Update"));

        horizontalLayout_11->addWidget(RadioButton_Access_Update);


        verticalLayout_4->addLayout(horizontalLayout_11);


        verticalLayout_6->addWidget(frame_3);

        line_3->raise();
        line_2->raise();
        frame->raise();
        frame_2->raise();
        frame_3->raise();

        verticalLayout_7->addWidget(groupBox);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        frame_5 = new QFrame(MainDialogClass);
        frame_5->setObjectName(QStringLiteral("frame_5"));
        frame_5->setFrameShape(QFrame::StyledPanel);
        frame_5->setFrameShadow(QFrame::Raised);
        verticalLayout_5 = new QVBoxLayout(frame_5);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(1, 1, 1, 1);
        CheckButton_TransformFolderAlso = new QCheckBox(frame_5);
        CheckButton_TransformFolderAlso->setObjectName(QStringLiteral("CheckButton_TransformFolderAlso"));
        CheckButton_TransformFolderAlso->setChecked(true);

        verticalLayout_5->addWidget(CheckButton_TransformFolderAlso);

        CheckButton_TransformRecursion = new QCheckBox(frame_5);
        CheckButton_TransformRecursion->setObjectName(QStringLiteral("CheckButton_TransformRecursion"));

        verticalLayout_5->addWidget(CheckButton_TransformRecursion);


        horizontalLayout_6->addWidget(frame_5);

        horizontalSpacer_9 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_6->addItem(horizontalSpacer_9);


        verticalLayout_7->addLayout(horizontalLayout_6);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

        Button_Transform = new QPushButton(MainDialogClass);
        Button_Transform->setObjectName(QStringLiteral("Button_Transform"));

        horizontalLayout->addWidget(Button_Transform);

        Button_Cancel = new QPushButton(MainDialogClass);
        Button_Cancel->setObjectName(QStringLiteral("Button_Cancel"));

        horizontalLayout->addWidget(Button_Cancel);


        verticalLayout_7->addLayout(horizontalLayout);

        ListView_Files->raise();
        groupBox->raise();
        line->raise();
#ifndef QT_NO_SHORTCUT
        Label_FileListCnt->setBuddy(ListView_Files);
#endif // QT_NO_SHORTCUT
        QWidget::setTabOrder(ListView_Files, Button_SelectFiles);
        QWidget::setTabOrder(Button_SelectFiles, Button_AddFiles);
        QWidget::setTabOrder(Button_AddFiles, Button_DeleteFile);
        QWidget::setTabOrder(Button_DeleteFile, Button_OpenDir);
        QWidget::setTabOrder(Button_OpenDir, RadioButton_AllFileProp);
        QWidget::setTabOrder(RadioButton_AllFileProp, RadioButton_OneFileProp);
        QWidget::setTabOrder(RadioButton_OneFileProp, CheckButton_CreateDateTime);
        QWidget::setTabOrder(CheckButton_CreateDateTime, DateEdit_CreateDate);
        QWidget::setTabOrder(DateEdit_CreateDate, TimeEdit_CreateTime);
        QWidget::setTabOrder(TimeEdit_CreateTime, Button_CreateNow);
        QWidget::setTabOrder(Button_CreateNow, RadioButton_Create_Create);
        QWidget::setTabOrder(RadioButton_Create_Create, RadioButton_Create_Update);
        QWidget::setTabOrder(RadioButton_Create_Update, RadioButton_Create_Access);
        QWidget::setTabOrder(RadioButton_Create_Access, CheckButton_UpdateDateTime);
        QWidget::setTabOrder(CheckButton_UpdateDateTime, DateEdit_UpdateDate);
        QWidget::setTabOrder(DateEdit_UpdateDate, TimeEdit_UpdateTime);
        QWidget::setTabOrder(TimeEdit_UpdateTime, Button_UpdateNow);
        QWidget::setTabOrder(Button_UpdateNow, RadioButton_Update_Update);
        QWidget::setTabOrder(RadioButton_Update_Update, RadioButton_Update_Create);
        QWidget::setTabOrder(RadioButton_Update_Create, RadioButton_Update_Access);
        QWidget::setTabOrder(RadioButton_Update_Access, CheckButton_AccessDateTime);
        QWidget::setTabOrder(CheckButton_AccessDateTime, DateEdit_AccessDate);
        QWidget::setTabOrder(DateEdit_AccessDate, TimeEdit_AccessTime);
        QWidget::setTabOrder(TimeEdit_AccessTime, Button_AccessNow);
        QWidget::setTabOrder(Button_AccessNow, RadioButton_Access_Access);
        QWidget::setTabOrder(RadioButton_Access_Access, RadioButton_Access_Create);
        QWidget::setTabOrder(RadioButton_Access_Create, RadioButton_Access_Update);
        QWidget::setTabOrder(RadioButton_Access_Update, CheckButton_TransformFolderAlso);
        QWidget::setTabOrder(CheckButton_TransformFolderAlso, CheckButton_TransformRecursion);
        QWidget::setTabOrder(CheckButton_TransformRecursion, Button_Transform);
        QWidget::setTabOrder(Button_Transform, Button_Cancel);

        retranslateUi(MainDialogClass);
        QObject::connect(Button_Cancel, SIGNAL(clicked()), MainDialogClass, SLOT(reject()));
        QObject::connect(CheckButton_CreateDateTime, SIGNAL(toggled(bool)), RadioButton_Create_Create, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_CreateDateTime, SIGNAL(toggled(bool)), RadioButton_Create_Update, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_CreateDateTime, SIGNAL(toggled(bool)), RadioButton_Create_Access, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_UpdateDateTime, SIGNAL(toggled(bool)), RadioButton_Update_Update, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_UpdateDateTime, SIGNAL(toggled(bool)), RadioButton_Update_Create, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_UpdateDateTime, SIGNAL(toggled(bool)), RadioButton_Update_Access, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_AccessDateTime, SIGNAL(toggled(bool)), RadioButton_Access_Access, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_AccessDateTime, SIGNAL(toggled(bool)), RadioButton_Access_Create, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_AccessDateTime, SIGNAL(toggled(bool)), RadioButton_Access_Update, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_AccessDateTime, SIGNAL(toggled(bool)), DateEdit_AccessDate, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_AccessDateTime, SIGNAL(toggled(bool)), TimeEdit_AccessTime, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_UpdateDateTime, SIGNAL(toggled(bool)), DateEdit_UpdateDate, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_UpdateDateTime, SIGNAL(toggled(bool)), TimeEdit_UpdateTime, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_CreateDateTime, SIGNAL(toggled(bool)), TimeEdit_CreateTime, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_CreateDateTime, SIGNAL(toggled(bool)), DateEdit_CreateDate, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_CreateDateTime, SIGNAL(toggled(bool)), Button_CreateNow, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_UpdateDateTime, SIGNAL(toggled(bool)), Button_UpdateNow, SLOT(setEnabled(bool)));
        QObject::connect(CheckButton_AccessDateTime, SIGNAL(toggled(bool)), Button_AccessNow, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Create_Create, SIGNAL(toggled(bool)), DateEdit_CreateDate, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Create_Create, SIGNAL(toggled(bool)), TimeEdit_CreateTime, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Create_Create, SIGNAL(toggled(bool)), Button_CreateNow, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Create_Update, SIGNAL(toggled(bool)), DateEdit_CreateDate, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Create_Update, SIGNAL(toggled(bool)), TimeEdit_CreateTime, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Create_Update, SIGNAL(toggled(bool)), Button_CreateNow, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Create_Access, SIGNAL(toggled(bool)), DateEdit_CreateDate, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Create_Access, SIGNAL(toggled(bool)), TimeEdit_CreateTime, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Create_Access, SIGNAL(toggled(bool)), Button_CreateNow, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Update_Update, SIGNAL(toggled(bool)), DateEdit_UpdateDate, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Update_Update, SIGNAL(toggled(bool)), TimeEdit_UpdateTime, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Update_Update, SIGNAL(toggled(bool)), Button_UpdateNow, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Update_Create, SIGNAL(toggled(bool)), DateEdit_UpdateDate, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Update_Create, SIGNAL(toggled(bool)), TimeEdit_UpdateTime, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Update_Create, SIGNAL(toggled(bool)), Button_UpdateNow, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Update_Access, SIGNAL(toggled(bool)), DateEdit_UpdateDate, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Update_Access, SIGNAL(toggled(bool)), TimeEdit_UpdateTime, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Update_Access, SIGNAL(toggled(bool)), Button_UpdateNow, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Access_Access, SIGNAL(toggled(bool)), DateEdit_AccessDate, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Access_Access, SIGNAL(toggled(bool)), TimeEdit_AccessTime, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Access_Access, SIGNAL(toggled(bool)), Button_AccessNow, SLOT(setEnabled(bool)));
        QObject::connect(RadioButton_Access_Create, SIGNAL(toggled(bool)), DateEdit_AccessDate, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Access_Create, SIGNAL(toggled(bool)), TimeEdit_AccessTime, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Access_Create, SIGNAL(toggled(bool)), Button_AccessNow, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Access_Update, SIGNAL(toggled(bool)), DateEdit_AccessDate, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Access_Update, SIGNAL(toggled(bool)), TimeEdit_AccessTime, SLOT(setDisabled(bool)));
        QObject::connect(RadioButton_Access_Update, SIGNAL(toggled(bool)), Button_AccessNow, SLOT(setDisabled(bool)));

        QMetaObject::connectSlotsByName(MainDialogClass);
    } // setupUi

    void retranslateUi(QDialog *MainDialogClass)
    {
        MainDialogClass->setWindowTitle(QApplication::translate("MainDialogClass", "FileTimeChanger", 0));
        Label_FileListCnt->setText(QApplication::translate("MainDialogClass", "\343\203\225\343\202\241\343\202\244\343\203\253\343\203\252\343\202\271\343\203\210 (0/0)(&L):", 0));
        Button_SelectFiles->setText(QApplication::translate("MainDialogClass", "\351\201\270\346\212\236...(&O)", 0));
        Button_AddFiles->setText(QApplication::translate("MainDialogClass", "\350\277\275\345\212\240...(&A)", 0));
        Button_DeleteFile->setText(QApplication::translate("MainDialogClass", "\345\211\212\351\231\244(&D)", 0));
        Button_OpenDir->setText(QApplication::translate("MainDialogClass", "\345\240\264\346\211\200\343\202\222\351\226\213\343\201\217...(&F)", 0));
        RadioButton_AllFileProp->setText(QApplication::translate("MainDialogClass", "\343\201\231\343\201\271\343\201\246\343\201\256\343\203\225\343\202\241\343\202\244\343\203\253\343\202\222\345\220\214\344\270\200\343\201\256\346\227\245\346\231\202\343\201\253\345\244\211\346\233\264\343\201\231\343\202\213", 0));
        RadioButton_OneFileProp->setText(QApplication::translate("MainDialogClass", "\343\203\225\343\202\241\343\202\244\343\203\253\343\201\224\343\201\250\343\201\253\345\210\245\343\200\205\343\201\256\346\227\245\346\231\202\343\201\253\345\244\211\346\233\264\343\201\231\343\202\213", 0));
        groupBox->setTitle(QApplication::translate("MainDialogClass", "\346\227\245\346\231\202\343\203\227\343\203\255\343\203\225\343\202\241\343\202\244\343\203\253", 0));
        CheckButton_CreateDateTime->setText(QApplication::translate("MainDialogClass", "\344\275\234\346\210\220\346\227\245\346\231\202(&C):", 0));
        Button_CreateNow->setText(QApplication::translate("MainDialogClass", "\347\217\276\345\234\250\346\227\245\346\231\202\343\201\253", 0));
        RadioButton_Create_Create->setText(QApplication::translate("MainDialogClass", "\345\210\245\343\201\256\346\227\245\346\231\202", 0));
        RadioButton_Create_Update->setText(QApplication::translate("MainDialogClass", "\346\233\264\346\226\260\346\227\245\346\231\202\343\201\250\345\220\210\343\202\217\343\201\233", 0));
        RadioButton_Create_Access->setText(QApplication::translate("MainDialogClass", "\357\275\261\357\275\270\357\275\276\357\275\275\346\227\245\346\231\202\343\201\250\345\220\210\343\202\217\343\201\233", 0));
        CheckButton_UpdateDateTime->setText(QApplication::translate("MainDialogClass", "\346\233\264\346\226\260\346\227\245\346\231\202(&U):", 0));
        Button_UpdateNow->setText(QApplication::translate("MainDialogClass", "\347\217\276\345\234\250\346\227\245\346\231\202\343\201\253", 0));
        RadioButton_Update_Update->setText(QApplication::translate("MainDialogClass", "\345\210\245\343\201\256\346\227\245\346\231\202", 0));
        RadioButton_Update_Create->setText(QApplication::translate("MainDialogClass", "\344\275\234\346\210\220\346\227\245\346\231\202\343\201\250\345\220\210\343\202\217\343\201\233", 0));
        RadioButton_Update_Access->setText(QApplication::translate("MainDialogClass", "\357\275\261\357\275\270\357\275\276\357\275\275\346\227\245\346\231\202\343\201\250\345\220\210\343\202\217\343\201\233", 0));
        CheckButton_AccessDateTime->setText(QApplication::translate("MainDialogClass", "\357\275\261\357\275\270\357\275\276\357\275\275\346\227\245\346\231\202(&E):", 0));
        Button_AccessNow->setText(QApplication::translate("MainDialogClass", "\347\217\276\345\234\250\346\227\245\346\231\202\343\201\253", 0));
        RadioButton_Access_Access->setText(QApplication::translate("MainDialogClass", "\345\210\245\343\201\256\346\227\245\346\231\202", 0));
        RadioButton_Access_Create->setText(QApplication::translate("MainDialogClass", "\344\275\234\346\210\220\346\227\245\346\231\202\343\201\250\345\220\210\343\202\217\343\201\233", 0));
        RadioButton_Access_Update->setText(QApplication::translate("MainDialogClass", "\346\233\264\346\226\260\346\227\245\346\231\202\343\201\250\345\220\210\343\202\217\343\201\233", 0));
        CheckButton_TransformFolderAlso->setText(QApplication::translate("MainDialogClass", "\343\203\225\343\202\251\343\203\253\343\203\200\343\203\274\343\201\256\346\227\245\346\231\202\343\202\222\345\244\211\346\233\264\343\201\231\343\202\213", 0));
        CheckButton_TransformRecursion->setText(QApplication::translate("MainDialogClass", "\343\203\225\343\202\251\343\203\253\343\203\200\343\203\274\345\206\205\343\201\256\343\203\225\343\202\241\343\202\244\343\203\253\343\201\256\346\227\245\346\231\202\343\202\202\345\244\211\346\233\264\343\201\231\343\202\213", 0));
        Button_Transform->setText(QApplication::translate("MainDialogClass", "\345\244\211\346\233\264(&T)", 0));
        Button_Cancel->setText(QApplication::translate("MainDialogClass", "\343\202\255\343\203\243\343\203\263\343\202\273\343\203\253(&X)", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialogClass: public Ui_MainDialogClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
