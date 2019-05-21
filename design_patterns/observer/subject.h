#ifndef SUBJECT_H
#define SUBJECT_H

#include <vector>

#include "observer.h"

class Subject
{
public:
	virtual ~Subject() {}

	virtual void Attach(Observer *o);
	virtual void Detach(Observer *o);
	virtual void Notify();

private:
	std::vector<Observer *> observers;
};

#endif
