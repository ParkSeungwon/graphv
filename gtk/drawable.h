#pragma once
#include<complex>
#include<vector>
#include<initializer_list>
#include<string>

namespace Cairo {
	class Context;
	template <typename T> class RefPtr<T>;
};

class Point : public std::complex<double>
{
public:
	Point(int x=0, int y=0);
	Point(std::complex<double> im);
	int x() const; 		
	int y() const; 	
};

class Drawable
{
public:
	virtual void operator()(const Cairo::RefPtr<Cairo::Context>& cr);
	void line_width(int w);
	void set_rgb(double r, double g, double b);
	void txt(std::string s);
	void set_size(int size);
	void set_family(std::string family);
	void set_weight(int weight);
	
protected:
	double r_ = 0, g_ = 0, b_ = 0, a_ = 1;
	int line_width_ = 3;
	std::string txt_;
	Point start_, end_;
	Pango::FontDescription font_;
};

class Line : public Drawable 
{
public:
	Line(std::initializer_list<Point> li);
	virtual void operator()(const Cairo::RefPtr<Cairo::Context>& cr);
protected:
	Line();
	std::vector<Point> points_;
};

class Arrow : public Line 
{
public:
	Arrow(Point s, Point e, int tip = 1);

protected:
	
};

class Box : public Line
{
public:
	Box(Point s, Point e);

protected:
};

class Ellipse : public Drawable
{
public:
	Ellipse(Point s, Point e);
	virtual void operator()(const Cairo::RefPtr<Cairo::Context>& cr);
	
};
