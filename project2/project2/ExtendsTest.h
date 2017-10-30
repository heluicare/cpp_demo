#ifndef _PROJECT2_EXTENDSTEST_H_
#define _PROJECT2_EXTENDSTEST_H_


class ExtendsTestBase
{
public:
	ExtendsTestBase();
	~ExtendsTestBase();
	static int a;
	int b;
	void funHiden1(int _i);
	void funHiden2(int _i);
	virtual void funOverride1(int _i);
	//virtual void funAbstract() = 0;

private:

};


class ExtendsTest : public ExtendsTestBase
{
public:
	ExtendsTest();
	~ExtendsTest();
	void funHiden1(float _f);
	void funHiden2(int _i);
	void funOverride1(int _i);
	void funUseStatic();
	void funUseNoStatic();

private:

};


#endif // !_PROJECT2_EXTENDSTEST_H_
