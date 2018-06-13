#include <iostream>
#include <thread>

using namespace std;

int main()
{
	thread t1([] {cout << this_thread::get_id() << endl; });
	thread t2([] {cout << this_thread::get_id() << endl; });
	thread t3([] {cout << this_thread::get_id() << endl; });
	thread t4([] {cout << this_thread::get_id() << endl; });
	t1.join();
	t2.join();
	t3.join();
	t4.join();
	system("pause");
	return 0;
}