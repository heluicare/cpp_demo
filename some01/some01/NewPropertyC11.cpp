// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <functional>
#include <iostream>

struct Foo {
	Foo(int num) : num_(num) {}
	void print_add(int i) const { std::cout << num_ + i << '\n'; }
	int num_;
};

void print_num(int i)
{
	std::cout << i << '\n';
}

struct PrintNum {
	void operator()(int i) const
	{
		std::cout << i << '\n';
	}
};


int _tmain(int argc, _TCHAR* argv[])
{
	// 存储 自由函数
	std::function<void(int)> f_display = print_num;
	f_display(-9);

	// 存储 lambda
	std::function<void()> f_display_42 = []() { print_num(42); };
	f_display_42();

	// 存储 std::bind调用的结果
	// std::bind的特殊作用https://www.cnblogs.com/ljygoodgoodstudydaydayup/p/5813247.html
	std::function<void()> f_display_31337 = std::bind(print_num, 31337);
	f_display_31337();

	//// 存储 成员函数的调用
	std::function<void(const Foo, int)> f_add_display = &Foo::print_add;
	const Foo foo(314159);
	f_add_display(foo, 1);
	f_add_display(314159, 1);

	// 存储 数据成员访问器的调用
	std::function<int(Foo const)> f_num = &Foo::num_;
	std::cout << "num_: " << f_num(foo) << '\n';

	// 存储 成员函数和调用成员函数对象的调用
	using std::placeholders::_1;
	std::function<void(int)> f_add_display2 = std::bind(&Foo::print_add, foo, _1);
	f_add_display2(2);

	// 存储 成员函数和调用成员函数对象不使用占位符的调用
	std::function<void()> f_add_display2_1 = std::bind(&Foo::print_add, foo, 1);
	f_add_display2_1();

	// 存储 成员函数和调用成员函数对象指针的调用
	std::function<void(int)> f_add_display3 = std::bind(&Foo::print_add, &foo, _1);
	f_add_display3(3);

	// 存储 函数对象的调用
	std::function<void(int)> f_display_obj = PrintNum();
	f_display_obj(18);

	system("pause");
	return 0;
}

