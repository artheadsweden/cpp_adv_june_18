#include <iostream>
#include <vector>
#include "type.h"

using namespace std;

template <typename T>
void f_ref(T& param)
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_const_ref(const T& param)
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}


template <typename T>
void f_pointer(T* param)
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_universal(T&& param)
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_value(T param)
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}


template <typename T>
void f_array1(T param[])
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}

template <typename T>
void f_array2(T& param)
{
	cout << "T is " << type_name<T>() << endl;
	cout << "param is " << type_name<decltype(param)>() << endl;
}


template <typename T, size_t N>
constexpr size_t array_size(T(&)[N]) noexcept
{
	return N;
}

int main()
{
	int x = 10;
	const int cx = x;
	const int& rx = x;

	cout << "===================" << endl;
	cout << "T& param" << endl;
	cout << "===================" << endl;
	f_ref(x);  // T = int, param = int&
	f_ref(cx); // T = const int, param = const int&
	f_ref(rx); // T = const int, param = const int&

	cout << "===================" << endl;
	cout << "const T& param" << endl;
	cout << "===================" << endl;
	f_const_ref(x);
	f_const_ref(cx);
	f_const_ref(rx);

	cout << "===================" << endl;
	cout << "T* param" << endl;
	cout << "===================" << endl;
	const int* pcx = &x;
	
	f_pointer(&x);
	f_pointer(pcx);


	cout << "===================" << endl;
	cout << "T&& param" << endl;
	cout << "===================" << endl;
	f_universal(x);
	f_universal(cx);
	f_universal(rx);
	f_universal(13);

	cout << "===================" << endl;
	cout << "T param" << endl;
	cout << "===================" << endl;
	f_value(x);
	f_value(cx);
	f_value(rx);

	auto& v1 = x;	//v1's type is int&, auto's type is int  
	auto& v2 = cx;  //v2's type is const int&, auto's type is const int  
	auto& v3 = rx;  //v3's type is const int&, auto's type is const int  
	cout << "v1 = " << type_name<decltype(v1)>() << endl;
	cout << "v2 = " << type_name<decltype(v2)>() << endl;
	cout << "v3 = " << type_name<decltype(v3)>() << endl;

	int a = { 1 };
	int b{ 2 };
	vector<int> vec1 = { 1 };
	vector<int> vec2{ 1,2,3 };

	auto a1{ 1 };
	auto a2 = { 1 };
	auto a3 = { 1,2,3 };
	//auto a4{ 1,2,3,4 }; //ERROR


	int arr[]{ 1,2,3 };
	cout << "===================" << endl;
	cout << "f_array1" << endl;
	cout << "===================" << endl;
	f_array1(arr);

	cout << "===================" << endl;
	cout << "f_array2" << endl;
	cout << "===================" << endl;
	f_array2(arr);

	cout << "size of arr is " << array_size(arr) << endl;

	system("pause");
	return 0;
}