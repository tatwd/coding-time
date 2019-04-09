/* 原型 p.77 */

#include <iostream>

class Prototype
{
public:
	virtual Prototype *Clone() = 0;
};

class A : public Prototype
{
public:
	A() { _name = "John Doe"; }
	A(const A& a);
	virtual A *Clone();
	void Show() { std::cout << _name << "\n"; }
private:
	std::string _name;
};

A::A(const A& a) { _name = a._name; }

A *A::Clone()
{
	return new A(*this);
}

int main(void)
{
	A *proto = new A;
	A *cloned = proto->Clone();
	cloned->Show();
	std::cout << proto << "\n"
	          << cloned << "\n";
	return 0;
}
