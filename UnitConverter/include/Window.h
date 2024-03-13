#pragma once

#include <iostream>
#include <iomanip>
#include <gtkmm.h>
#include <gtkmm/window.h>
#include <gtkmm/comboboxtext.h>
#include <gtkmm/liststore.h>
#include <gtkmm/cssProvider.h>
#include <gtk-4.0/gtk/gtk.h>
#include <cmath>

# define M_PI 3.14159265358979323846

struct MeasurementUnit 
{
    Glib::ustring name;
    double conversionFactor;
};

class Window : public Gtk::Window
{
public:
    Window();
    virtual ~Window();

private: 
    // Signal handlers:
    void on_unitsType_combo_changed();
    void on_units_combo_changed();
    void on_entryFrom_changed();
    void on_entryTo_changed();

    void convert_value(Gtk::ComboBox& m_unitsFrom_Combo, Gtk::ComboBox& m_unitsTo_Combo, Gtk::Entry& m_EntryFrom, Gtk::Entry& m_EntryTo);
    double get_conversion_factor(Glib::ustring name);

    // Tree model columns:
    class ModelColumns : public Gtk::TreeModel::ColumnRecord
    {
    public:

        ModelColumns()
        {
            add(m_col_name);
        }

        Gtk::TreeModelColumn<Glib::ustring> m_col_name;
    };

    ModelColumns m_Columns;

    // Units ComboBox Widget:
    Gtk::ComboBox m_units_Combo;
    Gtk::CellRendererText m_units_cell;
    Glib::RefPtr<Gtk::ListStore> m_units_refTreeModel;

    // Units from which to convert ComboBox Widget:
    Gtk::ComboBox m_unitsFrom_Combo;
    Gtk::CellRendererText m_unitsFrom_cell;
    Glib::RefPtr<Gtk::ListStore> m_unitsFrom_refTreeModel;

    // Units to which to convert ComboBox Widget:
    Gtk::ComboBox m_unitsTo_Combo;
    Gtk::CellRendererText m_unitsTo_cell;
    Glib::RefPtr<Gtk::ListStore> m_unitsTo_refTreeModel;

    Gtk::Entry m_EntryFrom;
    Gtk::Entry m_EntryTo;

    std::map<Glib::ustring, std::vector<MeasurementUnit>> unitsMap = {
        {"Area", {{"Square kilometre", 1e+6}, {"Square metre", 1.0}, {"Square mile", 2.58999e+6}, {"Square yard", 0.836127}, {"Square foot", 0.092903}, {"Square inch", 6.4516e-4}, {"Hectare", 1e+4}, {"Acre", 4046.86}}},

        {"Data Transfer Rate", {{"Bit per second", 1.0}, {"Kilobit per second", 1e+3}, {"Kilobyte per second", 1e+3 / 8}, {"Megabit per second", 1e+6}, {"Megabyte per second", 1e+6 / 8}, {"Mebibit per second", 1e+6 * 1.049}, {"Gigabit per second", 1e+9}, {"Gigabyte per second", 1e+9 / 8}, {"Gibibit per second", 1e+9 * 1.074}, {"Terabit per second", 1e+12}, {"Terabyte per second", 1e+12 / 8}, {"Tebibit per second", 1e+12 * 1.1}}},

        {"Digital Storage", {{"Bit", 1.0}, {"Kilobit", 1e+3}, {"Kibibit", 1e+3 * 1.024}, {"Megabit", 1e+6}, {"Mebibit", 1e+6 * 1.049}, {"Gigabit", 1e+9}, {"Gibibit", 1e+9 * 1.074}, {"Terabit", 1e+12}, {"Tebibit", 1e+12 * 1.1}, {"Petabit", 1e+15}, {"Pebibit", 1e+15 * 1.126}, {"Byte", 8.0}, {"Kilobyte", 8e+3}, {"Kibibyte", 8e+3 * 1.024}, {"Megabyte", 8e+6}, {"Mebibyte", 8e+6 * 1.049}, {"Gigabyte", 8e+9}, {"Gibibyte", 8e+9 * 1.074}, {"Terabyte", 8e+12}, {"Tebibyte", 8e+12 * 1.1}, {"Petabyte", 8e+15}, {"Pebibyte", 8e+15 * 1.126}}},

        {"Energy", {{"Joule", 1.0}, {"Kilojoule", 1e+3}, {"Gram calorie", 4.184}, {"Kilocalorie", 4184.0}, {"Watt hour", 3600.0}, {"Kilowatt-hour", 3.6e+6}, {"Electronvolt", 1.6022e-19}, {"British thermal unit", 1055.06}, {"US therm", 1.0548e+8}, {"Foot-pound", 1.35582}}},

        {"Frequency", {{"Hertz", 1.0}, {"Kilohertz", 1e+3}, {"Megahertz", 1e+6}, {"Gigahertz", 1e+9}}},

        {"Fuel Economy", {{"Mile per US gallon", 1.0 / 3.7854}, {"Mile per gallon", 1.0 / 4.54609}, {"Kilometer per liter", 1.0}, {"Litre per 100 kilometres", 100.0}}},

        {"Length", {{"Kilometer", 1e+3}, {"Meter", 1.0}, {"Centimeter", 1e-2}, {"Millimeter", 1e-3}, {"Micrometer", 1e-6}, {"Nanometer", 1e-9}, {"Mile", 1609.34}, {"Yard", 0.9144}, {"Foot", 0.3048}, {"Inch", 0.0254}, {"Nautical mile", 1852.0}}},

        {"Mass", {{"Tonne", 1e+6}, {"Kilogram", 1e+3}, {"Milligram", 1e-3}, {"Microgram", 1e-6}, {"Imperial ton", 1.0160e+6}, {"US ton", 9.0718e+5}, {"Stone", 6.3503e+3}, {"Pound", 453.592}, {"Ounce", 28.3495}}},

        {"Plane Angle", {{"Arcsecond", 4.84814e-6}, {"Degree", 1.0}, {"Gradian", 0.9}, {"Milliradian", 1e-3}, {"Minute of arc", 0.0166667}, {"Radian", 180.0 / M_PI}}},

        {"Pressure", {{"Atmosphere", 101325.0}, {"Bar", 1e+5}, {"Pascal", 1.0}, {"Torr", 133.322}, {"Pound-force per square inch", 6894.76}}},

        {"Speed", {{"Miles per hour", 0.44704}, {"Foot per second", 0.3048}, {"Meter per second", 1.0}, {"Kilometer per hour", 3.6}, {"Knot", 0.514444}}},

        {"Temperature", {{"Celsius", 0.0}, {"Fahrenheit", 0.0}, {"Kelvin", 0.0}}},

        {"Time", {{"Microsecond", 1e-6}, {"Nanosecond", 1e-9}, {"Millisecond", 1e-3}, {"Second", 1.0}, {"Minute", 60.0}, {"Hour", 3600.0}, {"Day", 86400.0}, {"Week", 604800.0}, {"Month", 2629746.0}, {"Year", 31556952.0}, {"Decade", 315569520.0}, {"Century", 3155695200.0}}},

        {"Volume", {{"US liquid gallon", 0.0037854}, {"US liquid quart", 9.46353e-4}, {"US liquid pint", 4.73176e-4}, {"US legal cup", 2.36588e-4}, {"US fluid ounce", 2.95735e-5}, {"US tablespoon", 1.47868e-5}, {"US teaspoon", 4.92892e-6},{"Cubic meter", 1.0}, {"Liter", 1e-3}, {"Milliliter", 1e-6}, {"Imperial gallon", 0.00454609}, {"Imperial quart", 0.00113652}, {"Imperial pint", 5.68261e-4}, {"Imperial cup", 2.84131e-4}, {"Imperial fluid ounce", 2.84131e-5}, {"Imperial tablespoon", 1.78354e-5}, {"Imperial teaspoon", 5.94512e-6}, {"Cubic foot", 0.0283168}, {"Cubic inch", 1.63871e-5}}}
    };

    struct TemperatureConversion {
        double factor;
        double offset;
    };

    std::map<std::string, std::map<std::string, TemperatureConversion>> temperatureConversions = {
        {"Celsius", {
            {"Fahrenheit", {1.8, 32.0}},
            {"Kelvin", {1.0, 273.15}}
        }},
        {"Fahrenheit", {
            {"Celsius", {0.55555555556, -17.7777777778}},
            {"Kelvin", {0.55555555556, 255.372222222}}
        }},
        {"Kelvin", {
            {"Celsius", {1.0, -273.15}},
            {"Fahrenheit", {1.8, -459.67}}
        }}
    };

    bool converting;
};