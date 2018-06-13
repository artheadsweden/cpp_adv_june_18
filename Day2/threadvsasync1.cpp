#include <iostream>
#include <numeric>
#include <vector>
#include <thread>

using namespace std;

void accumulate_block_value(int* data, size_t count, int* result)
{
	*result = accumulate(data, data + count, 0);
}

int main()
{
	vector<int> v{ 1,2,3,4,5,6,7,8 };
	int result;
	thread t(accumulate_block_value, v.data(), v.size(), &result);
	t.join();
	cout << result << endl;
	system("pause");
	return 0;
}