#pragma once
#include<iostream>
#include<memory>
#include"drawable.h"
template <typename T> class TreeView
{
public:
	TreeView(T* tree) {
		level_ = height(tree);
		width_ = pow(2, level_) * 20;
		height_ = level_ * 150;
		generate_graph(tree, width_ / 2, 100);
	}
	std::vector<std::shared_ptr<Drawable>>::const_iterator begin() const {
		return drawables_.begin();
	}
	std::vector<std::shared_ptr<Drawable>>::const_iterator end() const {
		return drawables_.end();
	}

protected:
	std::vector<std::shared_ptr<Drawable>> drawables_;
	int width_, height_, level_;
	void generate_graph(T* tree, int x, int y) {
		static int h = 0;
		Ellipse el{{x, y}, { x + 30, y + 20}};
		el.txt(tree->data);
		drawables_.push_back(std::make_shared<Ellipse>(el));

		if(tree->left) {
			h++;
			drawables_.push_back(std::make_shared<Arrow>(Arrow{{x, y}, 
					{x - width_ / pow(2, h + 1), y + 100}, 1}));
			generate_graph(tree->left, x - width_ / pow(2, h + 1), y + 100);
		}
		if(tree->right) {
			h++;
			drawables_.push_back(std::make_shared<Arrow>(Arrow{{x, y}, 
					{x + width_ / pow(2, h + 1), y + 100}, 1}));
			generate_graph(tree->right, x + width_ / pow(2, h + 1), y + 100);
		}
		h--;
	}

private:
	int height(T* tree) {
		static int max=0;
		static int i = 1;
		if(!tree) return max = max > --i ? max : i;
		i++;
		height(tree->left);
		i++;
		height(tree->right);
		i--;
		return max;
	}
};


