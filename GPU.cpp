#include <iostream>
#include "GPU.h"

inline void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

GPU::GPU()
{
	vram = TDP = Min_TDP = 0;
	flag = 1;
}

GPU::GPU(string name_gpu)
{
	this->name_gpu = name_gpu;
	vram = TDP = Min_TDP = 0;
	flag = 1;
}

GPU::GPU(string name_gpu, int vram, int TDP)
{
	if (CheckCor(name_gpu, vram, TDP))
	{
		this->name_gpu = name_gpu;
		this->vram = vram;
		this->TDP = TDP;
	}
	if (flag == 0)
	{
		this->Min_TDP = TDP * 0.85;
		flag = 1;
	}
}

GPU::~GPU()
{
}

bool GPU::CheckCor(string name_gpu, int vram, int TDP)
{
	if (size(name_gpu) != 0 && vram > 0 && TDP > 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

string GPU::GetName()
{
	return name_gpu;
}

int GPU::GetVram()
{
	return vram;
}

int GPU::GetTDP()
{
	return TDP;
}

int GPU::GetMin_TDP()
{
	return Min_TDP;
}

void GPU::SetGpu(string name_gpu, int vram, int TDP)
{
	if (CheckCor(name_gpu, vram, TDP))
	{
		this->name_gpu = name_gpu;
		this->vram = vram;
		this->TDP = TDP;
		this->Min_TDP = TDP * 0.85;
		flag = 1;
	}
}

void GPU::input_gpu()
{
	printf("\nВвод параметров видеокарты\n");
	string name_gpu;
	int vram, TDP;
	printf("\nВведите название видеокарты: ");
	getline(cin, name_gpu);
	do
	{
		printf("Введите объём видеопамяти в МБ: ");
		scanf("%d", &vram);
		clean();
	} while (vram <= 0);
	do
	{
		printf("Введите TDP в ваттах: ");
		scanf("%d", &TDP);
		clean();
	} while (TDP <= 0);
	SetGpu(name_gpu, vram, TDP);
}