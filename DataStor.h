#pragma once
#include <string>
#include <iostream>
using namespace std;

class DataStor abstract
{
public:
	DataStor() = default;
	DataStor(string type, int vol);
	~DataStor() = default;

	void operator=(DataStor* other);

	virtual string getCompName() const abstract = 0;
	virtual int GetVol();
	virtual void input();
protected:
	int vol = 0;
	string type;

	void SetDataStor(string type, int vol);
};

