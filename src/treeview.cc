#include"treeview.h"
using namespace std;

TreeView::TreeView(Tree<T>* tree)
{
	level_ = tree->height();
	width_ = pow(2, level_) * 100;
	height_ = level_ * 300;
	
}
void TreeView::generate_graph(Tree<T>* tree)
{
	int h = tree->height();
	static int x = 0;
	drawables_.push_back(Ellipse{{x, h * 100}, { x + 100, (h+1) * 100}});

	if(tree->left) {
		drawables_.push_back(Arrow{{x, h*100}, {x -= pow(2, h) * 100, (h+2)*100}});
		generate_graph(tree->left);
	}
	if(tree->right) {
		drawables_.push_back(Arrow{{x, h*100}, {x += pow(2, h) * 100, (h+2)*100}});
		generate_graph(tree->right);
	}
}

