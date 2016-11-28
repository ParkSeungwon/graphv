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

	int height() {
		return height(this);
	}
	void view() {
		view(this);
	}

protected:
	T data;
	Tree<T> *left = nullptr;
	Tree<T> *right = nullptr;

private:
	void tfree(Tree<T>* p) {
		if(!p) return;
		tfree(p->left);
		tfree(p->right);
		free(p);
	}	
	int height(Tree<T>* p) {
		static int max=0;
		static int i = 1;
		if(!p) return max = max > --i ? max : i;
		i++;
		height(p->left);
		i++;
		height(p->right);
		i--;
		return max;
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
			return p;
		}
		if(n < p->data) p->left = insert(p->left, n);
		else p->right = insert(p->right, n);
		return p;
	}
};


