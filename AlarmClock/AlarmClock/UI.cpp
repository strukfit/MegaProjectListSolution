#include "UI.h"

void UI::setupMainWindowUI(QMainWindow* MainWindowClass)
{
	mainWindowCentralWidget = new QWidget(MainWindowClass);

	vBoxLayout = new QVBoxLayout(mainWindowCentralWidget);
	
	alarmsListWidget = new QListWidget(mainWindowCentralWidget);

	mainWindowSetAlarmButton = new QPushButton("openSetAlarmWindowButton", mainWindowCentralWidget);
	mainWindowSetAlarmButton->setObjectName("mainWindowSetAlarmButton");

	vBoxLayout->addWidget(alarmsListWidget);
	vBoxLayout->addWidget(mainWindowSetAlarmButton);

	MainWindowClass->setLayout(vBoxLayout);

	MainWindowClass->setCentralWidget(mainWindowCentralWidget);

	QMetaObject::connectSlotsByName(MainWindowClass);

}

void UI::setupSetAlarmWindowUI(QDialog* SetAlarmWindowClass)
{
	setAlarmWindowVLayout = new QVBoxLayout(SetAlarmWindowClass);

	lineEdit1 = new QLineEdit(SetAlarmWindowClass);

	lineEdit2 = new QLineEdit(SetAlarmWindowClass);

	setAlarmWindowSetAlarmButton = new QPushButton("setAlarmButton", SetAlarmWindowClass);
	setAlarmWindowSetAlarmButton->setObjectName("setAlarmWindowSetAlarmButton");

	setAlarmWindowVLayout->addWidget(lineEdit1);
	setAlarmWindowVLayout->addWidget(lineEdit2);
	setAlarmWindowVLayout->addWidget(setAlarmWindowSetAlarmButton);

	SetAlarmWindowClass->setLayout(setAlarmWindowVLayout);

	QMetaObject::connectSlotsByName(SetAlarmWindowClass);
}

void UI::setupAlarmClockWidgetUI(QWidget* AlarmClockWidgetClass)
{
	//AlarmClockWidgetClass->resize(100, 100);

	//AlarmClockWidgetClass->setStyleSheet("background-color: black;");

	//alarmClockWidgetCentralWidget = new QWidget(AlarmClockWidgetClass);
	
	gBoxLayout = new QGridLayout(AlarmClockWidgetClass);

	time = new QLabel(AlarmClockWidgetClass);

	name = new QLabel(AlarmClockWidgetClass);

	testButton = new QPushButton("test", AlarmClockWidgetClass);

	gBoxLayout->addWidget(time, 0, 0);
	gBoxLayout->addWidget(name, 1, 0);
	gBoxLayout->addWidget(testButton, 0, 1);

	AlarmClockWidgetClass->setLayout(gBoxLayout);

	QMetaObject::connectSlotsByName(AlarmClockWidgetClass);
}
