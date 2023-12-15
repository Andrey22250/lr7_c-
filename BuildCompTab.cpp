#include "BuildCompTab.h"
#include <algorithm>
#include <format>

BuildCompTab::BuildCompTab(vector<BuildTab*> components)
{
	this->components = components;
}

void BuildCompTab::addComp(BuildTab* component)
{
	components.push_back(component);
}

void BuildCompTab::removeComp(string molName)
{
	//������� ��������, ������� ����� ��������� ���� �� ������ �������, ���� �� ����� �������, ���� �������� �� ��������
	auto removable = find_if(this->components.begin(), this->components.end(), [&](BuildTab* component) {
		return component->GetModName() == molName;
		}); //���������� ������-������� ��� ������ ���������� ������

	if (removable != this->components.end()) {
		this->components.erase(removable);
	}
	else {
		throw runtime_error("������ ������������� �� �������!");
	}
}

void BuildCompTab::removeLastComp()
{
	if (this->components.size() > 0) {
		this->components.pop_back();
	}
	else {
		throw runtime_error("� ������� ��� �������������!");
	}
}

BuildTab* BuildCompTab::getComp(string modName)
{
	//���������� ��� �� �������� �� removeComp()
	auto removable = find_if(this->components.begin(), this->components.end(), [&](BuildTab* component) {
		return component->GetModName() == modName;
		});

	if (removable != this->components.end()) {
		return *removable;
	}
	else {
		throw runtime_error("������ ������������� �� �������!");
	}
}

void BuildCompTab::sortByCompName()
{
	std::sort(this->components.begin(), this->components.end(), [&](BuildTab* first, BuildTab* second) {
		return first->GetCompName() < second->GetCompName();
		});
}

void BuildCompTab::sortByModName()
{
	std::sort(this->components.begin(), this->components.end(), [&](BuildTab* first, BuildTab* second) {
		return first->GetModName() < second->GetModName();
		});
}

void BuildCompTab::print()
{
	printHeader();
	for (auto component : this->components) {
		string res = format("*{:^20s}*{:^37s}*", component->GetCompName(), component->GetModName());
		cout << res << endl;
	}
	printFooter();
}

void BuildCompTab::printHeader()
{
	cout << "------------------------------------------------------------" << endl
		<< "- ��� �������������� -           �������� ������           -" << endl
		<< "------------------------------------------------------------" << endl;
}

void BuildCompTab::printFooter()
{
	cout << "-------------------------------------------------------------" << endl;
}