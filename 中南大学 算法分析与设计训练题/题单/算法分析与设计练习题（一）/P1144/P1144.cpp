// P1144 最短路计数
/*
链接：https://www.luogu.com.cn/problem/P1144
知识点：BFS、最短路计数
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

const int MOD = 100003;
const int MAXN = 1000005;

vector<int> bian[MAXN];
int dis[MAXN];
int cnt[MAXN];

int main(){
	int n, m;
	int x, y;

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d", &x, &y);
		if(x == y){
			continue; // 自环不影响最短路
		}
		bian[x].push_back(y);
		bian[y].push_back(x);
	}

	memset(dis, -1, sizeof(dis));
	memset(cnt, 0, sizeof(cnt));

	queue<int> q;
	dis[1] = 0;
	cnt[1] = 1;
	q.push(1);

	while(!q.empty()){
		int u = q.front();
		q.pop();

		for(auto &v : bian[u]){
			if(dis[v] == -1){
				dis[v] = dis[u] + 1;
				cnt[v] = cnt[u];
				q.push(v);
			}else if(dis[v] == dis[u] + 1){
				cnt[v] = (cnt[v] + cnt[u]) % MOD;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d\n", cnt[i]);
	}
}
