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

int n, m;
int C[1010];
vector<pair<int, int>> g[1010];
long long dis[1010];
int vis[1010];

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
	dis[1] = 0;
	pq.push((State){1, 0});
	while(!pq.empty()){
		State cur = pq.top();
		pq.pop();
		int u = cur.u;
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			int cost = w + (u == 1 ? 0 : C[u]);
			if(dis[u] + cost < dis[v]){
				dis[v] = dis[u] + cost;
				pq.push((State){v, dis[v]});
			}
		}
	}
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; i++){
		scanf("%d", &C[i]);
	}
	for(int i = 0; i < m; i++){
		int u, v, c;
		scanf("%d%d%d", &u, &v, &c);
		g[u].push_back(make_pair(v, c));
		g[v].push_back(make_pair(u, c));
	}

	dijkstra();

	printf("%lld\n", dis[n]);
}
