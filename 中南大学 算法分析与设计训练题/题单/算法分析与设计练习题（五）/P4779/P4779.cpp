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

const long long INF = 0x3f3f3f3f3f3f3f3fLL;

int n, m, s;
vector<pair<int, int>> g[100010];
long long dis[100010];
int vis[100010];

struct State{
	int u;
	long long d;
	bool operator<(const State& other) const {
		return d > other.d;
	}
};

void dijkstra(){
	priority_queue<State> pq;
	memset(dis, 0x3f, sizeof(dis));
	dis[s] = 0;
	pq.push((State){s, 0});
	while(!pq.empty()){
		State cur = pq.top();
		pq.pop();
		int u = cur.u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push((State){v, dis[v]});
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &s);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
	}

	dijkstra();

	for(int i = 1; i <= n; i++){
		printf("%lld ", dis[i]);
	}
	printf("\n");
}
