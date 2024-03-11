// UnitConverter.cpp : Defines the entry point for the application.
//

#include "main.h"

int main(int argc, char** argv)
{
    auto app = Gtk::Application::create("org.gtkmm.unit-converter");

    return app->make_window_and_run<Window>(argc, argv);
}