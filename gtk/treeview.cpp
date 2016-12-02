#include<gtkmm.h>
#include"treeview.h"
#include"treev.h"
#include"graphv.h"
#include"src/tree.h"
#include"src/graph.h"
using namespace std;

extern GraphView<Vertex, Edge, element>* pgv;
int main(int c, char** av)
{
	uniform_int_distribution<> di(0, 20);
	random_device rd;
	Tree<int> t{10};
	for(int i=0; i<15; i++) t.insert(di(rd));
	TreeView<Tree<int>> tv{&t};

	auto app = Gtk::Application::create(c, av);
	Win win;
//	for(auto& a : tv) win.draw(a);

	Line l{{10, 100}, {20, 10}, {30,100}, {300, 200}};
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
	win.draw(make_shared<Line>(l));
	win.draw(make_shared<Arrow>(a));
	win.draw(make_shared<Box>(b));
	win.draw(make_shared<Ellipse>(el));
	t.tfree(); 

	Vertex* v = NULL;
	for(int i=0; i<7; i++) v = insert_vertex(v, i);
	ins_edge(v, 0, 4, 3);
	ins_edge(v, 4, 0,  3);
	ins_edge(v, 1, 0, 7);
	ins_edge(v, 0, 1, 7);
	ins_edge(v, 0, 5, 10);
	ins_edge(v, 5, 0, 10);
	ins_edge(v, 4, 1, 2);
	ins_edge(v, 1, 4, 2);
	ins_edge(v, 1, 5, 6);
	ins_edge(v, 5, 1, 6);
	ins_edge(v, 4, 6, 5);
	ins_edge(v, 6, 4, 5);
	ins_edge(v, 4, 3, 11);
	ins_edge(v, 3, 4, 11);
	ins_edge(v, 3, 1, 10);
	ins_edge(v, 1, 3, 10);
	ins_edge(v, 1, 2, 4);
	ins_edge(v, 2, 1, 4);
	ins_edge(v, 3, 2, 2);
	ins_edge(v, 2, 3, 2);
	ins_edge(v, 3, 5, 9);
	ins_edge(v, 5, 3, 9);
	ins_edge(v, 3, 6, 4);
	ins_edge(v, 6, 3, 4);
	gshow(v);
	prim(v);
	vgshow(v);
//	clearv(v);
//	krusgal(v);
//	vgshow(v);
	GraphView<Vertex, Edge, element> gv{v};
	pgv = &gv;
	for(auto& a : gv) win.draw(a);
	gshow(v);
	gfree(v);
	return app->run(win);
}

