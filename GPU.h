#pragma once
#include <iostream>
#include <string>
#include "BuildTab.h"

using namespace std;

class GPU : public BuildTab
{
public:
	GPU();
	GPU(string name_gpu);
	GPU(string name_gpu, int vram, int TDP);
	~GPU();

	void operator=(GPU other);
	friend ostream& operator << (ostream& out, const GPU& gpu);

	bool CheckCor(string name_gpu, int vram, int TDP);

	string GetCompName() const override;
	string GetModName() const;
	int GetVram();
	int GetTDP();
	int GetMin_TDP();
	void input();
	void SetGpu(string name_gpu, int vram, int TDP);
private:
	string name_gpu;
	int vram, TDP, Min_TDP;
	int flag = 0;
};