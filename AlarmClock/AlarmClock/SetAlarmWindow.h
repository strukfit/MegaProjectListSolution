#pragma once
#include "UI.h"
#include "MainWindow.h"

class SetAlarmWindow : public QDialog
{
	Q_OBJECT

signals:
	void setAlarm(const QTime& time);

public:
	SetAlarmWindow(QWidget* parent = nullptr);
	~SetAlarmWindow();

private:
	Ui::SetAlarmWindowClass* ui;
};