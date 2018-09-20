// maths.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include "stdio.h"
using namespace std;

double dfunction(double x) {
	return 3 * pow(x, 2) - 10 * x;
}
double d2function(double x) {
	return 6*x-10;
}
double function(double x) {
	double y;
	y = pow(x, 3) - 5 * pow(x, 2) + 12;
	return y;
}
void newton(double x0, double x1) {
	double x2, x3, eps;
	eps = 0.001;	
	x2 = x0;
		x3 = x2 - function(x2) / dfunction(x2); 
		while (fabs(x2 - x3) > eps) 
		{
			x2 = x3;
			x3 = x2 - function(x2) / dfunction(x2); 
		}
		cout << "\nRoot = " << x3<<endl; 
		cout << function(x3) << endl;
	
	
}


int main()
{
	double a = -2, b=5,y,i,h;
		
	for (a = -2; a < b; a++) {
		if (a == 0) a++;
		newton(a, b);
	}
	system("pause");
    return 0;
}

