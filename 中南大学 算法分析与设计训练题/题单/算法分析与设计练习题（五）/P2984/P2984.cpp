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

int n, m, B;
vector<pair<int, int>> g[50010];
long long dis[50010];
int vis[50010];

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
			if(dis[u] + w < dis[v]){
				dis[v] = dis[u] + w;
				pq.push((State){v, dis[v]});
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &B);
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
	}

	dijkstra();

	for(int i = 0; i < B; i++){
		int p, q;
		scanf("%d%d", &p, &q);
		printf("%lld\n", dis[p] + dis[q]);
	}
}
