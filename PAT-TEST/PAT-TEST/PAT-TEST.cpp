// PAT-TEST.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<cstdio>
using namespace std;
int index[3010];
int judge(int n) {
	int sum = 0;
	//while (n) {
	//	sum += (n % 10)*(n % 10)*(n % 10);
	//	n /= 10;
	//}
	//if (sum == 1) {
	//	return -1;
	//}
	//else {
	//	return sum;
	//}
	if (n == 1) {
		return -1;
	}
	else {
		while (n) {
			sum += (n % 10)*(n % 10)*(n % 10);
			n /= 10;
		}
		return sum;
	}
}
int res(int n) {
	int i = 0;
	while (judge(n) != -1) {
		if (index[judge(n)] != 1) {
			index[judge(n)] = 1;
		}
		else {
			return judge(n);
		}
		n = judge(n);
		i++;
	}
	return i;
}
int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tmp;
		cin >> tmp;
		for (int j = 0; j < 3010; j++) {
			index[j] = 0;
		}
		cout << res(tmp) << endl;
	}
    return 0;
}

