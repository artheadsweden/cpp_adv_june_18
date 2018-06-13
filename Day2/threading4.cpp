#include <iostream>
#include <thread>
#include <functional>

using namespace std;

class ThreadWrapper
{
public:
	explicit ThreadWrapper(function<void()> f)
	{
		t = new thread(f);
	}
	~ThreadWrapper()
	{
		if (t->joinable())
		{
			t->join();
		}
		delete t;
	}
	ThreadWrapper(const ThreadWrapper&) = delete;
	ThreadWrapper& operator=(const ThreadWrapper&) = delete;
private:
	thread* t;
};


int main()
{
	{
		ThreadWrapper tw([] {cout << "Hi from thread" << endl; });
		cout << "Thread is going" << endl;
	}
	cout << "Thread is done" << endl;
	system("pause");
	return 0;
}