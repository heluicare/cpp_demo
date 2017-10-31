#ifndef _SOME01_POINTTEST_H_
#define _SOME01_POINTTEST_H_

class PointTest
{
public:
	PointTest();
	PointTest(PointTest& pt);
	PointTest operator = (PointTest& pt);
	~PointTest();

	void allocTest();
	void copyActorTest();

private:
	int a = 0;
	int* b;

	void copyActorTest01(PointTest _pt);
	PointTest copyActorTest02();
	void copyActorTest03();

};

#endif // !_SOME01_POINTTEST_H_
