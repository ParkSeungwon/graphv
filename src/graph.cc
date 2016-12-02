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
		p->v = 0;
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
		e->v = 0;
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

void gshow(Vertex* p) {
	if(!p) return;
	printf("%d : ", p->data);
	for(Edge* e = p->edge; e; e = e->edge) 
		printf("<%d %d>%d ", p->data, e->vertex->data, e->weight);
	printf("\n");
	gshow(p->vertex);
}
void vgshow(Vertex* p) {
	if(!p) return;
	printf("%d : ", p->data);
	for(Edge* e = p->edge; e; e = e->edge) 
		if(e->v) printf("<%d %d>%d ", p->data, e->vertex->data, e->weight);
	printf("\n");
	vgshow(p->vertex);
}

void efree(Edge* e) {
	if(!e) return;
	efree(e->edge);
	free(e);
}

void gfree(Vertex* p) {
	if(!p) return;
	efree(p->edge);
	gfree(p->vertex);
	free(p);
}

void shortest(Vertex* p) {
	Edge* me;
	int min = 100000;
	for(Vertex* q = p; q; q = q->vertex) {
		if(q->v) {
			for(Edge* e = q->edge; e; e = e->edge) {
				if(e->v) continue;
				if(e->weight < min && !e->vertex->v) {
					min = e->weight;
					me = e;
				}
			}
		}
	}
	me->v = 1;
	me->vertex->v = 1;
}

void prim(Vertex* p) {
	p->v = 1;
	for(Vertex* q = p->vertex; q; q = q->vertex) shortest(p);//just to call n-1
}

void krus(Vertex* p) {
	Edge* me;
	Vertex* mv;
	int min = 1000000;
	for(Vertex* q = p; q; q = q->vertex) {
		for(Edge* e = q->edge; e; e = e->edge) {
			if(e->weight < min && !(q->v && e->vertex->v)) {//this is not correct
				min = e->weight;
				me = e;
				mv = q;
			}
		}
	}
	mv->v = 1;
	me->v = 1;
	me->vertex->v = 1;
}

void krusgal(Vertex* p) {
	for(Vertex* q = p; q; q = q->vertex) krus(p);//just to call n times
	krus(p);
}

void clearv(Vertex* p) {
	for(Vertex* q = p; q; q = q->vertex) {
		q->v = 0;
		for(Edge* e = q->edge; e; e = e->edge) e->v = 0;
	}
}
