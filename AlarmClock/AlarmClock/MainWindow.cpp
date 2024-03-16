#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent) :
	QMainWindow(parent), ui(new Ui::MainWindowClass)
{
	ui->setupUI(this);

	connect(ui->button, &QPushButton::pressed, this, [&] {
		//QTime alarmTime = QTime::fromString(timeEdit->text(), "hh:mm");
		//setAlarm(QTime(23, 4));
	});
}

MainWindow::~MainWindow()
{
}

void MainWindow::setAlarm(const QTime& time)
{
	alarmTime = time;
	QTimer::singleShot(1000, this, &MainWindow::checkAlarm);
	QMessageBox::information(this, "Success!", "Alarm set for " + time.toString("hh::mm:ss"));
}

void MainWindow::checkAlarm()
{
	QTime currentTime = QTime::currentTime();
	if (currentTime >= alarmTime && currentTime < alarmTime.addSecs(5)) {
		QMessageBox::information(nullptr, "Alarm", "The alarm went off!");
	}
	QTimer::singleShot(1000, this, &MainWindow::checkAlarm);
}