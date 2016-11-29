#include"darea.h"
using namespace std;

SketchBook::SketchBook()
{
	set_size_request(500, 500);
}


bool SketchBook::on_draw(const Cairo::RefPtr<Cairo::Context>& cr) 
{
	cr->save();
	for(auto& a : to_draws_) (*a)(cr);
	cr->restore();
	return true;
}
