#pragma once

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/QLineEdit>
#include <QVBoxLayout>
#include <QGridLayout>
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qmessagebox.h>
#include <qdebug.h>

class UI
{
public:
	void setupUi(QMainWindow* UnitConverterClass);

	QLineEdit* lineEditFrom;
	QLineEdit* lineEditTo;
	QComboBox* unitTypeComboBox;
	QComboBox* unitFromComboBox;
	QComboBox* unitToComboBox;

private:
	QWidget* centralWidget;
	QVBoxLayout* vLayout;
	QGridLayout* gLayout;
	QLabel* equalText;

	QMainWindow* UnitConverterClass;
};

namespace Ui {
	class UnitConverterClass : public UI {};
} // namespace Ui