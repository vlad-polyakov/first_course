// деревья.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
using namespace std;

struct tree
{
	int inf;
	tree *left;
	tree *right;
} *root;

tree *list(int i)
{
	tree *temp = new tree;
	temp->inf = i;
	temp->left = temp->right = NULL;
	return temp;
}

void Make_Tree(tree* &root)
{
	tree *prev = root, *temp;
	int b, find;
	if (root == NULL) {
		cout << "Enter the root: " << endl;
		cin >> b;
		root = list(b);
	}
	while (1) {
		cout << "Enter the number: " << endl;
		cin >> b;
		if (b<0) break;
		temp = root;
		find = 0;
		while (temp && !find) {
			prev = temp;
			if (b == temp->inf) {
				find = 1;
			}
			else {
				if (b < temp->inf) {
					temp = temp->left;
				}
				else {
					temp = temp->right;
				}
			}
		}
		if (!find) {
			temp = list(b);
			if (b < prev->inf) {
				prev->left = temp;
			}
			else {
				prev->right = temp;
			}
		}
	}
}

void View(tree* &root, int level) {
	if (root) {
		View(root->right, level + 1);
		for (int i = 0; i < level; i++) {
			cout << "   ";
		}
		cout << " " << root->inf;
		View(root->left, level + 1);
	}
	cout << endl;
}

int Task(tree *root)
{
	if (root->left == NULL) {
		return 1;
	}
	int l;
	if (root->left != NULL) {
		l = Task(root->left);
	}
	else {
		l = 0;
	}
	return l + 1;
}

void Del_Tree(tree* &t)
{
	if (t != NULL)
	{
		Del_Tree(t->left);
		Del_Tree(t->right);
		delete t;
		t = NULL;
	}
}

int maxkey(tree *root) {
	root = root->left;
	while (root->right != NULL) {
		root = root->right;
	}
	return root->inf;
}

void Delete(tree* &root)
{
	int key = maxkey(root);
	tree *del = root, *prev = root;
	while (del != NULL && del->inf != key)
	{
		if (del->inf>key) {
			prev = del;
			del = del->left;
		}
		else {
			prev = del;
			del = del->right;
		}
	}
	if (del == NULL) {
		cout << "No key" << endl;
		return;
	}
	else {
		if (prev->inf < del->inf) {
			prev->right = NULL;
		}
		else {
			prev->left = NULL;
		}
		Del_Tree(del);
		cout << "Delete" << endl;;
	}
}

int main()
{
	tree *root = NULL;
	int level = 3, key;
	Make_Tree(root);
	cout << "Your tree: " << endl;
	View(root, level);
	cout << "The number of nodes: " << Task(root) << endl;
	Delete(root);
	View(root, level);
	Del_Tree(root);
	system("pause");
	return 0;
}
