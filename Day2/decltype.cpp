#include <iostream>

template <typename T1, typename T2>
auto adder1(T1 a, T2 b) -> decltype(a+b)
{
	return a + b;
}

template <typename T1, typename T2>
auto adder2(T1 a, T2 b) 
{
	return a + b;
}

int main()
{
	int x = 10;
	const int cx = x;
	
	decltype(cx) b = cx;  //const int
	decltype((cx)) c = cx; //const int&

	system("pause");
	return 0;
}