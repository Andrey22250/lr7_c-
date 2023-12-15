#pragma once
#include <string>
#include <iostream>

using namespace std;

class Motherboard
{
public:
	Motherboard();
	Motherboard(string name_mrbrd);
	Motherboard(string name_mrbrd, string chipset);
	~Motherboard();

	bool CheckCor(string name_mrbrd, string chipset);

	string GetName();
	string GetChipset();
	void input_mrbrd();
	void SetMrbrd(string name_mrbrd, string chipset);
private:
	string name_mrbrd = "", chipset = "";
};
