#include"tree.h"
using namespace std;

int main()
{
	Tree<int> t{2};
	t.insert(1);
	t.insert(3);
	t.insert(5);
	t.insert(0);
	t.view();
	cout << endl << "height is " << t.height() << endl;
	t.tfree();
}
