#include <iostream>

#include "subject.h"

void Subject::Attach(Observer *o) { observers.push_back(o); }

void Subject::Detach(Observer *o)
{
	std::vector<Observer *>::iterator i;
	for (i = observers.begin(); i != observers.end();) {
		if (*i == o)
			observers.erase(i);
		else
			i++;
	}
}

void Subject::Notify()
{
	for (auto o : observers) {
		o->Update(this);
	}
}
