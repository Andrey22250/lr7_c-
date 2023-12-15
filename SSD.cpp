#include "SSD.h"

void SSD::operator=(SSD other) {
	DataStor::operator=(other);
	this->speed = other.speed;
	this->type_ssd = type_ssd;
}

ostream& operator << (ostream& out, const SSD& ssd) {
	out << ssd.getSpeed();
	return out;
}

SSD::SSD(int speed, string type_ssd, string type, int vol)
{
	SetSSD(speed, type_ssd);
}

std::string SSD::getCompName() const {
	return "SSD";
}

int SSD::getSpeed() const {
	return speed;
}

void SSD::input() {
	DataStor::input();
	int speed;
	string type_ssd;

	cout << "Введите cкорость диска: ";
	cin >> speed;
	cout << "Введите формат диска: ";
	cin >> type_ssd;

	SetSSD(speed, type_ssd);
}

void SSD::SetSSD(int speed, string type_ssd) {
	if (speed > 0 && sizeof(type_ssd)) {
		this->speed = speed;
		this->type_ssd = type_ssd;
	}
	else throw std::invalid_argument("Некорректный формат данных!");
}