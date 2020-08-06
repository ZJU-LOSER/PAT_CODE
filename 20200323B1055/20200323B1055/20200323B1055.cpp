// 20200323B1055.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
const int maxn = 10010;
struct Stu {
	string id;
	int len;
};
Stu stu[maxn];
int n, k,col;
bool cmp(Stu a, Stu b) {
	if (a.len != b.len) return a.len > b.len;
	else return a.id < b.id;
}
string res[110][110];
int change(int t) {
	static int ind = 1;
	int re = t + 1;
	ind = -1 * (ind + 1);
}
int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> stu[i].id;
		scanf("%d", &stu[i].len);
	}
	sort(stu, stu + n, cmp);
	for (int i = 0; i < n; i++) {
		cout << stu[i].id << " " << stu[i].len << endl;
	}
    col = n / k;
	int index = n - 1;
	for (int i = k - 1; i > 0; i--) {
		int t = col / 2 + 1;
		for (int j = col; j >= 1; j--) {
			res[i][t] = stu[index].id;
			t = change(t);
			index--;
		}
	}
    return 0;
}

