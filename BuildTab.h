#pragma once
#include <iostream>

using namespace std;

class BuildTab abstract
{
public:
	virtual string GetCompName() const abstract = 0;
	virtual string GetModName() const abstract = 0;
	virtual void input() abstract = 0;
};

