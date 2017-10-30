#include "stdafx.h"

// 类的静态成员变量在使用前必须先定义
int ExtendsTestBase::a;

ExtendsTestBase::ExtendsTestBase()
{
	cout << "ExtendsTestBase()..." << endl;
}

ExtendsTestBase::~ExtendsTestBase()
{
	cout << "~ExtendsTestBase()..." << endl;
}

void ExtendsTestBase::funHiden1(int _i)
{
	cout << "ExtendsTestBase() funHiden1(int)..." << endl;
}

void ExtendsTestBase::funHiden2(int _i)
{
	cout << "ExtendsTestBase() funHiden2(int)..." << endl;
}

void ExtendsTestBase::funOverride1(int _i)
{
	cout << "ExtendsTestBase() funOverride1(int)..." << endl;
}

ExtendsTest::ExtendsTest()
{
	cout << "ExtendsTest()..." << endl;
}

ExtendsTest::~ExtendsTest()
{
	cout << "~ExtendsTest()..." << endl;
}

void ExtendsTest::funHiden1(float _i)
{
	cout << "ExtendsTest() funHiden1(float)..." << endl;
}

void ExtendsTest::funHiden2(int _i)
{
	cout << "ExtendsTest() funHiden2(float)..." << endl;
}

void ExtendsTest::funOverride1(int _i)
{
	cout << "ExtendsTest() funOverride1(int)..." << endl;
}

void ExtendsTest::funUseStatic()
{
	a = 1;
	cout << "ExtendsTest() fun2()..." << endl;
}

void ExtendsTest::funUseNoStatic()
{
	b = 1;
	cout << "ExtendsTest() fun3()..." << endl;
}