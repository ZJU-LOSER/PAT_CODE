// 20200318B1024.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
string str;
int main()
{
	cin >> str;
	int flag1 = 0;
	int flag2 = 0;
	int index = 0;
	int sum = 0;
	int ppos = -1;
	int epos = -1;
	int len = str.length();
	for (int i = 0; i < len; i++) {
		if (str[0] == '+') {
			flag1 = 1;
		}
		else {
			flag1 = -1;
		}
		if (str[i] == 'E') {
			epos = i;
			if (str[i+1] == '+') {
				flag2 = 1;
			}
			else {
				flag2 = -1;
			}
			index = i;
			continue;
		}
		if (index!=0&&i >= (index + 2)) {
			sum = sum * 10 + str[i] - '0';
		}
		if (str[i] == '.') {
			ppos = i;
		}

	}
	if (flag1 == 1) {

	}
	else {
		cout << "-";
	}
	if (flag2 == 1) {
		if (epos - ppos <= sum + 1) {//没有小数点的情况
			int tmp = epos - ppos;
			int count0 = sum - tmp + 1;
			for (int i = 0; i < len; i++) {
				if (isdigit(str[i]) && str[i] != '0'&&i < epos) {
					cout << str[i];
				}
				if (i >= epos)
					break;
			}
			for (int i = 0; i < count0; i++) {
				cout << "0";
			}
			cout << endl;
		}
		else {//存在小数点的情况
			int countz = 0;//统计前导0的个数
			int countfz = -1;
			for (int i = 0; i < len; i++) {
				if (isdigit(str[i]) && str[i] == '0')
					countz++;
				if (isdigit(str[i]) && str[i] != '0') {
					countfz = i;
					break;
				}
			}
			if (countz <= sum) {//结果无前导0
				char index0 = str[ppos+sum];//标记小数点前的一个字符
				for (int i = 0; i < len; i++) {
					if (isdigit(str[i]) && i>=countfz&&i<epos) {
						cout << str[i];
					}
					if (i==(ppos+sum)) {
						cout << ".";
					}
					if (i >= epos)
						break;
				}
				cout << endl;
			}
			else {//结果仍有前导0
				cout << "0.";
				int result0 = countz - sum - 1;
				for (int i = 0; i < result0; i++) {
					cout << "0";
				}
				for (int i = 0; i < len; i++) {
					if (isdigit(str[i]) && i < epos&&str[i]!='0')
						cout << str[i];
					if (i >= epos)
						break;
				}
				cout << endl;
			}

		}
	}
	else {
		printf("0.");
		for (int i = 0; i < sum - 1; i++)
			printf("0");
		for (int i = 0; i < len; i++) {
			if (isdigit(str[i])&&i<epos) {
				cout << str[i];
			if (i >= epos)
				break;
			}
		}
		cout << endl;
	}
    return 0;
}

