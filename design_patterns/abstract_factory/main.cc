/* 抽象工厂 p.57 */

#include <iostream>

class Product {
public:
	int GetID() { return _id; }
	Product(int id) { _id = id; }
private:
	int _id;
};

class AbstractProductA : public Product {
public:
	std::string GetType() { return _type; }
	AbstractProductA(int id) : Product(id) {}
private:
	std::string _type = "A";
};

class ProductA1 : public AbstractProductA {
public:
	ProductA1(int id) : AbstractProductA(id) {}
};

class ProductA2 : public AbstractProductA {
public:
	ProductA2(int id) : AbstractProductA(id) {}
};

class AbstractProductB : public Product {
public:
	std::string GetType() { return _type; }
	AbstractProductB(int id) : Product(id) {}
private:
	std::string _type = "B";
};

class ProductB1 : public AbstractProductB {
public:
	ProductB1(int id) : AbstractProductB(id) {}
};

class ProductB2 : public AbstractProductB {
public:
	ProductB2(int id) : AbstractProductB(id) {}
};

class AbstractFactory {
public:
	virtual AbstractProductA *CreateProductA() = 0;
	virtual AbstractProductB *CreateProductB() = 0;
};

class ConcreteFactory1 : public AbstractFactory {
public:
	AbstractProductA *CreateProductA() { return new ProductA1(10); }
	AbstractProductB *CreateProductB() { return new ProductB1(20); }
};

class ConcreteFactory2 : public AbstractFactory {
public:
	AbstractProductA *CreateProductA() { return new ProductA2(11); }
	AbstractProductB *CreateProductB() { return new ProductB2(22); }
};

/* test client */
class Client {
public:
	void Create(AbstractFactory *factory) {
		AbstractProductA *pa = factory->CreateProductA();
		AbstractProductB *pb = factory->CreateProductB();
		std::cout << pa->GetType() << " " << pa->GetID() << "\n"
				  << pb->GetType() << " " << pb->GetID() << "\n";
	}
};

int main(void)
{
	Client *client = new Client;
	AbstractFactory *factory1 = new ConcreteFactory1;
	AbstractFactory *factory2 = new ConcreteFactory2;
	client->Create(factory1);
	client->Create(factory2);
	return 0;
}
