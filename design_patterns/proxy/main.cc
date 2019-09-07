/* 代理 p.137 */

#include <iostream>

class Subject 
{
public:
	virtual ~Subject() {}

	virtual void request() = 0;
};

class RealSubject: public Subject 
{
public:
	virtual ~RealSubject() {}

	virtual void request() { std::cout << "I am RealSubject!\n";  }
};

class ProxySubject: public Subject 
{
public:
	ProxySubject() { _realSubject = new RealSubject; }
	virtual ~ProxySubject() {}

	virtual void request() { _realSubject->request(); }

private:
	RealSubject* _realSubject;
};

int main(void)
{
	Subject *subject = new ProxySubject;
	subject->request();
	delete subject;
	return 0;
}
