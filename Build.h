#pragma once
#include <iostream>
#include <string>
#include "PC.h"
#include "Status.h"
#include "HDD.h"
#include "SSD.h"

using namespace std;

template <typename T>
concept HasIO = requires(ostream & os, istream & is, T & t) {
	{ os << t } -> same_as<ostream&>;
	{ is >> t } -> same_as<istream&>;
}; //требует перегрузку операторов ввода-вывода для типа Т

template <HasIO T = string> //по умолчанию дополнительная информация - строка

class Build
{
public:
	Build(string client);
	Build(PC pc, string client, Status status, T additionalInfo);
	~Build() = default;

	bool CheckCor(PC pc, string client, Status status);

	template <HasIO T>
	friend ostream& operator << (ostream& out, Build<T>& build);
	static int GetNumBuild();
	PC GetPC();
	string GetClient();
	Status GetStatus();
	T getAdditionalInfo() const;
	void input_build();
	void out_build();
	void ChangeStatus(Status newstatus);
	void SetPC(PC pc);
	void SetBuild(PC pc, string client, Status status);
private:
	static inline int numberBuild{};
	int number;
	PC pc;
	string client;
	Status status;
	T additionalInfo{};
};

template <HasIO T>
ostream& operator << (ostream& out, Build<T>& build) {
	out << build.GetClient() << "\t" << build.getAdditionalInfo();
	return out;
}

template <HasIO T>
Build<T>::Build(string client)
{
	this->number = ++numberBuild;
	this->client = client;
}

template <HasIO T>
Build<T>::Build(PC pc, string client, Status status, T additionalInfo) : Build(client) {
	this->status = status;
	this->additionalInfo = additionalInfo;
	this->pc = pc;
}

template <HasIO T>
int Build<T>::GetNumBuild() {
	return numberBuild;
}

template <HasIO T>
PC Build<T>::GetPC()
{
	return pc;
}

template <HasIO T>
Status Build<T>::GetStatus() {
	return status;
}

template <HasIO T>
string Build<T>::GetClient() {
	return client;
}

template <HasIO T>
T Build<T>::getAdditionalInfo() const {
	return additionalInfo;
}

template <HasIO T>
void Build<T>::input_build() {
	PC pc;
	Status status;
	T additionalInfo = T();
	numberBuild++;

	cout << "Номер заказа: " << numberBuild;
	cout << "Введите статус заказа, где\n0 - Заказ создан\n1 - Заказ в работе\n2 - Заказ выполнен\nВаш выбор: ";
	cin >> status;
	cout << "\tВвод параметров ноутбука\n";
	pc.input_pc();
	cout << "\tВвод дополнительной информации\n";
	cin >> additionalInfo;

	this->number = numberBuild;
	this->pc = pc;
	this->status = status;
	this->additionalInfo = additionalInfo;
}

template <HasIO T>
void Build<T>::ChangeStatus(Status newstatus) {
	this->status = newstatus;
	cout << "Состояние заказа успешно изменено!\n";
}

template <HasIO T>
void Build<T>::SetPC(PC pc) {
	this->pc = pc;
}