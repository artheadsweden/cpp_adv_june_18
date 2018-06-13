#include <iostream>
#include <functional>
using namespace std;

function<int(int)> funcfact_extern(int x)
{
	return [=](int y)
	{
		return x * y;
	};
}

int main()
{
	auto funcfact = [](int x)
	{
		return [=](int y)
		{
			return x * y;
		};
	};

	auto times2 = funcfact_extern(2);
	auto times3 = funcfact_extern(3);
	cout << times2(3) << endl;
	cout << times3(4) << endl;
	cout << times2(3) << endl;
	cout << times3(4) << endl;

	system("pause");
	return 0;
}