// project2.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"

void extendsTest01()
{
	// A a��������ջ�п��ٳ�һ��ռ䣬���ƶ�ջ��ָ�룬Ȼ����ù��캯�����ջ���ٳ����Ŀռ䣬ʹ������Զ������������������տ��ٵĿռ䣬ջ��ָ���һ
	ExtendsTest t1;
	ExtendsTest* t2 = nullptr;

	cout << "---------------------" << endl;
	// ����ʵ����ʱ����Ĺ��̺���������ʱ�����Ĺ���
	ExtendsTest* test = new ExtendsTest();
	delete test;

	cout << "---------------------" << endl;
	// ��ExtendsTestʵ����������һ�������ַ(��������ĳ�Ա������������ַ)��ֵ��base���󣬴�ʱ����ֵ�ַ�иʾ��ͼ����
	ExtendsTestBase* base = new ExtendsTest();
	/*--------------------------------------*/
	/*|   ExtendsTestBase�Ķ���xxռ�õ��ڴ�  |                    -----------------------------------------*/
	/*|                                     |   ����������ֵ����������>  |   ExtendsTestBase�Ķ���xxxxռ�õ��ڴ�  |*/
	/*|   ExtendsTest�Ķ���xxxռ�õ��ڴ�     |                    -----------------------------------------*/
	/*--------------------------------------*/
	// ����������������virtual�ؼ���ʱ����ʱ��������baseָ�����delete����ִ�о�̬�󶨣�ֻ����base�����ڴ��е���������
	delete base; // �൱��base->~ExtendsTestBase()�ɣ�

	cout << "---------------------" << endl;
	// ����������������virtual�ؼ���ʱ����ʱ��������base01ָ�����delete����ִ�ж�̬�󶨣�����[��base01ָ��ĵ�ַ][�����洢�Ķ���]��[��vptr][��ָ��ĺ���]
	// �� ����new ExtendsTest�����Ķ���ĵ�ַ����������׵�ַ�� 1000��
	// �� ��ַ1000�洢�Ķ�����new ExtendsTest�����Ķ���
	// �� new ExtendsTest�����Ķ����vptr���������麯��������˵ÿһ��������һ��vptr������ָ��ͬһ��vtable��
	// �� new ExtendsTest�����Ķ����vtable����洢������ExtendsTest��������������Ϊ���า���˻����virtual ~()��
	ExtendsTestBase* base01 = new ExtendsTest();
	delete base01;

	cout << "---------------------" << endl;
	ExtendsTest test02;
	// ע�⣬��ʱ�����ǵ��û����funHiden1(int)���������ﲻ��������Ϊ���������ص������򣬶�������
	test02.funHiden1(1);
	test02.funHiden1(1.0);
	
	cout << "---------------------" << endl;
	ExtendsTestBase* base04 = new ExtendsTest();
	// ���������أ������Ǹ���(��д)
	base04->funHiden2(1);
	// ������Ǹ���(��д)�ˣ����������ص���������ڻ����virtual�ؼ��֣�����̬������
	base04->funOverride1(1);

}

void extendsTest02()
{
	// �����˴��麯������Ϊ������(�����)������ֱ��ʵ����
	// ExtendsTestBase base01;
	// û���õ�����Ĺ��캯������
	// ExtendsTest test01;
}

int _tmain(int argc, _TCHAR* argv[])
{

	//while (true)
	//{
	//	cout << "��ѡ��˵���(����-1�˳�����)";
	//	int id;
	//	cin >> id; // cin >> ���ո������
	//	switch (id)
	//	{
	//	case 1:
	//		cout << id << endl;
	//		break;
	//	default:
	//		if (cin.fail())
	//		{
	//			cin.clear();
	//			cin.sync();
	//		}
	//		cout << "��������~~" << endl;
	//		break;
	//	}
	//}

	extendsTest01();

	system("pause");
	return 0;
}

