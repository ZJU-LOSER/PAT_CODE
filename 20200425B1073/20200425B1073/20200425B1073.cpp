// 20200425B1073.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct Que {
	int p;
	int aa;
	int ra;
	char ans[5];
}que[110];
struct Peo {
	double mark;
}peo[1010];
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> que[i].p >> que[i].aa >> que[i].ra;
		for (int j = 0; j < que[i].ra; j++) {
			getchar();
			scanf("%c", &que[i].ans[j]);
		}
	}
	for (int i = 0; i < n; i++) {
		peo[i].mark = 0;
		for (int j = 0; j < m; j++) {//检索每一道题
			getchar();//把（输入进来
			int count;
			cin >> count;
			for (int k = 0; k < count; k++) {
				getchar();//消除空格
				char res;
				cin >> res;
				if (res != que[j].ans[k]) {
					
				}
				else {
					continue;
				}
			}
		}
	}
	for (int i = 0; i < m; i++) {
		cout << que[i].ans << endl;
	}
    return 0;
}

