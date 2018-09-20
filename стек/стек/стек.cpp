// стек.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "stack.h"
using namespace std;


int main()
{
	Stack *begin = NULL;
	int i, in, n, kod, kod1;
	while (true) {
		cout << "\nAdd Elements - 1. Show Stack - 2. Retrieve element - 3. Delete all - 4. Do sum - 5. Sort - 6. Exit - 0.\n ";
		cin >> kod;
		switch (kod) {
		case 1:
			cout << "Enter a number of elements "; cin >> n;
			cout << "Enter " << n << " elements of stack" << endl;
			for (i = 1; i <= n; i++) {
				cin >> in;
				begin = InStack(begin, in);
			}		
			break;
		case 2:
			if (begin == NULL) {
				cout << "Stack is empty";
				break;
			}
			else
				cout << "Your stack: ";
			View(begin);
			break;
		case 3:
			if (begin == NULL) {
				cout << "Stack is empty" << endl;
				break;
			}
			begin = OutStack(begin);		
			break;
		
		case 4:
			Del(&begin);
			cout << "Memory Free!" << endl;
			break;
		case 5:
			if (begin == NULL) {
				cout << "Stack is empty" << endl;
				break;
			}
			 Sum(begin);
				break;
		case 6:
			if (begin == NULL) {
				cout << "Stack is empty" << endl;
				break;
			}
			cout << "Enter a type of sorting: 0-address, 1-info" << endl;
			cin >> kod1;
			switch (kod1) {
			case 0: 				
				Sort1(&begin);			
				break;
			case 1: Sort2(begin); break;
			}
			break;
		case 0: {
			return 1;
		}
		}
	}
	system("pause");
	return 0;
}

