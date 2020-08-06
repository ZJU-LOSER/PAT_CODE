// 20200314B1079.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
string tmp;
string trans(string tmp) {
	string newone = tmp;
	reverse(newone.begin(), newone.end());
	return newone;
}
int judge(string tmp) {
	if (tmp == trans(tmp)) {
		return 1;
	}
	else {
		return 0;
	}
}
int getnum(string tmp) {
	int cap = tmp.size();
	int num = 0;
	for (int i = 0; i <cap ; i++) {
		num = num * 10 + tmp[i] - '0';
	}

	return num;
}
int main()
{
	cin >> tmp;
	if (judge(tmp) == 1) {
		cout << tmp << " is a palindromic number." << endl;
		return 0;
	}
	int index = 0;
	while (judge(tmp) == 0) {
		index++;
		string tran = trans(tmp);
		int result = getnum(tran) + getnum(tmp);
		string res = to_string(result);
		if (judge(res) == 1&&index<=10) {
			cout << tmp << " + " << tran << " = " << res << endl;
			cout << res << " is a palindromic number." << endl;
			break;
		}
		else if (judge(res) == 0 && index <= 10) {
			cout << tmp << " + " << tran << " = " << res << endl;
			tmp = res;
		}
		else {
			cout << "Not found in 10 iterations." << endl;
			break;
		}
	}
    return 0;
}
