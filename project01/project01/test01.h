#include "stdafx.h"

class Test01
{
public:
	int a;

	// A a; A& a; A* a;������ʽ����
	Test01()
	{
		std::cout << "Test01 ctor..." << std::endl;
	}

	// ʲôʱ�����õ����ƹ��캯��
	Test01(Test01 &t01)
	{
		std::cout << "Test01 copy..." << std::endl;
	}

	// ʲôʱ�����õ���ֵ���캯��
	Test01 operator = (Test01 &t01)
	{
		std::cout << "Test01 =..." << std::endl;
		return *this;
	}

	void fun01()
	{
		Test01* a1 = new Test01();
		Test01* a2;
		a2 = a1;
		std::cout << a1 << "," << a2 << std::endl;
		std::cout << "a1 set nullptr" << std::endl;
		a1->a = 2;
		a1 = nullptr;
		std::cout << a1 << "," << a2 << std::endl;
	}

	// ָ��ĵ�ַ��ָ��ָ���ֵ��ָ��ָ���ֵ�ĵ�ַ��������
	void fun02()
	{
		int age = 30;
		int weight = 60;
		int* a1 = nullptr;
		a1 = &age;
		int* b1 = &weight;
		//*b1 = age;
		b1 = &age;

		std::cout << a1 << "," << b1 << std::endl;
		std::cout << *a1 << "," << *b1 << std::endl;


		int m = 1;
		int n = 2;
		int tmp = 0;
		int* a = &m;
		int* b = &n;
		std::cout << a << "," << b << std::endl;

		tmp = *a;
		*a = *b;
		*b = tmp;

		std::cout << a << "," << b << std::endl;
		std::cout << *a << "," << *b << std::endl;
	}


};