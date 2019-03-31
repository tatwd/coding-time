/* 工厂方法 p.70 */

#include <iostream>

class Product
{
public:
	int GetID() { return _id; }
	Product(int id) { _id = id; }
private:
	int _id;
};

class ProductA: public Product
{
public:
	ProductA(int id) : Product(id) {};
};

class Creator
{
public:
	virtual Product* CreateProduct() = 0;
};

template <class T>
class MyCreator : public Creator
{
public:
	virtual Product* CreateProduct();
};

template <class T>
Product* MyCreator<T>::CreateProduct()
{
	return new T(11);
}

/*
class Client
{
public:
	static Product *create(Creator *creator) {
		return creator->CreateProduct();
	}
};
*/

int main(void)
{
	Creator *c = new MyCreator<Product>;
	Product *p = c->CreateProduct();
	/* Product *p = Client::create(new MyCreator<Product>); */
	std::cout << p->GetID() << "\n";
	return 0;
}
