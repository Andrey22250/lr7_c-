﻿#pragma once
#include <iostream>
#include <string>
#include "BuildTab.h"

using namespace std;

class CPU : public BuildTab
{
public:
	CPU();
	CPU(string name_cpu);
	CPU(string name_cpu, int frequency, int cores, int treads);
	~CPU();

	void operator=(CPU other);
	//единственное "разумное" применение модификтора friend
	friend CPU& operator++(CPU& cpu);
	bool CheckCor(string name_cpu, int frequency, int cores, int treads) const;

	string GetCompName() const override;
	string GetModName() const;
	int GetFrequency() const;
	int GetCores() const;
	int GetTreads() const;
	void input();
	void SetCpu(string name_cpu, int frequency, int cores, int treads);
private:
	string name_cpu ;
	int frequency;
	int cores, treads;
};

CPU operator+(const CPU& cpu, int addable);
CPU operator++(CPU& cpu, int);
std::ostream& operator << (std::ostream& out, const CPU& cpu);