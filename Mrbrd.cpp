#include "Mrbrd.h"

bool Motherboard::CheckCor(string name_mrbrd, string chipset)
{
	if (size(name_mrbrd) != 0 && size(chipset) != 0)
		return true;
	else
	{
		printf("Неверно, выход из программы...");
		exit(-1);
	}
}

Motherboard::Motherboard()
{
	this->name_mrbrd = "";
	this->chipset = "";
}

Motherboard::Motherboard(string name_mrbrd)
{
	this->name_mrbrd = name_mrbrd;
	this->chipset = "";
}

Motherboard::Motherboard(string name_mrbrd, string chipset)
{
	if (CheckCor(name_mrbrd, chipset))
	{
		this->name_mrbrd = name_mrbrd;
		this->chipset = chipset;
	}
}

Motherboard::~Motherboard()
{
}

string Motherboard::GetName()
{
	return name_mrbrd;
}

string Motherboard::GetChipset()
{
	return chipset;
}

void Motherboard::input_mrbrd()
{
	string name_mrbrd, chipset;
	printf("\nВвод параметров материнской платы\n");
	printf("\nВведите название материнской платы: ");
	getline(cin, name_mrbrd);
	printf("Введите чипсет: ");
	getline(cin, chipset);
	SetMrbrd(name_mrbrd, chipset);
}

void Motherboard::SetMrbrd(string name_mrbrd, string chipset)
{
	if (CheckCor(name_mrbrd, chipset))
	{
		this->name_mrbrd = name_mrbrd;
		this->chipset = chipset;
	}
}