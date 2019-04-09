/* 生成器 p.63 */

#include <iostream>

class NameBuilder
{
public:
	virtual void BuildFirstName(std::string s) {}
	virtual void BuildLastName(std::string s) {}
	virtual std::string GetName() { return 0; }
};

class SimpleNameBuilder : public NameBuilder
{
public:
	virtual void BuildFirstName(std::string s) { _name = s; }
	virtual void BuildLastName(std::string s) { _name += " " + s; }
	virtual std::string GetName() { return _name; }
private:
	std::string _name;
};

class Director
{
public:
	std::string CreateName(NameBuilder &builder) {
		builder.BuildFirstName("John");
		builder.BuildLastName("Doe");
		return builder.GetName();
	}
};

int main(void)
{
	Director director;
	SimpleNameBuilder builder;
	std::string name = director.CreateName(builder);
	std::cout << name << "\n";
	return 0;
}
