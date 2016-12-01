#include"tree.h"
#include"graph.h"
using namespace std;

int main()
{
	Tree<int> t{2};
	t.insert(1);
	t.insert(3);
	t.insert(5);
	t.insert(0);
	t.view();
	t.tfree();

	Vertex* v = NULL;
	for(int i=0; i<7; i++) v = insert_vertex(v, i);
	ins_edge(v, 0, 4, 3);
	ins_edge(v, 0, 1, 7);
	ins_edge(v, 0, 5, 10);
	ins_edge(v, 4, 1, 2);
	ins_edge(v, 1, 5, 6);
	ins_edge(v, 4, 6, 5);
	ins_edge(v, 4, 3, 11);
	ins_edge(v, 3, 1, 10);
	ins_edge(v, 1, 2, 4);
	ins_edge(v, 3, 2, 2);
	ins_edge(v, 3, 5, 9);
	ins_edge(v, 3, 6, 4);
	min_span(v);
	gshow(v);
	vgshow(v);
	gfree(v);
}
