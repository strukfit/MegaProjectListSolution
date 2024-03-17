#include "AlarmClockWidget.h"

int AlarmClockWidget::count = 0;

AlarmClockWidget::AlarmClockWidget(QWidget* parent, int id, QTime time, QString name) :
	QWidget(parent), 
	ui(new Ui::AlarmClockWidgetClass), 
	id(id), 
	alarmTime(time), 
	name(name), 
	alarmTriggered(false)
{
	ui->setupAlarmClockWidgetUI(this);

	ui->time->setText(time.toString("hh:mm"));
	ui->name->setText(name);

	count++;
}

void AlarmClockWidget::setAlarmTriggered(bool flag)
{
	this->alarmTriggered = flag;
}

int AlarmClockWidget::getId()
{
	return this->id;
}

QTime AlarmClockWidget::getAlarmTime()
{
	return this->alarmTime;
}

QString AlarmClockWidget::getName()
{
	return this->name;
}

bool AlarmClockWidget::isAlarmTriggered()
{
	return this->alarmTriggered;
}

void AlarmClockWidget::addAlarm(const QTime& time)
{

}