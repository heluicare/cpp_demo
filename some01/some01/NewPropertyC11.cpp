#include "stdafx.h"

NewPropertyC11::NewPropertyC11()
{
}

NewPropertyC11::~NewPropertyC11()
{
}

int funcTest01(int a, int b)
{
	cout << a << "," << b << endl;
	return 0;
}

void NewPropertyC11::funcPointTest()
{
	funcPt0 = funcTest01;
	//funcPt = &funcTest01;
	//funcPt = *funcTest01;
	funcPt0(2, 3);

	FuncPt1 funcpt01 = funcTest01;
	//FuncPt funcpt01 = &funcTest01;
	//FuncPt funcpt01 = *funcTest01;
	funcpt01(2, 3);

}


template <typename T>
void funcTest02(T& a, T& b)
{
	cout << a << "," << b << endl;
}

void NewPropertyC11::funcTemplateTest()
{
	int a0 = 1;
	int a1 = 2;
	funcTest02(a0, a1);
	float b0 = 1.0f;
	float b1 = 2.0f;
	funcTest02(b0, b1);
	//funcTest02(b0, b1);
	int* c0 = &a0;
	int* c1 = &a1;
	funcTest02(c0, c1);
	int& d0 = a0;
	int& d1 = a1;
	funcTest02(d0, d1);
	
	funcTest02(funcTest01, funcTest01);

}

void NewPropertyC11::classTemplateTest()
{
	
}

void NewPropertyC11::funcClassTemplateTest()
{
	// 初始化一个类模板
	std::function<int(int, int)> func01 = funcTest01;
	// 
	std::function<void> func02 = funcPointTest;
	// 函数模板
	std::function<int(int, int)> func03 = std::bind(&funcTest01, placeholders::_1, placeholders::_2);
	// 
	std::function<int(int, int)> func03 = std::bind(&funcPointTest, placeholders::_1, placeholders::_2);

}