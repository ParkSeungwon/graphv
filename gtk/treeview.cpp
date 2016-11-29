#include<gtkmm.h>
#include"treeview.h"
using namespace std;

int main(int c, char** v)
{
	auto app = Gtk::Application::create(c, v);
	Win win;
	return app->run(win);
}

