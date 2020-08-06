// 20200320B1095.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;
const int maxn = 10010;
struct stu {
	string id;
	int mark;
};
struct pla {
	int all;
	int own;
};
stu lis[maxn];
pla ind[1010];
void initial() {
	for (int i = 0; i<1010; i++) {
		ind[i].all = 0;
		ind[i].own = 0;
	}
}
bool cmp2(const pla &a,const pla &b) {
	if (a.all != b.all)
		return a.all > b.all;
	else
		return a.own<b.own;
}
int m, n;
bool cmp(const stu &a, const stu &b) {
	if (a.mark != b.mark) return a.mark > b.mark;
	else {
		return a.id < b.id;
	}
}
int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		cin >> lis[i].id;
		scanf("%d", &lis[i].mark);
	}
	for (int i = 1; i <= m; i++) {
		char c;
		cin >> c;
		string str;//关键字
		if (c == '1') {
			cin >> str;
			string tmp = "1 " + str;
			printf("Case %d: ", i);
			cout << tmp << endl;
			sort(lis, lis + n, cmp);
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (lis[i].id[0] == str[0]) {
					flag++;
					cout << lis[i].id;
					printf(" %d\n", lis[i].mark);
				}
			}
			if (flag == 0)
				printf("NA\n");
		}
		else if (c == '2') {
			cin >> str;
			string tmp = "2 " + str;
			printf("Case %d: ", i);
			cout << tmp << endl;
			int index = 0;
			int sum = 0;
			for (int i = 0; i < n; i++) {
				if (lis[i].id.substr(1, 3) == str) {
					index++;
					sum += lis[i].mark;
				}
			}
			if (index != 0)
				printf("%d %d\n", index, sum);
			else
				printf("NA\n");
		}
		else if (c == '3') {
			cin >> str;
			string tmp = "3 " + str;
			printf("Case %d: ", i);
			cout << tmp << endl;
			initial();
			int flag = 0;
			for (int i = 0; i < n; i++) {
				if (lis[i].id.substr(4, 6) == str) {
					ind[stoi(lis[i].id.substr(1, 3))].all++;
					ind[stoi(lis[i].id.substr(1, 3))].own = stoi(lis[i].id.substr(1, 3));
					flag++;
				}
			}
			if (flag == 0) {
				printf("NA\n");
			}
			else {
				sort(ind, ind + 1010, cmp2);
				int t = 0;
				while (ind[t].all != 0) {
					printf("%d %d\n", ind[t].own, ind[t].all);
					t++;
				}
			}
		}
	}
    return 0;
}

