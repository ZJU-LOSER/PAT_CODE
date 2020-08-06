// 20200316B1068.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
const int maxn = 1010;
int math[maxn][maxn] = { 0 };
int m, n;
int tol;
int judge(int i, int j) {
	int flag = 1;
	int tmp = math[i][j];
	if (tmp - math[i - 1][j] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i + 1][j] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i][j - 1] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i][j + 1] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i + 1][j + 1] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i + 1][j - 1] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i - 1][j + 1] <= tol) {
		flag = 0;
		return flag;
	}
	if (tmp - math[i - 1][j + 1] <= tol) {
		flag = 0;
		return flag;
	}
	return flag;
}
map<int, int>vi;
int tm[maxn] = { 0 };
int main()
{
	int mark = 0;
	cin >> m >> n >> tol;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> math[i][j];
			if (!vi[math[i][j]]) {
				vi[math[i][j]] = ++mark;
				tm[mark]++;
			}
			else {
				tm[vi[math[i][j]]]++;
			}
		}
	}
	int flag = 0;
	int index = 0;
	int line = -1;
	int col = -1;
	int result = 0;
	for (int i = 0; i < n ; i++) {
		for (int j = 0; j < m ; j++) {
			if (tm[vi[math[i][j]]] == 1 && judge(i, j) == 1) {
				if (index == 0) {
					flag = 1;
					col = i ;
					line = j ;
					result = math[i][j];
					index++;
				}
				else {
					index++;
					break;
				}
			}
			else {
				continue;
			}
		}
	}
	if (flag == 0) {
		cout << "Not Exist" << endl;
	}
	if (flag&&index > 1) {
		cout << "Not Unique" << endl;
	}
	if (flag&&index == 1) {
		printf("(%d, %d): %d\n", line,col,result);
	}
    return 0;
}

