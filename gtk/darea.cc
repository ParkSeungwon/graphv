#include"darea.h"
using namespace std;

SketchBook::SketchBook()
{
	set_size_request(3000, 1000);
}

bool SketchBook::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) 
{
	cr->save();
	for(auto& a : to_draws_) (*a)(cr);
	cr->restore();
	return true;
}

void SketchBook::draw_txt(const Cairo::RefPtr<Cairo::Context>& cr, int rectangle_width, int rectangle_height)
{
	Pango::FontDescription font;

	font.set_family("Monospace");
	font.set_weight(Pango::WEIGHT_BOLD);

	// http://developer.gnome.org/pangomm/unstable/classPango_1_1Layout.html
	auto layout = create_pango_layout("Hi, there");

	layout->set_font_description(font);

	int text_width;
	int text_height;

	//get the text dimensions (it updates the variables -- by reference)
	layout->get_pixel_size(text_width, text_height);

	// Position the text in the middle
	cr->move_to((rectangle_width-text_width)/2, (rectangle_height-text_height)/2);

	layout->show_in_cairo_context(cr);
}
