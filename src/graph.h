#include<cstdlib>
#include<cassert>
typedef int element;

typedef struct Edge
{
	int weight;
	struct Vertex* vertex;
	struct Edge* edge;
} Edge;

typedef struct Vertex
{
	element data;
	struct Edge* edge;
	struct Vertex* vertex;
} Vertex;

Vertex* insert_vertex(Vertex* p, element data)
{
	if(!p) {
		p = (Vertex*)malloc(sizeof(Vertex));
		p->data = data;
		p->edge = nullptr;
		p->vertex = nullptr;
		return p;
	}

	p->vertex = insert_vertex(p->vertex, data);
	return p;
}

Edge* insert_edge(Vertex* p, Vertex* q, int w)
{
	assert(p);
	Edge* prev = p;
	for(Edge* e = p->edge; e; e = e->edge) prev = e;
	prev->edge = (Edge*)malloc(sizeof(Edge));
	prev->edge->weight = w;
	prev->edge->edge = nullptr;
	prev->edge->vertex = q;
}


template <typename T> class Graph 
{
public:
	insert_vertex();
	insert_edge();
