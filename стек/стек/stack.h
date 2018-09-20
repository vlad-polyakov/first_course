#pragma once
#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
struct Stack;
Stack* InStack(Stack *p, int in);
void View(Stack *p);
Stack* OutStack(Stack* p);
void Del(Stack **p);
void Sum(Stack *p);
void Sort1(Stack **p);
void Sort2(Stack *p);
#endif