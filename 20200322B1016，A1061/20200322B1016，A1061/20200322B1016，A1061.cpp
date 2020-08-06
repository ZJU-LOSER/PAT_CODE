// 20200322B1016，A1061.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
#include<map>
#include<algorithm>
using namespace std;
string s1, s2, s3, s4;
string day[7] = { "MON","TUE","WED","THU","FRI","SAT","SUN" };
string gt = "0123456789ABCDEFGHIJKLMN";
int main()
{
	cin >> s1 >> s2 >> s3 >> s4;
	int len1, len2, len3, len4;
	len1 = s1.length();
	len2 = s2.length();
	len3 = s3.length();
	len4 = s4.length();
	int index = -1;
	for (int i = 0; i < min(len1, len2); i++) {
		if (s1[i] == s2[i] && isalpha(s1[i]) && s1[i] >= 'A'&&s1[i]<='G') {
			cout << day[s1[i] - 'A'] << " ";
			index = i;
			break;
		}
	}
	int flag = 0;
	for (int i = index + 1; i < min(len1, len2); i++) {
		if (s1[i] == s2[i]&&(isdigit(s1[i])||s1[i]>='A'&&s1[i]<='N')) {
			for (int j = 0; j < gt.length(); j++) {
				if (s1[i] == gt[j]) {
					printf("%02d", j);
					flag = 1;
					break;
				}
			}
		}
		if (flag)
			break;
	}
	for (int i = 0; i < min(len3, len4); i++) {
		if (s3[i] == s4[i] && isalpha(s3[i])) {
			printf(":%02d", i);
			break;
		}
	}
    return 0;
}

