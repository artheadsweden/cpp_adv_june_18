#include <iostream>
#include <numeric>
#include <vector>
#include <future>

using namespace std;

int accumulate_block_value(int* data, size_t count)
{
	return accumulate(data, data + count, 0);
}

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8 };
	future<int> result1(async(accumulate_block_value, v.data(), v.size()));
	future<int> result2 = async(launch::async, accumulate_block_value, v.data(), v.size());
	cout << result1.get() << endl;
	cout << result2.get() << endl;
	system("pause");
	return 0;
}