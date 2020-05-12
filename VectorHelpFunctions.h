#pragma once

using namespace std;

// Вспомогательные функции

// Ввод беззнакового целого в отрезке [min, max] с выводом сообщения 
unsigned InputUnsigned(string msg, unsigned min = 0, unsigned max = UINT_MAX);

// Ввод строки с выводом сообщения 
string InputString(string msg);

// Получение удвоенной суммы первого и последнего отрицательных чисел во всем векторе
int GetMultiplier(vector<int>& v);

// Получение удвоенной суммы первого и последнего отрицательных чисел в заданной части вектора
// itBegin указывает на 1-ый элемент обрабатываемой части,
// itEnd указывает на элемент, за последним элементом обрабатываемой части
// По аналогии с vector<T>.begin() и vector<T>.end()
int GetMultiplier(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd);