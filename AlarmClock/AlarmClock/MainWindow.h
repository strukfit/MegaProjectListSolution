#pragma once

#include "UI.h"
#include <QTime>
#include <QTimer>
#include <QtWidgets/QMessageBox>
#include "SetAlarmWindow.h"
#include "AlarmClockWidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr);
    ~MainWindow();

public slots:
    void setAlarm(const QTime& time);
    void checkAlarm();
    void openSetAlarmWindow();

private:
    Ui::MainWindowClass* ui;
};