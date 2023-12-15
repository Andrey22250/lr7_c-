#pragma once
#include <iostream>

using namespace std;

class BuildTab abstract
{
public:
	virtual string GetComponentName() const abstract = 0;
	virtual string GetModelName() const abstract = 0;
	virtual void input() abstract = 0;
	virtual string toString() const abstract = 0;
};

