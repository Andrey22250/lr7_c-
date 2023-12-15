#pragma once
#include <iostream>
#include <vector>
#include "BuildTab.h"

using namespace std;

class BuildCompTab
{
public:
	BuildCompTab() = default;
	BuildCompTab(vector<BuildTab*> components);
	~BuildCompTab() = default;

	void addComp(BuildTab* component);
	void removeComp(string modName);
	void removeLastComp();
	BuildTab* getComp(string modName);
	void sortByCompName();
	void sortByModName();
	void print();
private:
	vector<BuildTab*> components;

	void printHeader();
	void printFooter();
};

