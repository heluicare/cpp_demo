// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "test01.h"
// 类的前置声明一般用在头文件中，因为这里只起到一个通知编译器存在类A，而并不知其成员变量和函数，且不能使用其地址；
 //class Test01; 

Test01 fun01()
{
	Test01 a;
	std::cout << &a << std::endl;
	return a;
}

int _tmain(int argc, _TCHAR* argv[])
{
	
	//Test01 a;
	//Test01* a1 = nullptr;
	//std::cout << &a << "," << a1 << std::endl;
	////a.fun01();

	////Test01 a01 = fun01();
	//a = fun01();
	//std::cout << &a << std::endl;

	Test01 a;
	a.fun02();

	system("pause");
	return 0;
}