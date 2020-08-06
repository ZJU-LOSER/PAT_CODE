// PAT-3.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
using namespace std;
int index[1010];
void exc(int index[], int i, int j) {
	int tmp;
	tmp = index[i];
	index[i] = index[j];
	index[j] = tmp;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		index[i] = i;
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		exc(index, i, k);
	}
	cout << index[1];
	if (n > 1) {
		for (int i = 2; i <= n; i++) {
			cout << " " << index[i];
		}
	}
    return 0;
}

