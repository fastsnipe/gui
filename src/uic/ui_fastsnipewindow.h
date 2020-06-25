/********************************************************************************
** Form generated from reading UI file 'fastsnipewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FASTSNIPEWINDOW_H
#define UI_FASTSNIPEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FastSnipeWindow
{
public:
    QWidget *centralwidget;
    QLabel *lblStage1R;
    QLabel *lblStage1;
    QLineEdit *txtEmail;
    QLabel *lblEmail;
    QPushButton *btnLogin;
    QLabel *label;
    QLineEdit *txtUUID;
    QLabel *lblASUUID;
    QLineEdit *txtUsername;
    QLabel *lblASName;
    QLabel *lblStatus;
    QLabel *lblStage2R;
    QLabel *lblStage2;
    QPushButton *btnSave;
    QLineEdit *txtWantedName;
    QLabel *lblWantedName;
    QSlider *sldThreads;
    QLabel *lblThreads;
    QLineEdit *txtPassword;
    QLabel *lblPassword;
    QLineEdit *txtToken;
    QLabel *lblToken;

    void setupUi(QMainWindow *FastSnipeWindow)
    {
        if (FastSnipeWindow->objectName().isEmpty())
            FastSnipeWindow->setObjectName(QString::fromUtf8("FastSnipeWindow"));
        FastSnipeWindow->setWindowModality(Qt::NonModal);
        FastSnipeWindow->resize(531, 307);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(FastSnipeWindow->sizePolicy().hasHeightForWidth());
        FastSnipeWindow->setSizePolicy(sizePolicy);
        FastSnipeWindow->setMinimumSize(QSize(531, 307));
        FastSnipeWindow->setMaximumSize(QSize(531, 307));
        centralwidget = new QWidget(FastSnipeWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        lblStage1R = new QLabel(centralwidget);
        lblStage1R->setObjectName(QString::fromUtf8("lblStage1R"));
        lblStage1R->setGeometry(QRect(40, 10, 251, 41));
        lblStage1 = new QLabel(centralwidget);
        lblStage1->setObjectName(QString::fromUtf8("lblStage1"));
        lblStage1->setGeometry(QRect(10, 10, 21, 41));
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        lblStage1->setFont(font);
        txtEmail = new QLineEdit(centralwidget);
        txtEmail->setObjectName(QString::fromUtf8("txtEmail"));
        txtEmail->setGeometry(QRect(100, 50, 191, 20));
        lblEmail = new QLabel(centralwidget);
        lblEmail->setObjectName(QString::fromUtf8("lblEmail"));
        lblEmail->setGeometry(QRect(40, 50, 61, 20));
        QFont font1;
        font1.setPointSize(9);
        lblEmail->setFont(font1);
        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setGeometry(QRect(40, 140, 251, 23));
        btnLogin->setFlat(false);
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(310, 12, 131, 21));
        QFont font2;
        font2.setPointSize(10);
        label->setFont(font2);
        txtUUID = new QLineEdit(centralwidget);
        txtUUID->setObjectName(QString::fromUtf8("txtUUID"));
        txtUUID->setGeometry(QRect(310, 110, 211, 20));
        txtUUID->setReadOnly(true);
        lblASUUID = new QLabel(centralwidget);
        lblASUUID->setObjectName(QString::fromUtf8("lblASUUID"));
        lblASUUID->setGeometry(QRect(310, 90, 61, 20));
        lblASUUID->setFont(font1);
        txtUsername = new QLineEdit(centralwidget);
        txtUsername->setObjectName(QString::fromUtf8("txtUsername"));
        txtUsername->setGeometry(QRect(310, 70, 211, 20));
        txtUsername->setReadOnly(true);
        lblASName = new QLabel(centralwidget);
        lblASName->setObjectName(QString::fromUtf8("lblASName"));
        lblASName->setGeometry(QRect(310, 50, 61, 20));
        lblASName->setFont(font1);
        lblStatus = new QLabel(centralwidget);
        lblStatus->setObjectName(QString::fromUtf8("lblStatus"));
        lblStatus->setGeometry(QRect(310, 30, 121, 16));
        lblStage2R = new QLabel(centralwidget);
        lblStage2R->setObjectName(QString::fromUtf8("lblStage2R"));
        lblStage2R->setEnabled(true);
        lblStage2R->setGeometry(QRect(40, 170, 251, 41));
        lblStage2 = new QLabel(centralwidget);
        lblStage2->setObjectName(QString::fromUtf8("lblStage2"));
        lblStage2->setEnabled(true);
        lblStage2->setGeometry(QRect(10, 170, 21, 41));
        lblStage2->setFont(font);
        btnSave = new QPushButton(centralwidget);
        btnSave->setObjectName(QString::fromUtf8("btnSave"));
        btnSave->setGeometry(QRect(450, 270, 71, 23));
        txtWantedName = new QLineEdit(centralwidget);
        txtWantedName->setObjectName(QString::fromUtf8("txtWantedName"));
        txtWantedName->setEnabled(true);
        txtWantedName->setGeometry(QRect(100, 210, 191, 20));
        lblWantedName = new QLabel(centralwidget);
        lblWantedName->setObjectName(QString::fromUtf8("lblWantedName"));
        lblWantedName->setEnabled(true);
        lblWantedName->setGeometry(QRect(40, 210, 61, 20));
        lblWantedName->setFont(font1);
        sldThreads = new QSlider(centralwidget);
        sldThreads->setObjectName(QString::fromUtf8("sldThreads"));
        sldThreads->setEnabled(true);
        sldThreads->setGeometry(QRect(120, 240, 171, 22));
        sldThreads->setMinimum(1);
        sldThreads->setMaximum(50);
        sldThreads->setPageStep(5);
        sldThreads->setValue(20);
        sldThreads->setOrientation(Qt::Horizontal);
        sldThreads->setInvertedAppearance(false);
        lblThreads = new QLabel(centralwidget);
        lblThreads->setObjectName(QString::fromUtf8("lblThreads"));
        lblThreads->setEnabled(true);
        lblThreads->setGeometry(QRect(40, 240, 81, 20));
        lblThreads->setFont(font1);
        txtPassword = new QLineEdit(centralwidget);
        txtPassword->setObjectName(QString::fromUtf8("txtPassword"));
        txtPassword->setGeometry(QRect(100, 80, 191, 20));
        txtPassword->setEchoMode(QLineEdit::Password);
        lblPassword = new QLabel(centralwidget);
        lblPassword->setObjectName(QString::fromUtf8("lblPassword"));
        lblPassword->setGeometry(QRect(40, 80, 61, 20));
        lblPassword->setFont(font1);
        txtToken = new QLineEdit(centralwidget);
        txtToken->setObjectName(QString::fromUtf8("txtToken"));
        txtToken->setGeometry(QRect(100, 110, 191, 20));
        lblToken = new QLabel(centralwidget);
        lblToken->setObjectName(QString::fromUtf8("lblToken"));
        lblToken->setGeometry(QRect(40, 110, 61, 20));
        lblToken->setFont(font1);
        FastSnipeWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(txtEmail, txtPassword);
        QWidget::setTabOrder(txtPassword, txtToken);
        QWidget::setTabOrder(txtToken, btnLogin);
        QWidget::setTabOrder(btnLogin, txtWantedName);
        QWidget::setTabOrder(txtWantedName, sldThreads);
        QWidget::setTabOrder(sldThreads, btnSave);
        QWidget::setTabOrder(btnSave, txtUsername);
        QWidget::setTabOrder(txtUsername, txtUUID);

        retranslateUi(FastSnipeWindow);

        QMetaObject::connectSlotsByName(FastSnipeWindow);
    } // setupUi

    void retranslateUi(QMainWindow *FastSnipeWindow)
    {
        FastSnipeWindow->setWindowTitle(QCoreApplication::translate("FastSnipeWindow", "FastSnipeWindow", nullptr));
        lblStage1R->setText(QCoreApplication::translate("FastSnipeWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Login with your Mojang account<br/></span><span style=\" color:#a6a6a6;\">Your login details will only be shared with Mojang</span></p></body></html>", nullptr));
        lblStage1->setText(QCoreApplication::translate("FastSnipeWindow", "1", nullptr));
        lblEmail->setText(QCoreApplication::translate("FastSnipeWindow", "Email", nullptr));
        btnLogin->setText(QCoreApplication::translate("FastSnipeWindow", "Login", nullptr));
        label->setText(QCoreApplication::translate("FastSnipeWindow", "Authentication Status", nullptr));
        lblASUUID->setText(QCoreApplication::translate("FastSnipeWindow", "UUID", nullptr));
        lblASName->setText(QCoreApplication::translate("FastSnipeWindow", "Name", nullptr));
        lblStatus->setText(QCoreApplication::translate("FastSnipeWindow", "Not Logged In", nullptr));
        lblStage2R->setText(QCoreApplication::translate("FastSnipeWindow", "<html><head/><body><p><span style=\" font-size:10pt;\">Sniper settings<br/></span><span style=\" color:#a6a6a6;\">Configure your wanted name and thread count</span></p></body></html>", nullptr));
        lblStage2->setText(QCoreApplication::translate("FastSnipeWindow", "2", nullptr));
        btnSave->setText(QCoreApplication::translate("FastSnipeWindow", "Save", nullptr));
        lblWantedName->setText(QCoreApplication::translate("FastSnipeWindow", "Name", nullptr));
        lblThreads->setText(QCoreApplication::translate("FastSnipeWindow", "Threads (20)", nullptr));
        lblPassword->setText(QCoreApplication::translate("FastSnipeWindow", "Password", nullptr));
        lblToken->setText(QCoreApplication::translate("FastSnipeWindow", "Token", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FastSnipeWindow: public Ui_FastSnipeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FASTSNIPEWINDOW_H
