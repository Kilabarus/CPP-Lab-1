#include <iostream>
#include <vector>
#include <clocale>
#include "VectorMainFunctions.h"
#include "VectorHelpFunctions.h"

/*

Лабораторная А7:
	Контейнер - std::vector
	Преобразование - Умножить каждое третье число на удвоенную сумму первого и последнего отрицательных чисел

Данильченко Роман, 9 гр.

*/

using namespace std;

vector<int> ChooseConversion(vector<int>& v)
{
	// Проверка на целесообразность преобразования
	if (v.size() < 3)
	{
		cout << "Контейнер содержит недостаточно элементов для преобразования";
		return v;
	}

	cout << endl;
	cout << "Выберите метод преобразования:" << endl <<
			"1 - Преобразование всего контейнера через функцию Modify" << endl <<
			"2 - Преобразование части контейнера через функцию Modify" << endl <<
			"3 - Преобразование всего контейнера через std::transform" << endl <<
			"4 - Преобразование всего контейнера через std::for_each"  << endl;

	switch (InputUnsigned("", 1, 4))
	{
	case 1:
		return Modify(v);
	case 2:
	{
		unsigned i = InputUnsigned("Введите индекс, соответствующий началу преображаемой части контейнера:", 0, v.size() - 1);
		unsigned j = InputUnsigned("Введите индекс, соответствующий концу преображаемой части контейнера:" , 0, v.size() - 1);

		while (j - i < 2)
		{
			i = InputUnsigned("Введенная пара значений задает слишком малую часть контейнера для преобразование, повторите ввод:\nВведите индекс, соответствующий началу преображаемой части контейнера:", 0, v.size() - 1);
			j = InputUnsigned("Введите индекс, соответствующий концу преображаемой части контейнера:", 0, v.size() - 1);
		}

		vector<int>::iterator iti = v.begin();
		vector<int>::iterator itj = iti;

		// Смещение итераторов
		advance(iti, i);
		advance(itj, j + 1);

		return Modify(v, iti, itj);
	}		
	case 3:
		return ModifyByTransform(v);
	case 4:
		return ModifyByForEach(v);
	}
}

int MenuOptions(bool notEmpty)
{
	cout << "Выберите действие:" << endl <<
			"1 - Создать файл со случайными числами" << endl <<
			"2 - Cчитать числа из файла в контейнер vector" << endl;
	if (notEmpty)
	cout << "3 - Выполнить преобразование:" << endl <<
				"\tУмножить каждое третье число на удвоенную сумму первого и последнего отрицательных чисел" << endl <<
			"4 - Вывести сумму чисел в контейнере" << endl <<
			"5 - Вывести среднее арифметическое чисел в контейнере" << endl <<
			"6 - Вывести содержимое контейнера в консоль" << endl <<
			"7 - Вывести содержимое контейнера в файл" << endl <<
			"8 - Выйти из программы" << endl;
			
	return InputUnsigned("", 1, 2 + notEmpty * 6);
}

int main()
{
	setlocale(LC_ALL, "Russian");

	vector<int> v;
	
	while (true)
		switch (MenuOptions(v.size() != 0))
		{
		case 1:
		{
			string fileName = InputString("Введите название файла:");
			unsigned N = InputUnsigned("Введите кол-во гененрируемых чисел:");
			unsigned M = InputUnsigned("Введите ограничение для диапазона");
			GenerateFile(fileName, N, M);
			cout << "Файл \"" << fileName << "\" был успешно создан" << endl << endl;
			break;
		}
		case 2:
			v = FillFromFile(InputString("Введите название файла:"));
			cout << "Контейнер был успешно заполнен из файла" << endl;
			View(v);
			cout << endl;
			break;
		case 3:
			ChooseConversion(v);			
			break;
		case 4:
			cout << "Сумма чисел в контейнере: " << GetSum(v) << endl << endl;
			break;
		case 5:
			cout << "Среднее арифметическое чисел в контейнере: " << GetAverage(v) << endl << endl;
			break;
		case 6:
			View(v);
			cout << endl;
			break;
		case 7:
			VectorToFile(v, InputString("Введите название файла:"));
			cout << "Файл с содержимым контейнера был успешно создан" << endl << endl;
			break;
		case 8:
			exit(0);
		}
}