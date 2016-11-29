#include<gtkmm.h>
#include"treeview.h"
using namespace std;

Win::Win() 
{
	add(scwin_);
	scwin_.add(sketch_);
	set_default_size(300, 300);
	show_all_children();
}

