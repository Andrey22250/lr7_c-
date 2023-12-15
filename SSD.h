#pragma once
#include <string>
#include "DataStor.h"

using namespace std;

class SSD : public DataStor
{
public:
	SSD() = default;
	SSD(int speed, string type_ssd, string type, int vol);
	~SSD() = default;

	void operator=(SSD other);
	friend std::ostream& operator << (std::ostream& out, const SSD& hdd);

	string getCompName() const override;
	int getSpeed() const;
	string GetTypeSSD() const;
	void input() override;
private:
	int speed = 0;
	string type_ssd;
	void SetSSD(int speed, string type_ssd);
};
