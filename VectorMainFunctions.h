#pragma once
#include <vector>
#include <fstream>

using namespace std;

// Основные функции, указанные в условии лабораторной

// 1. Функция заполнения текстового файла N целыми случайными числами в диапазоне от -M до M
fstream GenerateFile(string fileName, unsigned N, int M);

// 2. Функция, получающая файл на вход, и возвращающая контейнер std::vector, заполненный числами из файла
vector<int> ReadFromFile(fstream& file);

// Функция, передающая в функцию ReadFromFile файл
vector<int> FillFromFile(string fileName);

// 3. Функция Modify, выполняющая преобразование полученного std::vector
vector<int> Modify(vector<int>& v);

// 4. Перегруженная функция Modify, принимающая на вход итераторы начала и конца обрабатываемой части контейнера
// itBegin указывает на 1-ый элемент обрабатываемой части,
// itEnd указывает на элемент, за последним элементом обрабатываемой части
// По аналогии с vector<T>.begin() и vector<T>.end()
vector<int> Modify(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd);

// 5. Функция, реализующая требуемое преобразование с использованием алгоритма std::transform вместо функции Modify
vector<int> ModifyByTransform(vector<int>& v);

// 6. Функция, реализующая требуемое преобразование с использованием алгоритма std::for_each вместо функции Modify
vector<int> ModifyByForEach(vector<int>& v);

// 7.1 Функция, вычисляющая сумму чисел, содержащихся в контейнере
int GetSum(vector<int>& v);

// 7.2 Функция, вычисляющая среднее арифметическое чисел, содержащихся в контейнере
float GetAverage(vector<int>& v);

// 8.1 Функция вывода результата в файл
void VectorToFile(vector<int>& v, string fileName);

// 8.2 Функция вывода результата в консоль
void View(vector<int>& v);

