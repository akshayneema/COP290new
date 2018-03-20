#ifndef GTKMM_EXAMPLE_MYAREA_H
#define GTKMM_EXAMPLE_MYAREA_H

// #include <gtkmm/drawingarea.h>
#include <gtkmm.h>

class MyWindow : public Gtk::Window
{
public:
  MyWindow();
  virtual ~MyWindow();

protected:
  //Override default signal handler:
  Gtk::Grid grid;
  Gtk::DrawingArea area;
  Gtk::Button buttonx;
  Gtk::Button buttony;
  Gtk::Button buttonz;
  bool on_drawe(const Cairo::RefPtr<Cairo::Context>& cr);
  void on_click(int x);
};

#endif // GTKMM_EXAMPLE_MYAREA_H