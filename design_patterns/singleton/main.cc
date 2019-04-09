/* 单件 p.84 */

#include <iostream>

class Singleton
{
public:
	static Singleton *Instance();
protected:
	Singleton(){ std::cout << "init!\n"; }
private:
	static Singleton *_instance;
};

Singleton *Singleton::_instance = 0;

Singleton *Singleton::Instance()
{
	/* 线程不安全 */
	if (_instance == 0)
		_instance = new Singleton(); /* lazy init */
	return _instance;
}

int main(void)
{
	Singleton *o1 = Singleton::Instance();
	Singleton *o2 = Singleton::Instance();
	std::cout << o1 << "\n"
	          << o2 << "\n";
	return 0;
}
