#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qpushbutton.h>

class UI
{
public:
	void setupUI(QMainWindow* MainWindowClass);

	QWidget* centralWidget;
	QPushButton* button;

private:
	QMainWindow* MainWindowClass;
};

namespace Ui {
	class MainWindowClass : public UI {};
} // namespace Ui