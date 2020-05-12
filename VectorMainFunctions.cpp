#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h> 
#include "VectorHelpFunctions.h"

using namespace std;

// Основные функции, указанные в условии лабораторной

// 1. Функция заполнения текстового файла N целыми случайными числами в диапазоне от -M до M
fstream GenerateFile(string fileName, unsigned N, int M)
{
	fstream file(fileName, ios::out);
	while (!file)
		file.open(InputString("Файла с введенным именем не существует, повторите ввод"), ios::out);

	srand(static_cast<unsigned int>(time(0)));

	auto Rand = [M]()
	{
		if (M == 0)
			return 0;

		int r = rand() % abs(M);
		return rand() % 2 ? r : -r;
	};

	cout << "Выберите способ генерации случайных чисел:" << endl <<
			"1 - Генерация в цикле" << endl <<
			"2 - Генерация с использованием std::generate" << endl;

	switch (InputUnsigned("", 1, 2))
	{
	case 1:
		for (unsigned i = 0; i < N; ++i)
			file << Rand() << " ";
		break;
	case 2:
		vector<int> v(N);
		generate(v.begin(), v.end(), Rand);
		for (const int& i : v)
			file << i << " ";
		break;
	}

	file.close();
	return file;
}

// 2. Функция, получающая файл на вход, и возвращающая контейнер std::vector, заполненный числами из файла
//	  Вызывается из функции FillFromFile
vector<int> ReadFromFile(fstream& file)
{
	vector<int> v;
	int i;

	while (file >> i)
	{
		v.push_back(i);
	}

	return v;
}

// Функция, передающая в функцию ReadFromFile файл
vector<int> FillFromFile(string fileName)
{
	fstream file(fileName, ios::in);
	while (!file)
		file.open(InputString("Файла с введенным именем не существует, повторите ввод"), ios::in);

	return ReadFromFile(file);
}

// 4. Перегруженная функция Modify, принимающая на вход итераторы начала и конца обрабатываемой части контейнера
// itBegin указывает на 1-ый элемент обрабатываемой части,
// itEnd указывает на элемент, за последним элементом обрабатываемой части
// По аналогии с vector<T>.begin() и vector<T>.end()
vector<int> Modify(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd)
{
	int mult = GetMultiplier(v, itBegin, itEnd);

	if (!mult)
		cout << "В заданной части контейнера нет ни одного отрицательного числа" << endl;
	else
	{
		// Сразу переходим к третьему элементу, так как по преобразованию нам нужен каждый третий
		vector<int>::iterator it = itBegin + 2;

		// Проходим по вектору, останавливаясь, 
		//		если на следующем шаге возможен выход итератора за пределы обрабатываемой части
		while (it < itEnd - 2)
		{
			*it *= mult;
			it += 3;
		}
		// Проверяем, не остался ли элемент, который нужно изменить
		if (it != itEnd)
			* it *= mult;
		cout << "Контейнер был успешно преобразован" << endl << endl;
	}

	return v;
}

// 3. Функция Modify, выполняющая преобразование полученного std::vector
vector<int> Modify(vector<int>& v)
{
	return Modify(v, v.begin(), v.end());
}

// 5. Функция, реализующая требуемое преобразование с использованием алгоритма std::transform вместо функции Modify
vector<int> ModifyByTransform(vector<int>& v)
{
	int mult = GetMultiplier(v);

	if (!mult)
		cout << "В заданной части контейнера нет ни одного отрицательного числа" << endl;
	else
	{
		auto MultEveryThird = [mult](int& val)
		{
			static int i = 1;
			if (i++ < 3)
				return val;

			i = 1;
			val *= mult;

			return val;
		};

		transform(v.begin(), v.end(), v.begin(), MultEveryThird);
		cout << "Контейнер был успешно преобразован" << endl << endl;
	}

	return v;
}

// 6. Функция, реализующая требуемое преобразование с использованием алгоритма std::for_each вместо функции Modify
vector<int> ModifyByForEach(vector<int>& v)
{
	int mult = GetMultiplier(v);

	if (!mult)
		cout << "В заданной части контейнера нет ни одного отрицательного числа" << endl;
	else
	{
		auto MultEveryThird = [mult](int& val)
		{
			static int i = 1;
			if (i++ < 3)
				return val;

			i = 1;
			val *= mult;

			return val;
		};

		for_each(v.begin(), v.end(), MultEveryThird);
		cout << "Контейнер был успешно преобразован" << endl << endl;
	}

	return v;
}

// 7.1 Функция, вычисляющая сумму чисел, содержащихся в контейнере
int GetSum(vector<int>& v)
{
	// Вспомогательная структура для подсчета суммы
	struct Sum {
		Sum() { sum = 0; }
		void operator()(int val) { sum += val; }

		int sum;
	};

	Sum s = std::for_each(v.begin(), v.end(), Sum());
	return s.sum;
}

// 7.2 Функция, вычисляющая среднее арифметическое чисел, содержащихся в контейнере
float GetAverage(vector<int>& v)
{
	return GetSum(v) / float(v.size());
}

// 8.1 Функция вывода результата в файл
void VectorToFile(vector<int>& v, string fileName)
{
	fstream file(fileName, ios::out);
	while (!file)
		file.open(InputString("Файла с введенным именем не существует, повторите ввод"), ios::out);
	for (const int& i : v)
		file << i << " ";
}

// 8.2 Функция вывода результата в консоль
void View(vector<int>& v)
{
	cout << "Содержимое контейнера:" << endl;
	for (const int& i : v)
		cout << i << " ";
	cout << endl;
}