#include "UnitConverter.h"

UnitConverter::UnitConverter(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::UnitConverterClass)
{
    ui->setupUi(this);

    setStyleSheet("background-color: #202124;");

    // Filling the unitTypeComboBox with unit types values
    for(const auto& unit: unitsMap)
    {
        ui->unitTypeComboBox->addItem(unit.first);
    }

    fillUnitsComboBoxes(0);

    connect(ui->unitTypeComboBox, &QComboBox::currentIndexChanged, this, &UnitConverter::on_unitsType_combo_changed);
    connect(ui->unitFromComboBox, &QComboBox::currentIndexChanged, this, &UnitConverter::on_units_combo_changed);
    connect(ui->unitToComboBox, &QComboBox::currentIndexChanged, this, &UnitConverter::on_units_combo_changed);
    connect(ui->lineEditFrom, &QLineEdit::textChanged, this, &UnitConverter::on_lineEdit_changed);
    connect(ui->lineEditTo, &QLineEdit::textChanged, this, &UnitConverter::on_lineEdit_changed);
}

UnitConverter::~UnitConverter()
{}

void UnitConverter::on_unitsType_combo_changed()
{
    ui->unitFromComboBox->clear();
    ui->unitToComboBox->clear();

    ui->lineEditFrom->clear();
    ui->lineEditTo->clear();

    fillUnitsComboBoxes(ui->unitTypeComboBox->currentIndex());
}

void UnitConverter::on_units_combo_changed()
{
    if(!ui->lineEditFrom->text().isEmpty())
        convert_value(ui->unitFromComboBox, ui->unitToComboBox, ui->lineEditFrom, ui->lineEditTo);
}

void UnitConverter::fillUnitsComboBoxes(int index)
{
    // Filling the unitFromComboBoxes with unit type values
    for (const auto& unit : unitsMap.at(ui->unitTypeComboBox->itemText(index)))
    {
        ui->unitFromComboBox->addItem(unit.name);
        ui->unitToComboBox->addItem(unit.name);
    }
    ui->unitToComboBox->setCurrentIndex(1);
}

void UnitConverter::on_lineEdit_changed()
{
    QLineEdit* senderLineEdit = qobject_cast<QLineEdit*>(sender());

    if (!senderLineEdit->text().isEmpty())
    {
        if (senderLineEdit == ui->lineEditFrom)
        {
            convert_value(ui->unitFromComboBox, ui->unitToComboBox, senderLineEdit, ui->lineEditTo);
        }
        else if (senderLineEdit == ui->lineEditTo)
        {
            convert_value(ui->unitToComboBox, ui->unitFromComboBox, senderLineEdit, ui->lineEditFrom);
        }
    } 
}

void UnitConverter::convert_value(QComboBox* comboFrom, QComboBox* comboTo, 
    QLineEdit* lineFrom, QLineEdit* lineTo)
{
    if (!converting)
    {
        converting = true;

        QString from = comboFrom->currentText();
        QString to = comboTo->currentText();

        const double value = lineFrom->text().toDouble();

        QString unitType = ui->unitTypeComboBox->currentText();

        double converted_value;

        if (unitType.compare("Temperature") == 0)
        {
            if (temperatureConversions.find(from) != temperatureConversions.end() &&
                temperatureConversions[from].find(to) != temperatureConversions[from].end())
            {
                const TemperatureConversion& conv = temperatureConversions[from][to];
                converted_value = value * conv.factor + conv.offset;
            }
            else
                converted_value = value;
        }
        else
        {
            const double factorFrom = get_conversion_factor(from, unitType);
            const double factorTo = get_conversion_factor(to, unitType);

            converted_value = value * (factorFrom / factorTo);
        }

        QString result;

        if (std::abs(converted_value) < 1e-3 || std::abs(converted_value) > 1e6)
        {
            std::stringstream ss;
            ss << std::scientific << std::setprecision(0) << converted_value;
            result = QString::fromStdString(ss.str());
        }
        else if (std::modf(converted_value, new double) == 0.0)
        {
            result = QString::number(static_cast<int>(converted_value));
        }
        else
        {
            result = QString::number(converted_value, 'f', 5);;
        }

        lineTo->setText(result);

        converting = false;
    }
}

double UnitConverter::get_conversion_factor(QString name, QString unitType)
{
    auto& units = unitsMap.at(unitType);

    for (const auto& unit : units)
    {
        if (unit.name == name)
            return unit.conversionFactor;
    }
    return 0;
}
