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
	//создаем итератор, который будет указывать либо на нужный элемент, либо на конец вектора, если элемента не окажется
	auto removable = find_if(this->components.begin(), this->components.end(), [&](BuildTab* component) {
		return component->GetModName() == molName;
		}); //используем лямбда-функцию для поиска конкретной модели

	if (removable != this->components.end()) {
		this->components.erase(removable);
	}
	else {
		throw runtime_error("Данное комплектующее не найдено!");
	}
}

void BuildCompTab::removeLastComp()
{
	if (this->components.size() > 0) {
		this->components.pop_back();
	}
	else {
		throw runtime_error("В таблице нет комплектующих!");
	}
}

BuildTab* BuildCompTab::getComp(string modName)
{
	//используем тот же итератор из removeComp()
	auto removable = find_if(this->components.begin(), this->components.end(), [&](BuildTab* component) {
		return component->GetModName() == modName;
		});

	if (removable != this->components.end()) {
		return *removable;
	}
	else {
		throw runtime_error("Данное комплектующее не найдено!");
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
		<< "- Тип комплектующего -           Название модели           -" << endl
		<< "------------------------------------------------------------" << endl;
}

void BuildCompTab::printFooter()
{
	cout << "-------------------------------------------------------------" << endl;
}