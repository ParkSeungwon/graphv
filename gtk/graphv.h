#pragma once
#include"drawable.h"

template <typename V, typename E, typename D> class GraphView 
{
public:
	GraphView(V* gr) {
		complex<double> im{300, 300};
		int i = 0;
		for(V* p = gr; p; p = p->vertex) {
			map_[p->data] = im + polar(100, M_PI * i++ / 8);
			for(E* q = p->edge; q; q = q->edge) 
				arrow_.push_back({p->data, q->vertex->data, q->weight});
		}
	}

protected:
	std::map<D, Point> map_;
	std::vector<std::tuple<D, D, int>> arrow_;

private:
};
