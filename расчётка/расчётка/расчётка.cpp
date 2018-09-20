// расчётка.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "fstream"
using namespace std;
int **a, **b, **b1, **a1, **ca, **cb, n, m, i, j, k, l,kod;
void trans(int **a, int **a1, int m, int n) {
	int  ch = 0,i,j;
	int i1, j1;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			if (a[i][j] == 1) {
				i1 = i;
				for (int g = i + 1; g < n; g++)
				{
					if (a[g][j] == 1) {
						j1 = g;
						a1[i1][j1] = 1;
						a1[j1][i1] = 1;
					}
				}
			}
		}
}
	cout << "Transformated matrix:" << endl;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cout << a1[i][j]<<" ";
		}
		cout << endl;
	}
}
void composition1(){
	int i1, j1,i2,j2,k,l;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (a1[i][j] == 1) {
				k = i;
				i1 = j;
				for (j1 = 0; j1 < n; j1++) {
					if (b1[i1][j1] == 1) {
						l = j1;
						ca[k][l] = 1;
					}
				}
}
		}
}
	cout << "Composition 1:" << endl;
	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++) {
			cout << ca[k][l] << " ";
		}
		cout << endl;
	}
}
void composition2() {
	int i1, j1, i2, j2, k, l;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (b1[i][j] == 1) {
				k = i;
				i1 = j;
				for (j1 = 0; j1 < n; j1++) {
					if (a1[i1][j1] == 1) {
						l = j1;
						cb[k][l] = 1;
						cb[l][k] = 1;
					}
				}
			}
		}
	}
	cout << "Composition 2:" << endl;
	for (k = 0; k < n; k++) {
		for (l = 0; l < n; l++) {
			cout << cb[k][l] << " ";
		}
		cout << endl;
	}
}
void reading_1(string str) {
	int i, j, i1, j1,k,l;
	ifstream in1(str);
	if (in1.is_open())
	{

		int count = 0;
		int temp;

		while (!in1.eof())
		{
			in1 >> temp;
			count++;
		}

		in1.seekg(0, ios::beg);
		in1.clear();

		int count_space = 0;
		char symbol;
		while (!in1.eof())
		{
			in1.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}

		in1.seekg(0, ios::beg);
		in1.clear();

		n = count / (count_space + 1);
		m = count_space + 1;
		a = new int *[n];
		for (i = 0; i < n; i++) 	a[i] = new int[m];
		cout << "Matrix 1:" << endl;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in1 >> a[i][j];
				cout << a[i][j]<<" ";
			}
			cout << endl;
		}
		a1 = new int *[n];
		for (i1 = 0; i1 < n; i1++) 	a1[i1] = new int[n];
		for (int i1 = 0; i1 < n; i1++)
		{
			for (int j1 = 0; j1 < n; j1++)
			{
				a1[i1][j1] = 0;
			}
		}
		trans(a,a1,m,n);	
		ca = new int *[n];
		for (k = 0; k < n; k++) 	ca[k] = new int[n];
		for (k = 0; k < n; k++) {
			for (l = 0; l < n; l++) {
				ca[k][l] = 0;
			}
		}
	}

	in1.close();
}
void reading_2(string str) {
	int i, j, i1, j1, k, l;
	ifstream in1(str);
	if (in1.is_open())
	{

		int count = 0;
		int temp;

		while (!in1.eof())
		{
			in1 >> temp;
			count++;
		}

		in1.seekg(0, ios::beg);
		in1.clear();

		int count_space = 0;
		char symbol;
		while (!in1.eof())
		{
			in1.get(symbol);
			if (symbol == ' ') count_space++;
			if (symbol == '\n') break;
		}

		in1.seekg(0, ios::beg);
		in1.clear();

		n = count / (count_space + 1);
		m = count_space + 1;
		cout << "Matrix 2:" << endl;
		b = new int *[n];
		for (i = 0; i < n; i++) 	b[i] = new int[m];
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				in1 >> b[i][j];
				cout << b[i][j]<<" ";
			}
			cout << endl;
		}
		b1 = new int *[n];
		for (i1 = 0; i1 < n; i1++) 	b1[i1] = new int[n];
		for (int i1 = 0; i1 < n; i1++)
		{
			for (int j1 = 0; j1 < n; j1++)
			{
				b1[i1][j1] = 0;
			}
		}
		trans(b,b1,m,n);
		cb = new int *[n];
		for (k = 0; k < n; k++) 	cb[k] = new int[n];
		for (k = 0; k < n; k++) {
			for (l = 0; l < n; l++) {
				cb[k][l] = 0;
			}
		}
	}

	in1.close();
}
int main(){
	
	while (true) {
		cout << "Choose any test (from 1 to 5), 0-Exit " << endl;
		cin >> kod;
		switch (kod) {
		case 1:
		{		
			reading_1("file1.txt");			
			reading_2("file11.txt");	
			composition1();
			composition2();			
			break;
		}
		case 2:
		{
			reading_1("file2.txt");
			reading_2("file22.txt");
			composition1();
			composition2();
			break;
		}
		case 3:
		{
			reading_1("file3.txt");
			reading_2("file33.txt");
			composition1();
			composition2();
			break;
		}
		case 4:
		{
			reading_1("file4.txt");
			reading_2("file44.txt");
			composition1();
			composition2();
			break;
		}
		case 5:
		{
			reading_1("file5.txt");
			reading_2("file55.txt");
			composition1();
			composition2();
			break;
		}
	    case 0: {
		return 1;
	}
		}
	}	
	delete[]a;
	delete[]b;
	delete[]a1;
	delete[]b1;
	delete[]ca;
	delete[]cb;
system("pause");
    return 0;
}

