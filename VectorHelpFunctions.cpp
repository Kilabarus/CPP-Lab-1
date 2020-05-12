#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// ¬спомогательные функции

// ¬вод беззнакового целого в отрезке [min, max] с выводом сообщени€ 
unsigned InputUnsigned(string msg, unsigned min = 0, unsigned max = UINT_MAX)
{
	unsigned u;
	if (!msg.empty())
		cout << msg << endl;
	cin >> u;
	while (u < min || u > max)
	{
		cout << "¬ведено неверное значение, повторите ввод: " << endl;
		cin >> u;
	}
	return u;
}

// ¬вод строки с выводом сообщени€
string InputString(string msg)
{
	string s;
	if (!msg.empty())
		cout << msg << endl;
	cin >> s;
	return s;
}

// ѕредикат дл€ поиска отрицательного числа
bool LessThanZero(int val)
{
	return val < 0;
}

// ѕолучение удвоенной суммы первого и последнего отрицательных чисел во всем векторе
int GetMultiplier(vector<int>& v)
{
	// ѕоиск первого отрицательного числа через предикат
	vector<int>::iterator it = find_if(v.begin(), v.end(), LessThanZero);
	// ≈сли не нашли ни одного отрицательного числа, возвращаем ноль
	// ¬ противном случае ищем последнее отрицательное число и возвращаем их удвоенную сумму 
	return it == v.end() ? 0 : 2 * (*it + *(find_if(v.rbegin(), v.rend(), LessThanZero)));
}

// ѕолучение удвоенной суммы первого и последнего отрицательных чисел в заданной части вектора
// itBegin указывает на 1-ый элемент обрабатываемой части,
// itEnd указывает на элемент, за последним элементом обрабатываемой части
// ѕо аналогии с vector<T>.begin() и vector<T>.end()
int GetMultiplier(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd)
{
	// ѕоиск первого отрицательного числа через предикат
	vector<int>::iterator itFirst = find_if(itBegin, itEnd, LessThanZero);

	// ≈сли не нашли ни одного отрицательного числа, возвращаем ноль
	if (itFirst == itEnd)
		return 0;

	// »наче ищем последнее отрицательное число 

	// ≈сли itFirst проходит проверку, значит он указывает на первое отрицательное число в обрабатываемой части
	// reverse_iterator от make_reverse_iterator(itEnd) будет указывать на последний элемент из обрабатываемой части
	// reverse_iterator от make_reverse_iterator(itFirst + 1) будет по прежнему указывать на первое отрицательное
	// “аким образом через reverse_iterator'ы мы пройдем с конца обрабатываемой части до первого неотрицательного числа,
	//		то есть в любом случае itLast будет указывать на отрицательный элемент

	vector<int>::reverse_iterator itLast = find_if(make_reverse_iterator(itEnd),
		make_reverse_iterator(itFirst + 1), LessThanZero);
	return 2 * (*itFirst + *itLast);
}