// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "test01.h"
// ���ǰ������һ������ͷ�ļ��У���Ϊ����ֻ��һ��֪ͨ������������A��������֪���Ա�����ͺ������Ҳ���ʹ�����ַ��
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