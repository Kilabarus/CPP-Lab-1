#pragma once
#include <vector>
#include <fstream>

using namespace std;

// �������� �������, ��������� � ������� ������������

// 1. ������� ���������� ���������� ����� N ������ ���������� ������� � ��������� �� -M �� M
fstream GenerateFile(string fileName, unsigned N, int M);

// 2. �������, ���������� ���� �� ����, � ������������ ��������� std::vector, ����������� ������� �� �����
vector<int> ReadFromFile(fstream& file);

// �������, ���������� � ������� ReadFromFile ����
vector<int> FillFromFile(string fileName);

// 3. ������� Modify, ����������� �������������� ����������� std::vector
vector<int> Modify(vector<int>& v);

// 4. ������������� ������� Modify, ����������� �� ���� ��������� ������ � ����� �������������� ����� ����������
// itBegin ��������� �� 1-�� ������� �������������� �����,
// itEnd ��������� �� �������, �� ��������� ��������� �������������� �����
// �� �������� � vector<T>.begin() � vector<T>.end()
vector<int> Modify(vector<int>& v, vector<int>::iterator itBegin, vector<int>::iterator itEnd);

// 5. �������, ����������� ��������� �������������� � �������������� ��������� std::transform ������ ������� Modify
vector<int> ModifyByTransform(vector<int>& v);

// 6. �������, ����������� ��������� �������������� � �������������� ��������� std::for_each ������ ������� Modify
vector<int> ModifyByForEach(vector<int>& v);

// 7.1 �������, ����������� ����� �����, ������������ � ����������
int GetSum(vector<int>& v);

// 7.2 �������, ����������� ������� �������������� �����, ������������ � ����������
float GetAverage(vector<int>& v);

// 8.1 ������� ������ ���������� � ����
void VectorToFile(vector<int>& v, string fileName);

// 8.2 ������� ������ ���������� � �������
void View(vector<int>& v);

