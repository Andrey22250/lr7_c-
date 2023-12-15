#pragma once
#include <iostream>
#include <string>

using namespace std;

class GPU
{
public:
	GPU();
	GPU(string name_gpu);
	GPU(string name_gpu, int vram, int TDP);
	~GPU();

	bool CheckCor(string name_gpu, int vram, int TDP);

	string GetName();
	int GetVram();
	int GetTDP();
	int GetMin_TDP();
	void input_gpu();
	void SetGpu(string name_gpu, int vram, int TDP);
private:
	string name_gpu;
	int vram, TDP, Min_TDP;
	int flag = 0;
};