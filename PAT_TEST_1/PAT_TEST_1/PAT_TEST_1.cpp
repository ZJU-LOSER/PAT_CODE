// PAT_TEST_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include<cstdio>
#include<string>
#include<ctype.h>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<set>
using namespace std;
int index[1100] = { 0 };
int index2[1100] = { 0 };
int math[10][1100] = { 0 };
vector<int>cou;
int flag[10] = { 0 };
int main()
{
	cou.clear();
	int a, b;
	cin >> a >> b;
	int first = abs(a - b);
	index2[first] = 1;
	index2[a] = 1;
	index2[b] = 1;
	cou.push_back(first);
	cou.push_back(a);
	cou.push_back(b);
	int m, n;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf("%d", &math[i][j]);
		}
	}
	for (int j = 0; j < m; j++) {
		for (int i = 0; i < n; i++) {
			if (flag[j] != 0) {
				continue;
			}
			cout << "math[i][j] = " << math[i][j] << endl;
			if (index[math[i][j]] == 1 || index2[math[i][j]] == 0) {
				flag[j] = i + 1;
			}
			else {
				int t = 0;
				for (int k = 0; k < cou.size(); k++) {
					if (cou[k] == math[i][j]) {
						cout << "找到了" << endl;
						t = 1;
						break;
					}
				}
				if (t == 0) {
					flag[j] = i + 1;
					cout << "???" << endl;
				}
				else {
					index[math[i][j]] = 1;
					int tmp = cou.size();
					for (int k = 0; k < tmp; k++) {
						if (index[abs(math[i][j] - cou[k])] == 0&&index2[abs(math[i][j] - cou[k])]==0) {
							cou.push_back(abs(math[i][j] - cou[k]));
							index2[abs(math[i][j] - cou[k])] = 1;
						}
					}
				}
				
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << flag[i] << endl;
	}
	for (int i = 0; i < cou.size(); i++) {
		cout << cou[i] << endl;
	}
	return 0;
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件