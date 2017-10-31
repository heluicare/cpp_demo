#include "stdafx.h"

PointTest::PointTest()
{
	b = new int();
	//std::cout << "PointTest ctor..." << std::endl;
}

PointTest::~PointTest()
{
	std::cout << "PointTest ~..." << std::endl;
}

PointTest::PointTest(PointTest& pt)
{
	this->a = pt.a;
	this->b = pt.b;

	// 深拷贝的原因，以免同一个地址(this->b)重复delete
	//this->b = new int();
	//*this->b = *pt.b;

	std::cout << "PointTest copy..." << std::endl;
}

PointTest PointTest::operator = (PointTest& pt)
{
	std::cout << "PointTest =..." << std::endl;
	return pt;
}

void PointTest::allocTest()
{

	// 在栈上分配内存，并调用对象的构造函数，退出作用域后自动销毁
	PointTest pt01;

	// 这里只是定义了一个PointTest类型指针，其地址为0
	PointTest* pt02 = nullptr;
	// 在堆上动态分配了一块内存给new出来的那个对象(这里暂时叫做tmp)，并把首地址赋值给pt02，这样pt02就指向了tmp，通过调用delete pt02销毁tmp
	pt02 = new PointTest();


	PointTest* pt03 = nullptr;
	// pt02，pt03只是地址相同，并根据拷贝构造函数和赋值运算符重载函数得出，指向的的对象是否为同一个
	pt03 = pt02;
	pt03 = nullptr;
	cout << pt02 << endl;

	// 引用不能声明，只能定义
	PointTest& pt04 = pt01;
	//cout << &pt04 << "," << &pt01 << endl;
	//pt02 = &pt04;
	//pt04 = *pt02;

	// 这里会因为使用默认拷贝构造函数而报错
	PointTest pt05 = pt01;

}

void PointTest::copyActorTest()
{
	//PointTest pt;
	//this->copyActorTest01(pt);
	//this->copyActorTest02();
	this->copyActorTest03();
	// 由上三点可知，在c++中，当一个对象初始化为另一个同类型对象的时候，就会调用拷贝构造函数，这里注意深浅拷贝
}

void PointTest::copyActorTest01(PointTest _pt)
{
	// 按值传递，实际上是以实参为参数调用形参的拷贝构造函数，即PointTest _pt(pt)
}

PointTest PointTest::copyActorTest02()
{
	PointTest pt01;
	// 以值的形式返回一个临时对象，实际上是 PointTest _tmp(pt01)
	return pt01;
}

void PointTest::copyActorTest03()
{
	PointTest pt01;

	// 初始化对象为另一个对象，实际上是PointTest pt02(pt01)，注意初始化不会调用赋值运算符重载
	PointTest pt02 = pt01;

	PointTest pt03;
	// 定义对象为另一个对象，实际上调用pt03.operator=(pt01)
	pt03 = pt01;
}