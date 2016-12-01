#include<gtkmm.h>
#include<random>
#include"treev.h"
#include"src/tree.h"
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

