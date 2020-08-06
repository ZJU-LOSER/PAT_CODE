// 20200323B1044，A1100.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
#include<map>
using namespace std;
int n;
string gw[13] = { "tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec" };
string sw[12] = { "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou" };
map<int, string>vi;
int a, b;
void change(int tmp) {
	int x, y;
	int result = 0;
	for (x = 0; x < 13; x++) {
		for (y = 0; y < 13; y++) {
			if (x * 13 + y == tmp) {
				a = x;
				b = y;
				return;
			}
		}
	}
}
void initial() {
	for (int i = 0; i < 169; i++) {
		change(i);
		if (a == 0) {
			vi[i] = gw[b];
		}
		else
		{
			if (b == 0) {
				vi[i] = sw[a - 1];
			}
			else
			vi[i] = sw[a - 1] + " " + gw[b];
		}
	}
}
int main()
{
	initial();
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		string str;
		getline(cin, str);
		if (isdigit(str[0])) {
			cout << vi[stoi(str)] << endl;
		}
		else {
			for (int i = 0; i < 169; i++) {
				if (vi[i] == str) {
					cout << i << endl;
					continue;
				}
			}
		}
	}
	//for (int i = 0; i < 169; i++) {
	//	cout << i << "=" << vi[i] << endl;
	//}
    return 0;
}

