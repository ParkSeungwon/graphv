#pragma once
#include"drawable.h"
using namespace std;

Point::Point(int x=0, int y=0) : complex<double>(x, y) {}
int Point::x() const {return real();}
int Point::y() const {return imag();}
Line::Line(Color c) 
{
	color_ = c;
}

void Line::operator()(const Cairo::RefPtr<Cairo::Context>& cr) 
{
	cr->save();
	cr->set_source_rgb(0,0,0);
	cr->set_line_width(5);
	cr->move_to(points_[0].x(), points_[0].y());
	for(auto& a : points_) cr->line_to(a.x(), a.y());
	cr->stroke();
	cr->restore();
}
Point Arrow::start() const {return start_;}
Point Arrow::end() const {return end_;}
Arrow::Arrow(Point s, Point e) 
{
	start_ = s;
	end_ = e;
}
