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
	v = insert_vertex(v, 3);
	v = insert_vertex(v, 4);
	v = insert_vertex(v, 5);
	v = insert_vertex(v, 6);
	ins_edge(v, 3, 4, 1);
	ins_edge(v, 3, 5, 1);
	ins_edge(v, 3, 6, 3);
	ins_edge(v, 4, 5, 1);
	show(v);
}
