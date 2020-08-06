// 20200314B1017.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<cstdio>
#include<string>
#include<iostream>
#include<algorithm>
using namespace std;
string tmp;
string res;
void divide(string tmp, int num) {
	int index = 0;
	int size = tmp.length(); 
	int flag = 0;
	int result = 0;
	if (size == 1) {
		if (tmp[index] < num) {
			res += '0';
			result = tmp[index] - '0';
		}
		else {
			res += (tmp[index] - '0') / num + '0';
			result = (tmp[index] - '0') % num;
		}
	}
	else {
		while (1) {
			if (tmp[index] - '0' < num) {
				if (index == size - 1 && flag == 1) {
					result = tmp[index] - '0';
					res += '0';
					break;
				}
				int pro = (tmp[index] - '0') * 10 + tmp[index + 1] - '0';
				if (flag == 1)
					res += '0';
				res += pro / num + '0';
				if (index == size - 2) {
					result = pro%num;
					break;
				}
				tmp[++index] = '0' + pro%num;
				flag = 0;
			}
			else if (tmp[index] - '0'>num) {
				int pro = tmp[index] - '0';
				res += pro / num + '0';
				tmp[index] = '0' + pro%num;
				if (index == size - 1) {
					result = pro%num;
					break;
				}
			}
			else if (tmp[index] - '0' == num) {
				res += '1';
				flag = 1;
				if (index == size - 1) {
					result = 0;
					break;
				}
				index++;
			}
		}
	}
	
	cout << res <<" "<<result<< endl;
}
int num;
int main()
{
	cin >> tmp>>num;
	divide(tmp, num);
    return 0;
}

