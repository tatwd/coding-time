/* 观察者模式 p.194 */

#include <iostream>

#include "observer.h"
#include "subject.h"

/* 目标 A */
class SubjectA : public Subject
{
public:
	int GetState() { return state; }
	void SetState(int value) { state = value; }
	void Change() {
		state++;
		Notify();
	}

private:
	int state = 1;
};

/* 观察者 A 负责观察目标 A 的状态 */
class ObserverA : public Observer
{
public:
	virtual ~ObserverA(){
		_subject->Detach(this);
	}
	ObserverA(Subject* s) { // 由观察者来决定订阅谁
		_subject = (SubjectA*)s;
		//_subject->Attach(this);
		s->Attach(this); // 订阅 s
	}

	virtual void Update() { std::cout << "Hello world!\n"; }
	virtual void Update(Subject *s) {
		if (s == _subject) {
			// std::cout << _subject->GetState() << "\n";
			std::cout << ((SubjectA*)s)->GetState() << "\n";
		}
	}

private:
	SubjectA* _subject;
};


/* 测试 */
int main(void)
{
	SubjectA *subject = new SubjectA;
	ObserverA *observer = new ObserverA(subject);
	subject->Change();
	subject->SetState(10);
	subject->Change();
	return 0;
}
