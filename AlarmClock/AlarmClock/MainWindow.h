#pragma once

#include "UI.h"
#include <QTime>
#include <QTimer>
#include <qmessagebox.h>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void setAlarm(const QTime& time);
    void checkAlarm();

private:
    Ui::MainWindowClass* ui;

    QTime alarmTime;
};