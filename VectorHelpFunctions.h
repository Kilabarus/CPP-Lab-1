#pragma once

using namespace std;

// ��������������� �������

// ���� ������������ ������ � ������� [min, max] � ������� ��������� 
unsigned InputUnsigned(string msg, unsigned min = 0, unsigned max = UINT_MAX);

// ���� ������ � ������� ��������� 
string InputString(string msg);

// ��������� ��������� ����� ������� � ���������� ������������� ����� �� ���� �������
int GetMultiplier(vector<int>& v);

// ��������� ��������� ����� ������� � ���������� ������������� ����� � �������� ����� �������
// itBegin ��������� �� 1-�� ������� �������������� �����,
// itEnd ��������� �� �������, �� ��������� ��������� �������������� �����
// �� �������� � vector<T>.begin() � vector<T>.end()
int GetMultiplier(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd);