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

	// �����ԭ������ͬһ����ַ(this->b)�ظ�delete
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

	// ��ջ�Ϸ����ڴ棬�����ö���Ĺ��캯�����˳���������Զ�����
	PointTest pt01;

	// ����ֻ�Ƕ�����һ��PointTest����ָ�룬���ַΪ0
	PointTest* pt02 = nullptr;
	// �ڶ��϶�̬������һ���ڴ��new�������Ǹ�����(������ʱ����tmp)�������׵�ַ��ֵ��pt02������pt02��ָ����tmp��ͨ������delete pt02����tmp
	pt02 = new PointTest();


	PointTest* pt03 = nullptr;
	// pt02��pt03ֻ�ǵ�ַ��ͬ�������ݿ������캯���͸�ֵ��������غ����ó���ָ��ĵĶ����Ƿ�Ϊͬһ��
	pt03 = pt02;
	pt03 = nullptr;
	cout << pt02 << endl;

	// ���ò���������ֻ�ܶ���
	PointTest& pt04 = pt01;
	//cout << &pt04 << "," << &pt01 << endl;
	//pt02 = &pt04;
	//pt04 = *pt02;

	// �������Ϊʹ��Ĭ�Ͽ������캯��������
	PointTest pt05 = pt01;

}

void PointTest::copyActorTest()
{
	//PointTest pt;
	//this->copyActorTest01(pt);
	//this->copyActorTest02();
	this->copyActorTest03();
	// ���������֪����c++�У���һ�������ʼ��Ϊ��һ��ͬ���Ͷ����ʱ�򣬾ͻ���ÿ������캯��������ע����ǳ����
}

void PointTest::copyActorTest01(PointTest _pt)
{
	// ��ֵ���ݣ�ʵ��������ʵ��Ϊ���������βεĿ������캯������PointTest _pt(pt)
}

PointTest PointTest::copyActorTest02()
{
	PointTest pt01;
	// ��ֵ����ʽ����һ����ʱ����ʵ������ PointTest _tmp(pt01)
	return pt01;
}

void PointTest::copyActorTest03()
{
	PointTest pt01;

	// ��ʼ������Ϊ��һ������ʵ������PointTest pt02(pt01)��ע���ʼ��������ø�ֵ���������
	PointTest pt02 = pt01;

	PointTest pt03;
	// �������Ϊ��һ������ʵ���ϵ���pt03.operator=(pt01)
	pt03 = pt01;
}