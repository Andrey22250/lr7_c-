#include "PC.h"

inline void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

PC::PC(float price)
{
	if (price > 0)
	{
		cpu = CPU();
		gpu = GPU();
		ram = RAM();
		*mrbrd = Motherboard();
		this->price = price;
	}
}

PC::PC(float price, CPU cpu, GPU gpu, RAM ram, Motherboard *mrbrd)
{
	if (price > 0)
	{
		this->price = price;
		this->cpu = cpu;
		this->gpu = gpu;
		this->ram = ram;
		Motherboard* newmrbrd = mrbrd;
		this->mrbrd = newmrbrd;
	}
}

PC::~PC()
{
}

float PC::GetPrice()
{
	return price;
}

CPU& PC::GetCpu()
{
	return cpu;
}

GPU& PC::GetGpu()
{
	return gpu;
}

RAM& PC::GetRam()
{
	return ram;
}

Motherboard* PC::GetMrbrd()
{
	return mrbrd;
}

void PC::input_pc()
{
	float price;
	printf("\nВвод информации о компьютере\n");
	do
	{
		printf("Введите цену ПК: ");
		scanf("%f", &price);
		clean();
	} while (price <= 0);
	cpu.input_cpu();
	gpu.input_gpu();
	ram.input_ram();
	mrbrd->input_mrbrd();
	SetPrice(price);
}

void PC::Undervolt_GPU()
{
	if (this->gpu.GetTDP() - 3 > this->gpu.GetMin_TDP())
	{
		gpu = GPU(this->gpu.GetName(), this->gpu.GetVram(), this->gpu.GetTDP() - 3);
		if (this->gpu.GetTDP() <= this->gpu.GetMin_TDP())
			gpu = GPU(this->gpu.GetName(), this->gpu.GetVram(), this->gpu.GetMin_TDP());
	}
	else printf("Undervolt невозможен!");
}

void PC::Out_PC()
{
	printf("\nИнформация о сборке:\n\n");
	printf("Процессор: %s, %d МГЦ, %d ядер, %d потоков\n", this->cpu.GetName().c_str(), this->cpu.GetFrequency(), this->cpu.GetCores(), this->cpu.GetTreads());
	printf("Видеокарта: %s, %d VRAM, %d TDP\n", this->gpu.GetName().c_str(), this->gpu.GetVram(), this->gpu.GetTDP());
	printf("ОЗУ: %s, %d частота, %d объём\n", this->ram.GetType().c_str(), this->ram.GetFrequencyRam(), this->ram.GetMem());
	printf("Материнская плата: %s, %s чипсет\n", this->mrbrd->GetName().c_str(), this->mrbrd->GetChipset().c_str());
	printf("Цена сборки: %.2f\n\n", this->price);
}

void PC::SetPrice(float price)
{
	this->price = price;
}