// PAT-TEST2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
#include<map>
using namespace std;
map<string, int>vi;
void PRINT(int n) {
	if (n == 1) {
		printf("Gan laji\n");
	}
	else if (n == 2) {
		printf("Shi laji\n");
	}
	else if (n == 3) {
		printf("Ke Hui Shou\n");
	}
	else {
		printf("You Hai laji\n");
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		string s;
		int flag;
		cin >> s;
		scanf("%d", &flag);
		vi[s] = flag;
	}
	while (1) {
		int F = 0;
		string str;
		cin >> str;
		if (str == "#") {
			break;
		}
		if (vi[str] != 0) {
			PRINT(vi[str]);
			F = 1;
		}
		else {
			printf("?\n");
		}
	}
	return 0;
}

