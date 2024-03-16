#include "UI.h"

void UI::setupUi(QMainWindow* UnitConverterClass)
{
    UnitConverterClass->setWindowTitle("Unit Converter");

    centralWidget = new QWidget(UnitConverterClass);

    vLayout = new QVBoxLayout(centralWidget);

    vLayout->setSpacing(12);
    vLayout->setContentsMargins(11, 11, 11, 11);

    unitTypeComboBox = new QComboBox(centralWidget);
    unitTypeComboBox->setObjectName("unitTypeComboBox");
    unitTypeComboBox->setStyleSheet("height: 30; border: 1px solid #303134; background-color: #383434; color: white;");

    vLayout->addWidget(unitTypeComboBox);

    gLayout = new QGridLayout();
    gLayout->setVerticalSpacing(0);
    gLayout->setHorizontalSpacing(6);

    lineEditFrom = new QLineEdit(centralWidget);
    lineEditFrom->setObjectName("lineEditFrom");
    lineEditFrom->setAlignment(Qt::AlignCenter);
    lineEditFrom->setEnabled(true);
    lineEditFrom->setStyleSheet("height: 40; border: 1px solid #303134; background-color: #202124; color: white; font-size: 16px; font-weight: bold;");
    
    lineEditTo = new QLineEdit(centralWidget);
    lineEditTo->setObjectName("lineEditTo");
    lineEditTo->setAlignment(Qt::AlignCenter);
    lineEditTo->setEnabled(true);
    lineEditTo->setStyleSheet("height: 40; border: 1px solid #303134; background-color: #202124; color: white; font-size: 16px; font-weight: bold;");

    unitFromComboBox = new QComboBox(centralWidget);
    unitFromComboBox->setObjectName("unitFromComboBox");
    unitFromComboBox->setStyleSheet("height: 30; border: 1px solid #303134; background-color: #383434; color: #c0c4c4;");
    unitToComboBox = new QComboBox(centralWidget);
    unitToComboBox->setObjectName("unitToComboBox");
    unitToComboBox->setStyleSheet("height: 30; border: 1px solid #303134; background-color: #383434; color: #c0c4c4;");

    equalText = new QLabel("=", centralWidget);
    equalText->setStyleSheet("color: white; font-size: 16px; font-weight: bold;");

    gLayout->addWidget(lineEditFrom, 0, 0);
    gLayout->addWidget(unitFromComboBox, 1, 0);
    gLayout->addWidget(equalText, 0, 1);
    gLayout->addWidget(lineEditTo, 0, 2);
    gLayout->addWidget(unitToComboBox, 1, 2);

    vLayout->addLayout(gLayout);

    UnitConverterClass->setLayout(vLayout);

    UnitConverterClass->setCentralWidget(centralWidget);

    QMetaObject::connectSlotsByName(UnitConverterClass);
}