﻿/*
 * Copyright (C) 2018-2019 wuuhii. All rights reserved.
 *
 * The file is encoding with utf-8 (with BOM). It is a part of QtSwissArmyKnife
 * project. The project is a open source project, you can get the source from:
 *     https://github.com/wuuhii/QtSwissArmyKnife
 *     https://gitee.com/wuuhii/QtSwissArmyKnife
 *
 * If you want to know more about the project, please join our QQ group(952218522).
 * In addition, the email address of the project author is wuuhii@outlook.com.
 */
#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMenu>
#include <QLabel>
#include <QAction>
#include <QMetaEnum>
#include <QTabWidget>
#include <QMessageBox>
#include <QHBoxLayout>
#include <QMainWindow>
#include <QTranslator>

class SAKVersion;
class UpdateManager;
class MoreInformation;

namespace Ui {
class SAKMainWindow;
}

class SAKMainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SAKMainWindow(QWidget *parent = nullptr);
    ~SAKMainWindow();

private:
    QTabWidget* mpTabWidget             = nullptr;
    Ui::SAKMainWindow* ui               = nullptr;
    QMenu* toolsMenu                    = nullptr;
    QMenu *languageMenu                 = nullptr;
    QAction *defaultStyleSheetAction    = nullptr;
    SAKVersion* versionDialog           = nullptr;
    UpdateManager* updateManager        = nullptr;
    MoreInformation* moreInformation    = nullptr;   

    QTranslator qtTranslator;
    QTranslator qtBaeTranslator;
    QTranslator sakTranslator;

    const char* appStyleKey = "Universal/appStyle";
    const char* appStylesheetKey = "Universal/appStylesheet";
    const char* settingStringLanguage = "Universal/language";
    /// ----------------------------------------------------
    void AddTab();    
    void AddTool();

    void addTool(QString toolName, QWidget *toolWidget);
    void changeStylesheet(QString styleSheetName);
    void changeAppStyle(QString appStyle);

    void initMenu();
    void initFileMenu();
    void initToolMenu();
    void initOptionMenu();
    void initLanguageMenu();
    void initHelpMenu();


    void installLanguage();
    void installLanguageFromLocale(QString language);
    void addRemovablePage();
    void openIODeviceWindow();
    QWidget *getDebugPage(int type);
    void closeDebugPage(int index);
    void About();
private:
    void createCRCCalculator();
};

#endif // MAINWINDOW_H