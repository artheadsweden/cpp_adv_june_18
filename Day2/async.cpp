#include <iostream>
#include <future>
#include <vector>

using namespace std;

int twice(int x)
{
	return x * 2;
}

int main()
{
	vector<future<int>> futures;
	for (int i = 0; i < 10; i++)
	{
		//futures.push_back(async(twice, i));
		futures.push_back(async([](int x) {return x * 2; }, i));
	}
	for (auto& f : futures)
	{
		cout << f.get() << endl;
	}
	system("pause");
	return 0;
}