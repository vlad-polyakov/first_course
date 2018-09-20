#include "stdafx.h"
#include <conio.h>
#include <iostream>
#include "stack.h"
using namespace std;

struct Stack 
{
	int info;
	Stack *next;
};


Stack* InStack(Stack *p, int in)
{
	Stack *t = new Stack;
	t->info = in;
	t->next = p;
	return t;
}

void View(Stack *p)
{
	Stack *t = p;
	while (t != NULL) {
		cout << t->info << " ";
		t = t->next;
	}
	cout << endl;
}

Stack* OutStack(Stack* p) {
	Stack *t = p;
	p = p->next;
	delete t;
	return p;
}

void Del(Stack **p) {
	Stack *t;
	while (*p != NULL) {
		t = *p;
		*p = (*p)->next;
		delete t;
	}
}

void Sum(Stack *p) {
	int sh = 0;
	Stack *dop1, *dop2;
	while (p != NULL) {
		if (sh == 1) {
			dop1->next = p->next;
			dop2 = p;
			p = p->next;
			delete dop2;
			sh = 0;
		}
		else {
			dop1 = p;
			sh++;
			p = p->next;
		}
	}
}


void Sort1(Stack **p) {
	Stack *t = NULL, *t1, *r;
	if ((*p)->next->next == NULL) return;
	do {
		for (t1 = *p; t1->next->next != t; t1 = t1->next)
			if (t1->next->info  >  t1->next->next->info) {
				r = t1->next->next;
				t1->next->next = r->next;
				r->next = t1->next;
				t1->next = r;
			}
		t = t1->next;
	} while ((*p)->next->next != t);
}


void Sort2(Stack *p) {
	Stack *t = NULL, *t1;
	int r;
	do {
		for (t1 = p; t1->next != t; t1 = t1->next)
			if (t1->info > t1->next->info) {
				r = t1->info;
				t1->info = t1->next->info;
				t1->next->info = r;
			}
		t = t1;
	} while (p->next != t);
}






