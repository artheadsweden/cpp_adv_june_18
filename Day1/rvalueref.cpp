#include <iostream>
#include <string>
using namespace std;


void myfunc(int& a)
{
	cout << "a is lvalue" << endl;
}

void myfunc(int&& a)
{
	cout << "a is rvalue" << endl;
}


int main()
{
	int x = 10;
	myfunc(move(x));
	myfunc(10);
	string s1 = "Hej hopp";
	auto s2 = move(s1);
	cout << "!" << s1 << "!" << endl;
	cout << "!" << s2 << "!" << endl;
	system("pause");
	return 0;
}