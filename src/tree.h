#pragma once
#include<cstdlib>
#include<iostream>

template <typename T> class Tree
{
public:
	Tree<T>(T n) {
		this->data = n;
	}
	void tfree() {
		tfree(left);
		tfree(right);
	}
	void insert(T n) {
		insert(this, n);
	}

	void view() {
		view(this);
	}
	Tree<T> *left = nullptr;
	Tree<T> *right = nullptr;
	T data;

protected:

private:
	void tfree(Tree<T>* p) {
		if(!p) return;
		tfree(p->left);
		tfree(p->right);
		free(p);
	}	
	void view(Tree<T>* p) {
		if(!p) return;
		view(p->left);
		std::cout << p->data << ' ';
		view(p->right);
	}
	Tree<T>* insert(Tree<T>* p, T n) {
		if(!p) {
			p = (Tree<T>*)malloc(sizeof(Tree<T>));
			p->data = n;
			p->left = nullptr;
			p->right = nullptr;
			return p;
		}
		if(n < p->data) p->left = insert(p->left, n);
		else p->right = insert(p->right, n);
		return p;
	}
};

