// P1219 [USACO1.5] 八皇后 Checker Challenge
/*
链接：https://www.luogu.com.cn/problem/P1219
知识点：DFS、回溯、八皇后
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int n;
int ans[15];      // ans[i] 表示第 i 行皇后所在的列
int lie[15];      // 列是否被占用
int zuo[30];      // 主对角线是否被占用（row - col + n）
int you[30];      // 副对角线是否被占用（row + col）
int zong = 0;    // 解的个数

void dfs(int row){
	if(row == n + 1){
		zong++;
		if(zong <= 3){
			for(int i = 1; i <= n; i++){
				printf("%d", ans[i]);
				if(i != n){
					printf(" ");
				}
			}
			printf("\n");
		}
		return;
	}

	for(int col = 1; col <= n; col++){
		if(!lie[col] && !zuo[row - col + n] && !you[row + col]){
			ans[row] = col;
			lie[col] = 1;
			zuo[row - col + n] = 1;
			you[row + col] = 1;

			dfs(row + 1);

			lie[col] = 0;
			zuo[row - col + n] = 0;
			you[row + col] = 0;
		}
	}
}

int main(){
	scanf("%d", &n);

	memset(lie, 0, sizeof(lie));
	memset(zuo, 0, sizeof(zuo));
	memset(you, 0, sizeof(you));

	dfs(1);

	printf("%d\n", zong);
}
