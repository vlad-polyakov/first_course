// очереди.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
using namespace std;
struct Spis {
	int info;
	Spis  *prev, *next;
} *begin, *end, *t;
void Create_firstelement(Spis **b, Spis **e, int in) {
	t = new Spis;
	t->info = in;
	t->next = t->prev = NULL;
	*b = *e = t;
}
void Add_begin( Spis **b, int in) {
	t = new Spis;
	t->info = in;
		t->prev = NULL;
		t->next = *b;
		(*b)->prev = t;
		*b = t;	
}
void Add_end( Spis **e, int in) {
	        t = new Spis;
	        t->info = in;
			t->next = NULL;
			t->prev = *e;
			(*e)->next = t;
			*e = t;
		}
void View_begin( Spis *t) {
	while (t != NULL) {
		cout << t->info << endl;
		t = t->next;
	}
}
void View_end( Spis *t) {
	while (t != NULL) {
		cout << t->info<<endl;
		t = t->prev;
	}
}
void Sum_begin(Spis *t, Spis **end) {
	int sh = 0;
	Spis *d1, *d2, *d3;
	while (t->next != NULL) {
		if (sh == 1) {
				d1->next = t->next;
				d2 = t;
				d3 = t->next;
				d3->prev = d1;
				t = t->next;
				delete d2;
				sh = 0;
		}
		else {
			d1 = t;
			sh++;
			t = t->next;
		}

	}
	if (sh)
	{
		t->prev->next = NULL;
		*end = t->prev;
		delete t;

	}
}
void Sum_end(Spis *t, Spis **begin) {
	int sh = 0;
	Spis *d1, *d2, *d3;
	while (t->prev != NULL) {
		if (sh == 1) {
			d1->prev = t->prev;
			d2 = t;
			d3 = t->prev;
			d3->next = d1;
			t = t->prev;
			delete d2;
			sh = 0;
		}
		else {
			d1 = t;
			sh++;
			t = t->prev;
		}

	}
	if (sh) {
		t->next->prev = NULL;
		*begin = t->next;
		delete t;
	}
}





int main()
{
	Spis *begin = NULL, *end = NULL;
	int i, in, kod, kod1,n, count=0;
	while (true) {
		cout << "\nCreate - 1, Add - 2, View - 3, Do sum - 4, Exit - 0  :  ";
		cin >> kod;
		switch (kod) {
		case 1:
			if (begin != NULL) {
				cout << "You need to clear memory";
				break;
			}
			cout << "Begin Info = ";
			cin >> in;
			Create_firstelement(&begin, &end, in);
			cout << "Create Begin = " << begin->info << endl;
			count++;
			break;
		case 2:		
			cout << "Choose one variant: 0-Add End, 1-Add Begin ";
			cin >> kod1;
			switch (kod1) {
			case 0:		
				cout << "Enter an amount of elements ";
				cin >> n;
				cout << "Enter elements ";				
				for (i = 0; i < n; i++) {
					cin >> in;
					Add_end(&end, in);
					count++;
				}
					t = end;
					cout << "You have added element to the end " << endl;
				break;
			case 1:		
				cout << "Enter an amount of elements ";
				cin >> n;
				cout << "Enter elements ";				
				for (i = 0; i < n; i++) {
					cin >> in;
					Add_begin(&begin, in);
				}
					t = begin;
					cout << "You have added element to the begin " << endl;
				break;
			}
			
				break;
			case 3:
				if (!begin) {
					cout << "List is empty" << endl;
					break;
				}
				cout << "View End-0,View Begin-1:";
				cin >> kod1;
				switch (kod1) {
				case 0: 	t = end;
					View_end(t);
					break;
				case 1: t = begin;
					View_begin(t);
					break;
				}
				break;
			case 4:
				if (!begin) {
					cout << "List is empty" << endl;
					break;
				}
				cout << "Do sum from End-0,Do sum from Begin-1:";
				cin >> kod1;
				switch (kod1) {
				case 0: 	t = end;
					Sum_end(t,&begin);
					break;
				case 1: t = begin;
					Sum_begin(t, &end);
					break;
				}
				break;
			case 0: {
				return 1;
			}
			}
		}
	
    return 0;
}

