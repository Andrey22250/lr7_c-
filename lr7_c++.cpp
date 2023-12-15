#include <iostream>
#include <windows.h>
#include "Build.h"
#include "BuildCompTab.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	BuildCompTab table = BuildCompTab();
	table.addComp(new GPU("RTX 2070"));
	table.addComp(new CPU("Intel i5 11400f"));
	table.addComp(new CPU("Intel i7 11700f"));
	table.print();
	cout << endl;

	table.sortByCompName();
	table.print();
	cout << endl;

	table.removeComp("Intel i5 11400f");
	table.sortByModName();
	table.print();
	cout << endl;

	table.removeLastComp();
	table.print();

	BuildTab* searchbleComponent;
	try
	{
		searchbleComponent = table.getComp("Intel i7 11700f");
	}
	catch (const exception&)
	{
		cout << "Комплектующее не найдено!" << endl;
	}
	searchbleComponent = table.getComp("Intel i7 11700f");
	cout << "Найденный компонент: " << searchbleComponent->GetModName() << endl;

	return 0;
}