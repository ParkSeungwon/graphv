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
	clearv(v);
	krusgal(v);
	vgshow(v);
	gfree(v);
}
