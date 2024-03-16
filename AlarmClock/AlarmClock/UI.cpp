#include "UI.h"

void UI::setupUI(QMainWindow* MainWindowClass)
{
	centralWidget = new QWidget(MainWindowClass);

	button = new QPushButton(centralWidget);
}
