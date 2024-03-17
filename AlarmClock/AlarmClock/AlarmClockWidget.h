#pragma once
#include <QWidget>
#include <QTime>
#include "UI.h"

class AlarmClockWidget : public QWidget
{
	Q_OBJECT

public:
	AlarmClockWidget(QWidget* parent = nullptr, int id = NULL, QTime time = QTime(0, 0), QString name = NULL);

	void setAlarmTriggered(bool flag);

	int getId();
	QTime getAlarmTime();
	QString getName();
	bool isAlarmTriggered();

	static int count;

public slots:
	void addAlarm(const QTime& time);

private:
	Ui::AlarmClockWidgetClass* ui;

	int id;
	QTime alarmTime;
	QString name;

	bool alarmTriggered;
};