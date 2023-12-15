#pragma once
#include <string>
#include "DataStor.h"

using namespace std;

class HDD : public DataStor
{
public:
	HDD() = default;
	HDD(int speed, string type, int vol);
	~HDD() = default;

	void operator=(HDD other);
	friend std::ostream& operator << (std::ostream& out, const HDD& hdd);
	
	string getCompName() const override;
	int getSpeed() const;
	void input() override;
private:
	int speed = 0;
	void SetHDD(int speed);
};