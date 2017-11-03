#ifndef _SOME01_NEWPROPERTYC11_H_
#define _SOME01_NEWPROPERTYC11_H_

class NewPropertyC11
{
public:
	NewPropertyC11();
	~NewPropertyC11();

	void funcPointTest();

	void funcTemplateTest();
	// 声明一个函数指针，指针funcPt指向一个返回值为int且两个int参数的函数
	int(*funcPt0)(int, int);
	typedef int(*FuncPt1)(int, int);

	void funcClassTemplateTest();

	void classTemplateTest();


private:

};

#endif // !_SOME01_NEWPROPERTYC11_H_
