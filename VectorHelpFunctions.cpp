#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

// ��������������� �������

// ���� ������������ ������ � ������� [min, max] � ������� ��������� 
unsigned InputUnsigned(string msg, unsigned min = 0, unsigned max = UINT_MAX)
{
	unsigned u;
	if (!msg.empty())
		cout << msg << endl;
	cin >> u;
	while (u < min || u > max)
	{
		cout << "������� �������� ��������, ��������� ����: " << endl;
		cin >> u;
	}
	return u;
}

// ���� ������ � ������� ���������
string InputString(string msg)
{
	string s;
	if (!msg.empty())
		cout << msg << endl;
	cin >> s;
	return s;
}

// �������� ��� ������ �������������� �����
bool LessThanZero(int val)
{
	return val < 0;
}

// ��������� ��������� ����� ������� � ���������� ������������� ����� �� ���� �������
int GetMultiplier(vector<int>& v)
{
	// ����� ������� �������������� ����� ����� ��������
	vector<int>::iterator it = find_if(v.begin(), v.end(), LessThanZero);
	// ���� �� ����� �� ������ �������������� �����, ���������� ����
	// � ��������� ������ ���� ��������� ������������� ����� � ���������� �� ��������� ����� 
	return it == v.end() ? 0 : 2 * (*it + *(find_if(v.rbegin(), v.rend(), LessThanZero)));
}

// ��������� ��������� ����� ������� � ���������� ������������� ����� � �������� ����� �������
// itBegin ��������� �� 1-�� ������� �������������� �����,
// itEnd ��������� �� �������, �� ��������� ��������� �������������� �����
// �� �������� � vector<T>.begin() � vector<T>.end()
int GetMultiplier(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd)
{
	// ����� ������� �������������� ����� ����� ��������
	vector<int>::iterator itFirst = find_if(itBegin, itEnd, LessThanZero);

	// ���� �� ����� �� ������ �������������� �����, ���������� ����
	if (itFirst == itEnd)
		return 0;

	// ����� ���� ��������� ������������� ����� 

	// ���� itFirst �������� ��������, ������ �� ��������� �� ������ ������������� ����� � �������������� �����
	// reverse_iterator �� make_reverse_iterator(itEnd) ����� ��������� �� ��������� ������� �� �������������� �����
	// reverse_iterator �� make_reverse_iterator(itFirst + 1) ����� �� �������� ��������� �� ������ �������������
	// ����� ������� ����� reverse_iterator'� �� ������� � ����� �������������� ����� �� ������� ���������������� �����,
	//		�� ���� � ����� ������ itLast ����� ��������� �� ������������� �������

	vector<int>::reverse_iterator itLast = find_if(make_reverse_iterator(itEnd),
		make_reverse_iterator(itFirst + 1), LessThanZero);
	return 2 * (*itFirst + *itLast);
}