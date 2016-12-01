typedef int element;

typedef struct Edge
{
	int weight;
	int v;
	struct Vertex* vertex;
	struct Edge* edge;
} Edge;

typedef struct Vertex
{
	element data;
	int v;
	struct Edge* edge;
	struct Vertex* vertex;
} Vertex;

Vertex* insert_vertex(Vertex* p, element data);
Edge* insert_edge(Edge* e, Vertex* q, int w);
void ins_edge(Vertex* p, element a, element b, int w);
void gshow(Vertex* p);
void vgshow(Vertex* p);
void gfree(Vertex* p);
void min_span(Vertex* p);
