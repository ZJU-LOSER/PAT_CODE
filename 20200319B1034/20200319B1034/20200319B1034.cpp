// 20200319B1034.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<string>
#include<cctype>
#include<algorithm>
using namespace std;
string a;//分子
string b;//分母
int flag1;
int flag2;
int getpos(string str) {
	int i = 0;
	while (str[i] != '/') i++;
	return i;
}
int getflag(string str) {
	if (isdigit(str[0])){
		return 1;
	}
	else {
		return -1;
	}
}
int getsub1(string str, int flag,int pos) {
	if (flag == 1) {
		return stoi(str.substr(0, pos));
	}
	else {
		return -1 * stoi(str.substr(1, pos - 1));
	}
}
int getsub2(string str, int flag,int pos) {
	return stoi(str.substr(pos+1));
}
int main()
{
	cin >> a >> b;
	cout << a << endl;
	cout << b << endl;
	flag1 = getflag(a);
    flag2 = getflag(b);
	int pos1 = getpos(a);
	int pos2 = getpos(b);
	int asub1 = getsub1(a,flag1,pos1);
	int asub2 = getsub2(a,flag1,pos1);
	int bsub1 = getsub1(b, flag2,pos2);
	int bsub2 = getsub2(b, flag2,pos2);
	cout << asub1 << " " << asub2 << endl;
	cout << bsub1 << " " << bsub2 << endl;
    return 0;
}

