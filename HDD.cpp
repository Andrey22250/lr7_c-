#include "HDD.h"

void HDD::operator=(HDD other) {
	DataStor::operator=(other);
	this->speed = other.speed;
}

std::ostream& operator << (std::ostream& out, const HDD& hdd) {
	out << hdd.getCompName();
	return out;
}

HDD::HDD(int speed, string type, int vol)
{
	SetHDD(speed);
}

std::string HDD::getCompName() const {
	return "HDD";
}

int HDD::getSpeed() const {
	return speed;
}

void HDD::input() {
	DataStor::input();
	int speed;

	std::cout << "Введите cкорость диска: ";
	std::cin >> speed;
	while (getchar() != '\n');

	SetHDD(speed);
}

void HDD::SetHDD(int speed) {
	if (speed > 0) {
		this->speed = speed;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}