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

int ditu[110][110];
int f[110][110];
int r, c;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int dfs(int x, int y){
	if(f[x][y] != 0) return f[x][y];
	f[x][y] = 1;
	for(int i = 0; i < 4; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && nx < r && ny >= 0 && ny < c && ditu[nx][ny] < ditu[x][y]){
			int t = dfs(nx, ny) + 1;
			if(t > f[x][y]) f[x][y] = t;
		}
	}
	return f[x][y];
}

int main(){
	scanf("%d%d", &r, &c);
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			scanf("%d", &ditu[i][j]);
		}
	}

	int ans = 0;
	for(int i = 0; i < r; i++){
		for(int j = 0; j < c; j++){
			int t = dfs(i, j);
			if(t > ans) ans = t;
		}
	}

	printf("%d\n", ans);
}
