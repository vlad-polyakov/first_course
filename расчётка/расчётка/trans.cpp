#include "stdafx.h"
#include "iostream"
#include "fstream"
#include "trans.h"


//void trans(int **a, int **a1, int m, int n) {
//	int i, j, i1,j1, ch=0;
//	for (i = 0; i < n; i++) {
//		for (j = 0; j < n; j++) {
//			a1[i][j] = 0;
//		}
//	}
//	for(j = 0; j < m; j++){
//	for (i = 0; i < n; i++) {
//			if (a[i][j] == 1) {
//				ch++;
//				if (ch = 1) i1 = i;
//				if (ch = 2) {
//					j1 = i;
//					a1[i1][j1] = 1;
//					a1[j1][i1] = 1;
//					break;
//				}
//			}
//		}
//		}	
//	}
void trans(int **a, int **a1, int m, int n) {
	int i, j, i1, j1, ch = 0;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			a1[i][j] = 0;
		}
	}
	for (j = 0; j < m; j++) {
	
		for (i = 0; i < n; i++) {
			if (a[i][j] == 1) {
				ch++;
				if (ch = 1) i1 = i;
				if (ch = 2) {
					j1 = i;
					a1[i1][j1] = 1;
					a1[j1][i1] = 1;
					break;
				}
			}
		}
	}
}


		
			
