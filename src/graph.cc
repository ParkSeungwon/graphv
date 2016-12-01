#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include"graph.h"

Vertex* insert_vertex(Vertex* p, element data)
{
	if(!p) {
		p = (Vertex*)malloc(sizeof(Vertex));
		p->data = data;
		p->edge = NULL;
		p->vertex = NULL;
		return p;
	}

	p->vertex = insert_vertex(p->vertex, data);
	return p;
}

Edge* insert_edge(Edge* e, Vertex* q, int w) 
{
	if(!e) {
		e = (Edge*)malloc(sizeof(Edge));
		e->weight = w;
		e->edge = NULL;
		e->vertex = q;
		return e;
	}
	e->edge = insert_edge(e->edge, q, w);
	return e;
}

void ins_edge(Vertex* p, element a, element b, int w)
{
	Vertex *va = NULL, *vb = NULL;
	while(p) {
		if(p->data == a) va = p;
		if(p->data == b) vb = p;
		p = p->vertex;
	}
	va->edge = insert_edge(va->edge, vb, w);
}

void show(Vertex* p) {
	if(!p) return;
	printf("\n%d : ", p->data);
	for(Edge* e = p->edge; e; e = e->edge) 
		printf("<%d %d>%d ", p->data, e->vertex->data, e->weight);
	show(p->vertex);
}
