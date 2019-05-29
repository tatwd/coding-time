/* 责任链模式 p.147 */

#include <iostream>
#include <vector>

/* 被过滤器链（责任链）处理的消息 */
class Message
{
public:
	int GetData() { return data; }
	void SetData(int data) { this->data = data; }

private:
	int data;
};

class Filter
{
public:
	virtual ~Filter() {}

	virtual bool DoFilter(Message &msg) = 0;
};

class FilterChain : public Filter
{
public:
	virtual bool DoFilter(Message &msg) {
		for (auto f : filters) {
			if (!(f->DoFilter(msg)))
				break;
			f->DoFilter(msg);
		}
	}

	FilterChain &Add(Filter *filter) {
		filters.push_back(filter);
		return *this;
	}

private:
	std::vector<Filter *> filters;
};

class FilterA : public Filter
{
public:
	virtual bool DoFilter(Message &msg) {
		msg.SetData(2);
		return true;
	}
};

class FilterB : public Filter
{
public:
	virtual bool DoFilter(Message &msg) {
		msg.SetData(3);
		return false;
	}
};

class FilterC : public Filter
{
public:
	virtual bool DoFilter(Message &msg) {
		msg.SetData(4);
		return true;
	}
};

/* 测试 */
int main(void)
{
	Message msg;
	msg.SetData(1);

	FilterChain chain;

	chain.Add(new FilterA)
	     .Add(new FilterB)
	     .Add(new FilterC);

	chain.DoFilter(msg);
	std::cout << msg.GetData() << "\n";

	return 0;
}
