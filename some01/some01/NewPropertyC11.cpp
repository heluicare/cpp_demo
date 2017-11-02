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
	// 声明一个函数指针，指针funcPt指向一个返回值为int且两个int参数的函数
	int (*funcPt)(int, int);
	funcPt = funcTest01;
	//funcPt = &funcTest01;
	//funcPt = *funcTest01;
	funcPt(2, 3);

	typedef int(*FuncPt)(int, int);
	FuncPt funcpt01 = funcTest01;
	//FuncPt funcpt01 = &funcTest01;
	//FuncPt funcpt01 = *funcTest01;
	funcpt01(2, 3);

}

void NewPropertyC11::funcTempeletTest()
{

}
