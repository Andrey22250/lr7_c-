#include <iostream>
#include <string>
#include "CPU.h"

void CPU::operator=(const CPU other) {
	this->name_cpu = other.GetName();
	this->frequency = other.GetFrequency();
	this->cores = other.GetCores();
	this->treads = other.GetTreads();
}

CPU operator+(const CPU& cpu, int addable) {
	return CPU(cpu.GetName(), cpu.GetFrequency() + addable, cpu.GetCores() , cpu.GetTreads());
}

CPU& operator++(CPU& cpu) {
	cpu.SetCpu(cpu.GetName(), cpu.GetFrequency(), cpu.GetCores(), cpu.GetTreads());
	return cpu;
}

CPU operator++(CPU& cpu, int) {
	CPU tempCPU = cpu;
	++cpu;
	return tempCPU;
}

std::ostream& operator << (ostream& out, const CPU& cpu) {
	out << cpu.GetName();
	return out;
}

inline void clean()  //Очистка потока
{
	while (getchar() != '\n');
}

bool CPU::CheckCor(string name_cpu, int frequency, int cores, int treads) const
{
	if (size(name_cpu) != 0 && frequency > 0 && cores > 0 && treads > 0 && cores <=treads)
		return true;
	else
		throw invalid_argument("Некорректный формат данных!");
}

void CPU::SetCpu(string name_cpu, int frequency, int cores, int treads)
{
	if (CheckCor(name_cpu, frequency, cores, treads))
	{
		this->name_cpu = name_cpu;
		this->frequency = frequency;
		this->cores = cores;
		this->treads = treads;
	}
}
//Конструкторы
CPU::CPU()
{
	frequency = cores = treads = 0;
}

CPU::CPU(string name_cpu)
{
	this->name_cpu = name_cpu;
	frequency = cores = treads = 0;
}

CPU::CPU(string name_cpu, int frequency, int cores, int treads)
{
	if (CheckCor(name_cpu, frequency, cores, treads))
	{
		this->name_cpu = name_cpu;
		this->frequency = frequency;
		this->cores = cores;
		this->treads = treads;
	}
}
//Деструктор
CPU::~CPU()
{
}

//Получение
int CPU::GetFrequency() const
{
	return frequency;
}

int CPU::GetCores() const
{
	return cores;
}

int CPU::GetTreads() const
{
	return treads;
}

string CPU::GetName() const
{
	return name_cpu;
}
//Ввод
void CPU::input_cpu()
{
	int frequency, cores, treads;
	string name_cpu;
	printf("\nВвод параметров процессора\n");
	printf("\nВведите название процессора: ");
	getline(cin, name_cpu);
	do
	{
		printf("Введите частоту процессора в МГЦ: ");
		scanf("%d", &frequency);
		clean();
	} while (frequency <= 0 || frequency >= 7000);
	do
	{
		printf("Введите кол-во ядер: ");
		scanf("%d", &cores);
		clean();
	} while (cores <= 0 || cores > 256);
	do
	{
		printf("Введите кол-во потоков: ");
		scanf("%d", &treads);
		clean();
	} while (treads <= 0 && treads > 512);
	SetCpu(name_cpu, frequency, cores, treads);
}