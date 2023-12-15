#pragma once
#include <iostream>
#include <string>
#include "CPU.h"
#include "GPU.h"
#include "Ram.h"
#include "Mrbrd.h"

using namespace std;

class PC
{
public:
	PC() = default;
	PC(float price);
	PC(float price, CPU cpu, GPU gpu, RAM ram, Motherboard *mrbrd);
	~PC();

	float GetPrice();
	CPU& GetCpu();
	GPU& GetGpu();
	RAM& GetRam();
	Motherboard* GetMrbrd();
	void input_pc();
	void Undervolt_GPU();
	void Out_PC();
	void SetPrice(float price);
private:
	float price;
	CPU cpu;
	GPU gpu;
	RAM ram;
	Motherboard *mrbrd = new Motherboard();
};