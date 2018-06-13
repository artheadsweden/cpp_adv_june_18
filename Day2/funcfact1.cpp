#include <iostream>

using namespace std;

int main()
{
	int x = 10;
	int y = 19;
	auto func = [&](int x, int y)
	{
		return x + y; 
	};
	cout << func(2,3) << endl;
	system("pause");
	return 0;
}