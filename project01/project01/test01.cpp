#include "stdafx.h"

class A
{
public:
	int a;
	void fun01()
	{
		A* a1 = new A();
		A* a2;
		a2 = a1;
		std::cout << a1 << "," << a2 << std::endl;
		std::cout << "a1 set nullptr" << std::endl;
		a1->a = 2;
		a1 = nullptr;
		std::cout << a1 << "," << a2 << std::endl;
	}
};