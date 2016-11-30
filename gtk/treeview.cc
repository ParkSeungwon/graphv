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
	sketch_.set_size_request(3000, 1000);
/*	Line l{{10, 100}, {20, 10}, {30,100}, {300, 200}};
	l.set_rgb(1,0,0);
	l.line_width(10);
	Arrow a{{300, 100}, {200, 200}};
	a.txt("3");
	a.set_rgb(0,0,1);
	Box b{{30, 100}, {70, 140}};
	b.txt("int");
	b.set_rgb(0,1,0);
	//a.set_size(50);
	b.set_family("Script");
	b.set_weight(1000);

	Ellipse el({100, 100}, {170, 120});
	el.txt("el");
	el.set_rgb(0,0,0);
	sketch_.to_draws_.push_back(make_shared<Line>(l));
	sketch_.to_draws_.push_back(make_shared<Arrow>(a));
	sketch_.to_draws_.push_back(make_shared<Box>(b));
	sketch_.to_draws_.push_back(make_shared<Ellipse>(el));
*/	set_default_size(900, 900);
	uniform_int_distribution<> di(0, 20);
	random_device rd;
	Tree<int> t{10};
	for(int i=0; i<15; i++) t.insert(di(rd));
	t.insert(1);
	t.insert(3);
	t.insert(5);
	t.insert(0);
	t.view();
	TreeView<Tree<int>> tv{&t};
	for(auto& a : tv) sketch_.to_draws_.push_back(a);
	t.tfree();
	show_all_children();
}

