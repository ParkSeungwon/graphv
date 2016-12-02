#pragma once
#include<complex>
#include"drawable.h"

template <typename V, typename E, typename D> class GraphView 
{
public:
	GraphView(V* gr) {
		Point im{300, 300};
		int i = 0, sz = 0;
		for(V* p = gr; p; p = p->vertex) sz++;
		for(V* p = gr; p; p = p->vertex) {
			map_[p->data] = im + std::polar(200.0, M_PI * 2 * i++ / sz);
			for(E* q = p->edge; q; q = q->edge) 
				arrows_.push_back(std::make_tuple(p->data, q->vertex->data, q->weight));
		}
		generate_graph();
	}
	void drag(Point f, Point t) {
		drawables_.clear();
		for(auto& a : map_) {
			if(abs(a.second - f) < 20) {
				a.second = t;
				break;
			}
		}
		generate_graph();
	}

	std::vector<std::shared_ptr<Drawable>>::const_iterator begin() const {
		return drawables_.begin();
	}
	std::vector<std::shared_ptr<Drawable>>::const_iterator end() const {
		return drawables_.end();
	}
	

protected:
	std::map<D, Point> map_;
	std::vector<std::tuple<D, D, int>> arrows_;
	std::vector<std::shared_ptr<Drawable>> drawables_;

private:
	void generate_graph() {
		for(auto& a : arrows_) {
			auto d1 = map_[std::get<0>(a)];
			auto d2 = map_[std::get<1>(a)];
			auto d3 = 30.0 * (d2 - d1) / abs(d2 - d1);
			d1 += d3;
			d2 -= d3;
			Arrow arrow{d1, d2, 1};
			arrow.txt(std::get<2>(a));
			drawables_.push_back(std::make_shared<Arrow>(arrow));
		}
		for(auto& a : map_) {
			Ellipse el{a.second - Point{15, 15}, a.second + Point{15, 15}};
			el.txt(a.first);
			drawables_.push_back(std::make_shared<Ellipse>(el));
		}
	}
};
