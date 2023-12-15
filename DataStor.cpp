#include "DataStor.h"

void DataStor::operator=(DataStor* other) {
	this->type = other->type;
	this->vol = other->vol;
}

DataStor::DataStor(string type, int vol)
{
	if (sizeof(type) > 0 && vol > 0)
	{
		this->type = type;
		this->vol = vol;
	}
}

int DataStor::GetVol()
{
	return vol;
}

void DataStor::input()
{
	string type;
	int vol;

	printf("\nВвод параметров диска\n");
	printf("\nВведите тип диска: ");
	getline(cin, type);
	std::cout << "Введите вместимость (в ГБ): ";
	std::cin >> vol;
}