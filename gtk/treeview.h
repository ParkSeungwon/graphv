#pragma once
#include<vector>
class Drawable;
class SketchBook : public Gtk::DrawingArea
{
public:
	SketchBook();
	std::vector<std::shared_ptr<Drawable>> to_draws_; 
	void refresh();

protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

};

class Win : public Gtk::Window
{
public:
	Win();
	void draw(std::shared_ptr<Drawable> to_draw);

protected:
	bool on_button_press_event(GdkEventButton* e);
	bool on_button_release_event(GdkEventButton* e);
	Gtk::ScrolledWindow scwin_;
	SketchBook sketch_;
private:
	int x, y, tx, ty;
};

