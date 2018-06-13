#include <iostream>
#include <string>

using namespace std;

void process(const string& arg)
{
	cout << "lvalue process" << endl;
}

void process(string&& arg)
{
	cout << "rvalue process" << endl;
}

template <typename T>
void log_and_process(T&& param)
{
	process(forward<T>(param));
}

int main()
{
	string str = "Hi there";
	log_and_process(str);
	log_and_process("Hi there");
	log_and_process(move(str));
	system("pause");
	return 0;
}