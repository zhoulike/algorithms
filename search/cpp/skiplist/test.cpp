#include <iostream>
#include <string>
#include "skiplist.h"

using std::cout;
using std::endl;

int main()
{
	skiplist<int, double> slist;

	slist.insert(1, 1.0);
	slist.insert(2, 2.0);
	slist.insert(5, 5.0);
	slist.insert(3, 3.0);
	slist.insert(9, 9.0);
	slist.insert(7, 7.0); //insert middle
	slist.insert(0, 0.0); //insert head
	slist.insert(100, 100.0); //insert tail
	slist.insert(7, 7.0); //insert same node

	cout << slist.find(1) << endl;
	cout << slist.find(9) << endl;

	cout << "before remove:" << endl;
	slist.traverse();

	slist.remove(7); //remove middle
	slist.remove(0); //remove head
	slist.remove(100); //remove tail
	slist.remove(10000); //remove non-exist node

	cout << "after remove:" << endl;
	slist.traverse();

	return 0;
}
