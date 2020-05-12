#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>
#include <time.h> 
#include "VectorHelpFunctions.h"

using namespace std;

// �������� �������, ��������� � ������� ������������

// 1. ������� ���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M
fstream GenerateFile(string fileName, unsigned N, int M)
{
	fstream file(fileName, ios::out);
	while (!file)
		file.open(InputString("����� � ��������� ������ �� ����������, ��������� ����"), ios::out);

	srand(static_cast<unsigned int>(time(0)));

	auto Rand = [M]()
	{
		if (M == 0)
			return 0;

		int r = rand() % abs(M);
		return rand() % 2 ? r : -r;
	};

	cout << "�������� ������ ��������� ��������� �����:" << endl <<
			"1 - ��������� � �����" << endl <<
			"2 - ��������� � �������������� std::generate" << endl;

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

// 2. �������, ���������� ���� �� ����, � ������������ ��������� std::vector, ����������� ������� �� �����
//	  ���������� �� ������� FillFromFile
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

// �������, ���������� � ������� ReadFromFile ����
vector<int> FillFromFile(string fileName)
{
	fstream file(fileName, ios::in);
	while (!file)
		file.open(InputString("����� � ��������� ������ �� ����������, ��������� ����"), ios::in);

	return ReadFromFile(file);
}

// 4. ������������� ������� Modify, ����������� �� ���� ��������� ������ � ����� �������������� ����� ����������
// itBegin ��������� �� 1-�� ������� �������������� �����,
// itEnd ��������� �� �������, �� ��������� ��������� �������������� �����
// �� �������� � vector<T>.begin() � vector<T>.end()
vector<int> Modify(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd)
{
	int mult = GetMultiplier(v, itBegin, itEnd);

	if (!mult)
		cout << "� �������� ����� ���������� ��� �� ������ �������������� �����" << endl;
	else
	{
		// ����� ��������� � �������� ��������, ��� ��� �� �������������� ��� ����� ������ ������
		vector<int>::iterator it = itBegin + 2;

		// �������� �� �������, ��������������, 
		//		���� �� ��������� ���� �������� ����� ��������� �� ������� �������������� �����
		while (it < itEnd - 2)
		{
			*it *= mult;
			it += 3;
		}
		// ���������, �� ������� �� �������, ������� ����� ��������
		if (it != itEnd)
			* it *= mult;
		cout << "��������� ��� ������� ������������" << endl << endl;
	}

	return v;
}

// 3. ������� Modify, ����������� �������������� ����������� std::vector
vector<int> Modify(vector<int>& v)
{
	return Modify(v, v.begin(), v.end());
}

// 5. �������, ����������� ��������� �������������� � �������������� ��������� std::transform ������ ������� Modify
vector<int> ModifyByTransform(vector<int>& v)
{
	int mult = GetMultiplier(v);

	if (!mult)
		cout << "� �������� ����� ���������� ��� �� ������ �������������� �����" << endl;
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
		cout << "��������� ��� ������� ������������" << endl << endl;
	}

	return v;
}

// 6. �������, ����������� ��������� �������������� � �������������� ��������� std::for_each ������ ������� Modify
vector<int> ModifyByForEach(vector<int>& v)
{
	int mult = GetMultiplier(v);

	if (!mult)
		cout << "� �������� ����� ���������� ��� �� ������ �������������� �����" << endl;
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
		cout << "��������� ��� ������� ������������" << endl << endl;
	}

	return v;
}

// 7.1 �������, ����������� ����� �����, ������������ � ����������
int GetSum(vector<int>& v)
{
	// ��������������� ��������� ��� �������� �����
	struct Sum {
		Sum() { sum = 0; }
		void operator()(int val) { sum += val; }

		int sum;
	};

	Sum s = std::for_each(v.begin(), v.end(), Sum());
	return s.sum;
}

// 7.2 �������, ����������� ������� �������������� �����, ������������ � ����������
float GetAverage(vector<int>& v)
{
	return GetSum(v) / float(v.size());
}

// 8.1 ������� ������ ���������� � ����
void VectorToFile(vector<int>& v, string fileName)
{
	fstream file(fileName, ios::out);
	while (!file)
		file.open(InputString("����� � ��������� ������ �� ����������, ��������� ����"), ios::out);
	for (const int& i : v)
		file << i << " ";
}

// 8.2 ������� ������ ���������� � �������
void View(vector<int>& v)
{
	cout << "���������� ����������:" << endl;
	for (const int& i : v)
		cout << i << " ";
	cout << endl;
}