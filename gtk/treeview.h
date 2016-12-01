#pragma once
#include<vector>
#include"darea.h"

class Win : public Gtk::Window
{
public:
	Win();
	void draw(std::shared_ptr<Drawable> to_draw);

protected:
	Gtk::ScrolledWindow scwin_;
	SketchBook sketch_;
};
template <typename T> void treeview(T* p) 
{
	if(!p) return;
	treeview(p->left);
	treeview(p->right);
}

