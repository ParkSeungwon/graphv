#include<gtkmm.h>
#include<memory>
#include<vector>
#include"drawable.h"

class SketchBook : public Gtk::DrawingArea
{
public:
	SketchBook();
	std::vector<std::shared_ptr<Drawable>> to_draws_; 
	
protected:
	bool on_draw(const Cairo::RefPtr<Cairo::Context>& cr);

private:
	void draw_txt(const Cairo::RefPtr<Cairo::Context>& cr, int w, int h);
};

