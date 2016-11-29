#pragma once
#include<complex>
#include<vector>
#include<gtkmm.h>

class Point : public std::complex<double>
{
public:
	Point(int x, int y);
	int x() const; 		
	int y() const; 	
};

class Drawable
{
public:
	virtual void operator()(const Cairo::RefPtr<Cairo::Context>& cr) = 0;
protected:
	enum Color {RED, BLUE, BLACK, GREEN} color_;
};

class Line : public Drawable 
{
public:
	Line(Color c);
	virtual void operator()(const Cairo::RefPtr<Cairo::Context>& cr);
	std::vector<Point> points_;
protected:
};

class Arrow : public Drawable 
{
public:
	Arrow(Point s, Point e);
	Point start() const;	Point end() const;
protected:
	enum Color {BLACK, RED, BLUE} color_;
	enum Style {BOTH, ARROW, LINE} style_;
	Point start_, end_;
	
};

class Box
{
public:

protected:
	enum Style {ROUND, RECT} style_;
};

