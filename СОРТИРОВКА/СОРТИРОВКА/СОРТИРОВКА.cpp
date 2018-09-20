// СОРТИРОВКА.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <conio.h>
#include <string>
#include <iomanip>
#include <fstream>
#include "cstdlib"

using namespace std;

struct student
{
	string Name;
	string Group;
	int Num1, Num2, Num3, Num4;
	double Sred;

};

student *Info;
student *TempInfo;
int Quantity = 0;
ofstream file;
ifstream files;

void AddStud();
void ShowStud();
void WritetoFile();
void ReadingFile();
void Sort();
void QuickSort(int left, int right);
void Task();
void Find();

int main()
{
	setlocale(LC_ALL, "rus");
	ReadingFile();
	bool Cycle = true;
	int What;
	while (Cycle)
	{
		cout << " 1-Добавить студента \n 2-Посмотреть \n 3-Сортировка1 \n 4-Сортировка2 \n 5-Задание \n 6-Поиск \n 7-Выход \n";
		cin >> What;
		switch (What)
		{
		case 1:
			AddStud();
			break;
		case 2:
			ShowStud();
			break;
		case 3:
			Sort();
			break;
		case 4:
			QuickSort(0, Quantity - 1);
			break;
		case 5:
			Task();
			break;
		case 6:
			Find();
			break;
		case 7:
			Cycle = false;
			break;
		default:
			cout << "Попробуйте еще раз" << endl;
			break;
		}
	}
}

void Find()
{
	int num = -56;
	string str;
	cout << "Введите ФИО" << endl;
	cin >> str;
	for (int i = 0; i<Quantity; i++)
		if (str == Info[i].Name)
			num = i;
	if (num == -56)
		cout << "Ничего не найдено" << endl;
	else
		cout << setw(10) << Info[num].Name << setw(10) << Info[num].Group << setw(15) << Info[num].Num1 << setw(10) << Info[num].Num2 << setw(10) << Info[num].Num3 << setw(10) << Info[num].Num4 << setw(15) << Info[num].Sred << endl;
}

void Task()
{
	Sort();
	double Sr = 0;
	for (int i = 0; i<Quantity; i++)
	{
		Sr += Info[i].Sred;
	}
	Sr = Sr / Quantity;
	for (int i = Quantity - 1; i>-1; i--)
	{
		if (Info[i].Sred>Sr)
			cout << setw(10) << Info[i].Name << setw(10) << Info[i].Group << setw(15) << Info[i].Num1 << setw(10) << Info[i].Num2 << setw(10) << Info[i].Num3 << setw(10) << Info[i].Num4 << setw(15) << Info[i].Sred << endl;
	}
}

void QuickSort(int left, int right)
{
	int i = left, j = right;
	int tmp;
	double pivot = Info[(left + right) / 2].Sred;
	while (i <= j) {
		while (Info[i].Sred < pivot)
			i++;
		while (Info[j].Sred > pivot)
			j--;
		if (i <= j) {
			swap(Info[i], Info[j]);
			i++;
			j--;
		}
	}
	if (left < j)
		QuickSort(left, j);
	if (i < right)
		QuickSort(i, right);

}

void Sort()
{
	for (int i = 1; i<Quantity; i++)
		for (int j = i; j>0 && Info[j - 1].Sred >= Info[j].Sred; j--)
			swap(Info[j - 1], Info[j]);
}

void AddStud()
{
	TempInfo = new student[Quantity];
	for (int i = 0; i<Quantity; i++)
	{
		TempInfo[i].Name = Info[i].Name;
		TempInfo[i].Num1 = Info[i].Num1;
		TempInfo[i].Num2 = Info[i].Num2;
		TempInfo[i].Num3 = Info[i].Num3;
		TempInfo[i].Num4 = Info[i].Num4;
		TempInfo[i].Sred = Info[i].Sred;
		TempInfo[i].Group = Info[i].Group;
	}
	Info = new student[Quantity + 1];
	for (int i = 0; i<Quantity; i++)
	{
		Info[i].Name = TempInfo[i].Name;
		Info[i].Num1 = TempInfo[i].Num1;
		Info[i].Num2 = TempInfo[i].Num2;
		Info[i].Num3 = TempInfo[i].Num3;
		Info[i].Num4 = TempInfo[i].Num4;
		Info[i].Sred = TempInfo[i].Sred;
		Info[i].Group = TempInfo[i].Group;
	}
	delete[] TempInfo;
	cout << "ФИО" << endl;
	cin >> Info[Quantity].Name;
	cout << "Группа" << endl;
	cin >> Info[Quantity].Group;
	cout << "1-ая оценка" << endl;
	cin >> Info[Quantity].Num1;
	cout << "2-ая оценка" << endl;
	cin >> Info[Quantity].Num2;
	cout << "3-ая оценка" << endl;
	cin >> Info[Quantity].Num3;
	cout << "4-ая оценка" << endl;
	cin >> Info[Quantity].Num4;
	Info[Quantity].Sred = ((double)Info[Quantity].Num1 + (double)Info[Quantity].Num2 + (double)Info[Quantity].Num3 + (double)Info[Quantity].Num4) / 4;
	Quantity++;
	WritetoFile();
}

void ShowStud()
{
	cout << setw(10) << "ФИО" << setw(10) << "Группа" << setw(15) << "1-ая оценка" << setw(10) << "2-ая" << setw(10) << "3-ая" << setw(10) << "4-ая" << setw(15) << "Средний балл" << endl;
	for (int i = 0; i<Quantity; i++)
		cout << setw(10) << Info[i].Name << setw(10) << Info[i].Group << setw(15) << Info[i].Num1 << setw(10) << Info[i].Num2 << setw(10) << Info[i].Num3 << setw(10) << Info[i].Num4 << setw(15) << Info[i].Sred << endl;
}

void WritetoFile()
{
	file.open("InfoBus.txt", ios_base::trunc);
	for (int i = 0; i < Quantity; i++)
	{
		file << " " << Info[i].Name << ";" << Info[i].Num1 << ";" << Info[i].Num2 << ";" << Info[i].Num3 << ";" << Info[i].Num4 << ";" << Info[i].Sred << ";" << Info[i].Group << ";";
	}
	file.close();
}

void ReadingFile()
{
	int DopNumber = -1, Shetchik = 0, LengthStr, Index, IndexStart, IndexEnd;
	string str, st;
	Quantity = 0;
	files.open("InfoBus.txt", ios::in);
	getline(files, str);
	files.close();
	LengthStr = str.length();
	for (int i = 0; i < LengthStr; i++)
	{
		if (str[i] == ' ')
			Quantity++;
	}
	Info = new student[Quantity];
	for (int i = 0; i < LengthStr; i++)
	{
		if (str[i] == ' ')
		{
			DopNumber++;
			Shetchik = 0;
			IndexStart = i;
		}
		if (str[i] == ';')
		{
			if (Shetchik != 0)
			{
				Index = IndexEnd;
			}
			IndexEnd = i;
			if (Shetchik == 0)
			{
				Info[DopNumber].Name = str.substr(IndexStart + 1, IndexEnd - IndexStart - 1);
				Shetchik++;
			}
			else
			{
				if (Shetchik == 1)
				{
					Info[DopNumber].Num1 = atoi(str.substr(Index + 1, IndexEnd - Index - 1).c_str());
					Shetchik++;
				}
				else
				{
					if (Shetchik == 2)
					{
						Info[DopNumber].Num2 = atoi(str.substr(Index + 1, IndexEnd - Index - 1).c_str());
						Shetchik++;
					}
					else
					{
						if (Shetchik == 3)
						{
							Info[DopNumber].Num3 = atoi(str.substr(Index + 1, IndexEnd - Index - 1).c_str());
							Shetchik++;
						}
						else
						{
							if (Shetchik == 4)
							{
								Info[DopNumber].Num4 = atoi(str.substr(Index + 1, IndexEnd - Index - 1).c_str());
								Shetchik++;
							}
							else
							{
								if (Shetchik == 5)
								{
									st = str.substr(Index + 1, IndexEnd - Index - 1);
									for (int j = 0; j<st.length(); j++)
										if (st[j] == '.')
										{
											st[j] = ',';
										}
									Info[DopNumber].Sred = atof(st.c_str());
									Shetchik++;
								}
								else
								{
									if (Shetchik == 6)
									{
										Info[DopNumber].Group = str.substr(Index + 1, IndexEnd - Index - 1);
										Shetchik++;
									}
								}
							}
						}
					}
				}
			}
		}
	}
}


