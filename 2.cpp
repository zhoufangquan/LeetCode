// CPP program to illustrate the
// list::splice() function
#include <bits/stdc++.h>
using namespace std;

int main()
{
	// initializing lists
	list<int> l1 = { 1, 2, 3 };
	list<int> l2 = { 4, 5 };
	list<int> l3 = { 6, 7, 8 };

	// transfer all the elements of l2
    list<int> ::iterator it = l1.begin();
    map<int, list<int> ::iterator> m;
    m[12] = ++it;
	l1.splice(l1.begin(), l1, ((++it)));

	// at the beginning of l1
	cout << "list l1 after splice operation" << endl;
	for (auto x : l1)
		cout << x << " ";
    cout<<'\n'<<*m[12]<<'\n'<<*++l1.begin();
	// transfer all the elements of l1
	l3.splice(l3.end(), l1);

	// at the end of l3
	cout << "\nlist l3 after splice operation" << endl;
	for (auto x : l3)
		cout << x << " ";
    cout<<'\n';
	return 0;
}
