// P1162 填涂颜色
/*
链接：https://www.luogu.com.cn/problem/P1162
知识点：BFS、 Flood Fill
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

int ditu[35][35];
int vis[35][35];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};

int main(){
	int n;
	queue<pair<int, int>> q;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf("%d", &ditu[i][j]);
		}
	}

	// 加一圈 0，从 (0,0) 开始 BFS，所有能到达的 0 都是圈外的
	q.push({0, 0});
	vis[0][0] = 1;
	while(!q.empty()){
		auto [x, y] = q.front();
		q.pop();

		for(int i = 0; i < 4; i++){
			int nx = x + dx[i];
			int ny = y + dy[i];

			if(nx >= 0 && nx <= n + 1 && ny >= 0 && ny <= n + 1 && !vis[nx][ny] && ditu[nx][ny] == 0){
				vis[nx][ny] = 1;
				q.push({nx, ny});
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(ditu[i][j] == 0 && !vis[i][j]){
				ditu[i][j] = 2;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d", ditu[i][j]);
			if(j != n){
				printf(" ");
			}
		}
		printf("\n");
	}
}
