#pragma once
#include<vector>

class SketchBook : public Gtk::DrawingArea
{
public:
	SketchBook();
	std::vector<std::shared_ptr<Drawable>> to_draws_; 
	
protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);
};

class Win : public Gtk::Window
{
public:
	Win();
	void draw(std::shared_ptr<Drawable> to_draw);

protected:
	Gtk::ScrolledWindow scwin_;
	SketchBook sketch_;
};

