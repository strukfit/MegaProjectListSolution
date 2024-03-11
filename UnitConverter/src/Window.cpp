#include "Window.h"

Window::Window() : converting(false)
{
    set_title("Unit Converter");

    /*auto provider = Gtk::CssProvider::create();
    provider->load_from_path("css/style.css");

    auto screen = Gdk::Display::get_default();
    auto context = Gtk::StyleContext::create();
    context->add_provider_for_screen(screen, provider, GTK_STYLE_PROVIDER_PRIORITY_APPLICATION);
    get_style_context()->add_class("window");*/

    m_units_Combo.set_margin_start(10);
    m_units_Combo.set_margin_end(10);
    m_units_Combo.set_margin_top(10);

    m_EntryFrom.set_margin_start(10);
    m_EntryFrom.set_margin_end(10);
    m_EntryFrom.set_alignment(Gtk::Align::CENTER);
     
    m_EntryTo.set_margin_start(10);
    m_EntryTo.set_margin_end(10);
    m_EntryTo.set_alignment(Gtk::Align::CENTER);

    m_unitsFrom_Combo.set_margin_start(10);
    m_unitsFrom_Combo.set_margin_end(10);
    m_unitsFrom_Combo.set_margin_bottom(10);

    m_unitsTo_Combo.set_margin_start(10);
    m_unitsTo_Combo.set_margin_end(10);
    m_unitsTo_Combo.set_margin_bottom(10);

    // Create a container to hold widgets
    auto m_mainBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL, 10);
    set_child(*m_mainBox);

    //Create the Tree model:
    m_units_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_units_Combo.set_model(m_units_refTreeModel);

    // Fill the ComboBox's Tree Model:
    Gtk::TreeRow row;

    for (const auto& unit : unitsMap)
    {
        row = *(m_units_refTreeModel->append());
        row[m_Columns.m_col_name] = unit.first;
    }

    m_units_Combo.set_active(0);

    //Add the model columns to the Combo (which is a kind of view),
    //rendering them in the default way:
    m_units_Combo.pack_start(m_Columns.m_col_name);

    // Add the ComboBox to the window.

    auto m_hBox = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::HORIZONTAL, 10);

    // Create the Tree model:
    m_unitsFrom_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_unitsFrom_Combo.set_model(m_unitsFrom_refTreeModel);

    // Fill the ComboBox's Tree Model:
    for (const auto& unit : unitsMap.at((*m_units_Combo.get_active())[m_Columns.m_col_name]))
    {
        row = *(m_unitsFrom_refTreeModel->append());
        row[m_Columns.m_col_name] = unit.name;
    }

    m_unitsFrom_Combo.set_active(0);

    //Add the model columns to the Combo (which is a kind of view),
    //rendering them in the default way:
    m_unitsFrom_Combo.pack_start(m_Columns.m_col_name);
    
    // Create the Tree model:
    m_unitsTo_refTreeModel = Gtk::ListStore::create(m_Columns);
    m_unitsTo_Combo.set_model(m_unitsTo_refTreeModel);

    // Fill the ComboBox's Tree Model:
    for (const auto& unit : unitsMap.at((*m_units_Combo.get_active())[m_Columns.m_col_name]))
    {
        row = *(m_unitsTo_refTreeModel->append());
        row[m_Columns.m_col_name] = unit.name;
    }
    
    m_unitsTo_Combo.set_active(0);

    //Add the model columns to the Combo (which is a kind of view),
    //rendering them in the default way:
    m_unitsTo_Combo.pack_start(m_Columns.m_col_name);

    //Connect signal handlers:
    m_units_Combo.signal_changed().connect(sigc::mem_fun(*this, &Window::on_unitsType_combo_changed));
    m_unitsFrom_Combo.signal_changed().connect(sigc::mem_fun(*this, &Window::on_units_combo_changed));
    m_unitsTo_Combo.signal_changed().connect(sigc::mem_fun(*this, &Window::on_units_combo_changed));

    m_EntryFrom.signal_changed().connect(sigc::mem_fun(*this, &Window::on_entryFrom_changed));
    m_EntryTo.signal_changed().connect(sigc::mem_fun(*this, &Window::on_entryTo_changed));

    auto m_VBoxFrom = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);
    auto m_VBoxTo = Gtk::make_managed<Gtk::Box>(Gtk::Orientation::VERTICAL);

    m_EntryFrom.set_expand(true);
    m_EntryTo.set_expand(true);

    m_mainBox->append(m_units_Combo);
    m_VBoxFrom->append(m_EntryFrom);
    m_VBoxFrom->append(m_unitsFrom_Combo);
    m_hBox->append(*m_VBoxFrom);
    m_VBoxTo->append(m_EntryTo);
    m_VBoxTo->append(m_unitsTo_Combo);
    m_hBox->append(*m_VBoxTo);
    m_mainBox->append(*m_hBox);
}

Window::~Window()
{
}

void Window::on_unitsType_combo_changed()
{
    m_EntryFrom.set_text("");

    m_EntryTo.set_text("");

    const auto iter = m_units_Combo.get_active();
    if (iter)
    {
        const auto& row = *iter;
        if (row)
        {
            //Get the data for the selected row, using our knowledge of the tree
            //model:
            Glib::ustring name = row[m_Columns.m_col_name];

            m_unitsFrom_refTreeModel->clear();
            m_unitsTo_refTreeModel->clear();

            Gtk::TreeRow unitsFrom_row;
            Gtk::TreeRow unitsTo_row;

            for (const auto& units : unitsMap.at(name))
            {
                unitsFrom_row = *(m_unitsFrom_refTreeModel->append());
                unitsTo_row = *(m_unitsTo_refTreeModel->append());
                unitsFrom_row[m_Columns.m_col_name] = units.name;
                unitsTo_row[m_Columns.m_col_name] = units.name;
            }

            m_unitsFrom_Combo.set_active(0);
            m_unitsTo_Combo.set_active(0);
        }
    }
    else
        std::cout << "invalid iter" << std::endl;
}

void Window::on_units_combo_changed()
{
    Glib::ustring unitsFrom_name = (*m_unitsFrom_Combo.get_active())[m_Columns.m_col_name];
    Glib::ustring unitsTo_name = (*m_unitsFrom_Combo.get_active())[m_Columns.m_col_name];
    if(unitsFrom_name.compare(unitsTo_name) != 0)

    if (!m_EntryFrom.get_text().empty())
        convert_value(m_unitsFrom_Combo, m_unitsTo_Combo, m_EntryFrom, m_EntryTo);
}

void Window::convert_value(Gtk::ComboBox& m_unitsFrom_Combo, Gtk::ComboBox& m_unitsTo_Combo, Gtk::Entry& m_EntryFrom, Gtk::Entry& m_EntryTo)
{
    if (!converting)
    {
        converting = true;

        Glib::ustring unitFrom_name = (*m_unitsFrom_Combo.get_active())[m_Columns.m_col_name];
        Glib::ustring unitTo_name = (*m_unitsTo_Combo.get_active())[m_Columns.m_col_name];

        const double value = std::stod(m_EntryFrom.get_text());

        const double factorFrom = get_conversion_factor(unitFrom_name);
        const double factorTo = get_conversion_factor(unitTo_name);

        const double converted_value = value * (factorFrom / factorTo);

        
        std::string str;

        if (std::abs(converted_value) < 1e-3 || std::abs(converted_value) > 1e6)
        {
            std::stringstream ss;
            ss << std::scientific << std::setprecision(0) << converted_value;
            str = ss.str();
        }
        else {
            if (std::modf(converted_value, new double) == 0.0)
            {
                str = std::to_string(static_cast<int>(converted_value));
            }
            else
            {
                str = std::to_string(converted_value);
            } 
        }

        m_EntryTo.set_text(str);

        converting = false;
    }
}

void Window::on_entryFrom_changed()
{
    std::cout << "EntryFrom changed: " << m_EntryFrom.get_text() << '\n';
    if (!m_EntryFrom.get_text().empty())
        convert_value(m_unitsFrom_Combo, m_unitsTo_Combo, m_EntryFrom, m_EntryTo);
}

void Window::on_entryTo_changed()
{
    std::cout << "EntryTo changed: " << m_EntryTo.get_text() << '\n';
    if (!m_EntryTo.get_text().empty())
        convert_value(m_unitsTo_Combo, m_unitsFrom_Combo, m_EntryTo, m_EntryFrom);
}

double Window::get_conversion_factor(Glib::ustring name)
{
    Glib::ustring unitType = (*m_units_Combo.get_active())[m_Columns.m_col_name];
    auto& units = unitsMap.at(unitType);

    for (const auto& unit : units)
    {
        if (unit.name == name)
            return unit.conversionFactor;
    }
    return 0;
}