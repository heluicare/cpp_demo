#ifndef _SOME01_NEWPROPERTYC11_H_
#define _SOME01_NEWPROPERTYC11_H_

class NewPropertyC11
{
public:
	NewPropertyC11();
	~NewPropertyC11();

	void funcPointTest();

	void funcTemplateTest();
	// ����һ������ָ�룬ָ��funcPtָ��һ������ֵΪint������int�����ĺ���
	int(*funcPt0)(int, int);
	typedef int(*FuncPt1)(int, int);

	void funcClassTemplateTest();

	void classTemplateTest();


private:

};

#endif // !_SOME01_NEWPROPERTYC11_H_
