// project2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void extendsTest01()
{
	// A a编译器在栈中开辟出一块空间，并移动栈顶指针，然后调用构造函数填充栈开辟出来的空间，使用完后自动调用析构函数，回收开辟的空间，栈顶指针减一
	ExtendsTest t1;
	ExtendsTest* t2 = nullptr;

	cout << "---------------------" << endl;
	// 子类实例化时构造的过程和子类销毁时析构的过程
	ExtendsTest* test = new ExtendsTest();
	delete test;

	cout << "---------------------" << endl;
	// 把ExtendsTest实例化出来的一大块对象地址(包括基类的成员变量及函数地址)赋值给base对象，此时会出现地址切割，示意图如下
	ExtendsTestBase* base = new ExtendsTest();
	/*--------------------------------------*/
	/*|   ExtendsTestBase的对象xx占用的内存  |                    -----------------------------------------*/
	/*|                                     |   ————赋值给————>  |   ExtendsTestBase的对象xxxx占用的内存  |*/
	/*|   ExtendsTest的对象xxx占用的内存     |                    -----------------------------------------*/
	/*--------------------------------------*/
	// 基类析构函数不加virtual关键字时，此时编译器对base指针调用delete函数执行静态绑定，只调用base对象内存中的析构函数
	delete base; // 相当于base->~ExtendsTestBase()吧？

	cout << "---------------------" << endl;
	// 基类析构函数加上virtual关键字时，此时编译器对base01指针调用delete函数执行动态绑定，调用[①base01指针的地址][②所存储的对象]的[③vptr][④指向的函数]
	// ① 即是new ExtendsTest出来的对象的地址，假设对象首地址是 1000；
	// ② 地址1000存储的对象即是new ExtendsTest出来的对象；
	// ③ new ExtendsTest出来的对象的vptr，对于有虚函数的类来说每一个对象都有一个vptr，但都指向同一个vtable；
	// ④ new ExtendsTest出来的对象的vtable里面存储的是类ExtendsTest的析构函数，因为子类覆盖了基类的virtual ~()；
	ExtendsTestBase* base01 = new ExtendsTest();
	delete base01;

	cout << "---------------------" << endl;
	ExtendsTest test02;
	// 注意，此时并不是调用基类的funHiden1(int)函数，这里不是重载因为超出了重载的作用域，而是隐藏
	test02.funHiden1(1);
	test02.funHiden1(1.0);
	
	cout << "---------------------" << endl;
	ExtendsTestBase* base04 = new ExtendsTest();
	// 这里是隐藏，而不是覆盖(重写)
	base04->funHiden2(1);
	// 这里就是覆盖(重写)了，覆盖与隐藏的区别就在于基类的virtual关键字，即多态的体现
	base04->funOverride1(1);

}

void extendsTest02()
{
	// 声明了纯虚函数的类为抽象类(虚基类)，不能直接实例化
	// ExtendsTestBase base01;
	// 没调用到基类的构造函数，不
	// ExtendsTest test01;
}

int _tmain(int argc, _TCHAR* argv[])
{

	//while (true)
	//{
	//	cout << "请选择菜单：(输入-1退出程序)";
	//	int id;
	//	cin >> id; // cin >> 遇空格符结束
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
	//		cout << "输入有误~~" << endl;
	//		break;
	//	}
	//}

	extendsTest01();

	system("pause");
	return 0;
}

