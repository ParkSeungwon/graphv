#include"tree.h"
#include"gtk/drawable.h"

class TreeView
{
public:
	TreeView(Tree<T>* tree);

protected:
	int width_, height_, level_;
	std::vector<Drawable> drawables_;
};

vector<Drawable> generate_graph(Tree<T>* tree)
{
	

