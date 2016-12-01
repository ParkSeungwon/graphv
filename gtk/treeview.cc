#include<gtkmm.h>
#include"drawable.h"
#include"treeview.h"
using namespace std;

Win::Win() 
{
	add(scwin_);
	scwin_.add(sketch_);
	set_default_size(1500, 900);
	show_all_children();
}

void Win::draw(shared_ptr<Drawable> dr)
{
	sketch_.to_draws_.push_back(dr);
}

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
