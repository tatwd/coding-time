/* 模板代码 p.214 */

#include <iostream>

class Operator
{
public:
	int Add(int a, int b) {
		return First(a) + Last(b);
	}
protected:
	virtual int First(int v) { return v; }
	virtual int Last(int v) { return v; }
};

class OperatorImpl : public Operator
{
public:
	virtual int First(int v) { return ++v; }
	/* virtual int Last(int v) { return ++v; } */
};

int main(void)
{
	Operator *opt = new OperatorImpl;
	int result = opt->Add(1, 2);
	std::cout << result << std::endl;
	delete opt;
	return 0;
}
