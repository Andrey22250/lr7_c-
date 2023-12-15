#pragma once
#include <iostream>
#include <string>

using namespace std;

class RAM
{
public:
	RAM();
	RAM(string type_ddr);
	RAM(string type_ddr, int frequency, int mem);
	~RAM();

	bool CheckCor(string type_ddr, int frequency, int mem);

	string GetType();
	int GetFrequencyRam();
	int GetMem();
	void SetRam(string type_ddr, int frequency, int mem);
	void input_ram();
private:
	string type_ddr;
	int frequency, mem;
};