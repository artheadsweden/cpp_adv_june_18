#include <iostream>
#include <thread>
#include <chrono>
#include <string>
#include <mutex>

using namespace std;
mutex coutMutex;

class Worker
{
public:
	Worker(string n): name(n){}

	void operator()()
	{
		for (int i = 0; i <= 3; i++)
		{
			this_thread::sleep_for(chrono::microseconds(200));
			{
				lock_guard<mutex> coutLock(coutMutex);
				cout << name << " is doing work" << endl;
			}
		}
	}
private:
	string name;
};

int main()
{
	cout << "Boss says: Start working!" << endl;
	thread bob(Worker("Bob"));
	thread sara(Worker("Sara"));
	thread tom(Worker("Tom"));
	thread pete(Worker("Pete"));
	thread alice(Worker("Alice"));
	thread sue(Worker("Sue"));

	bob.join();
	sara.join();
	tom.join();
	pete.join();
	alice.join();
	sue.join();

	cout << "Boss says: Great you can now go home" << endl;
	system("pause");
	return 0;
}