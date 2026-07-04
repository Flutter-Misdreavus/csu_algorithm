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

int n, m, k;
int s, t;
vector<pair<int, int>> g[10010];
long long dis[10010][12];
int vis[10010][12];

struct State{
	int u;
	int used;
	long long d;
	bool operator<(const State& other) const {
		return d > other.d;
	}
};

void dijkstra(){
	priority_queue<State> pq;
	memset(dis, 0x3f, sizeof(dis));
	dis[s][0] = 0;
	pq.push((State){s, 0, 0});
	while(!pq.empty()){
		State cur = pq.top();
		pq.pop();
		int u = cur.u;
		int used = cur.used;
		if(vis[u][used]) continue;
		vis[u][used] = 1;
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			// 付费走，层数不变
			if(dis[u][used] + w < dis[v][used]){
				dis[v][used] = dis[u][used] + w;
				pq.push((State){v, used, dis[v][used]});
			}
			// 免费走，进入下一层
			if(used < k && dis[u][used] < dis[v][used + 1]){
				dis[v][used + 1] = dis[u][used];
				pq.push((State){v, used + 1, dis[v][used + 1]});
			}
		}
	}
}

int main(){
	scanf("%d%d%d", &n, &m, &k);
	scanf("%d%d", &s, &t);
	for(int i = 0; i < m; i++){
		int a, b, c;
		scanf("%d%d%d", &a, &b, &c);
		g[a].push_back(make_pair(b, c));
		g[b].push_back(make_pair(a, c));
	}

	dijkstra();

	long long ans = INF;
	for(int i = 0; i <= k; i++){
		if(dis[t][i] < ans) ans = dis[t][i];
	}

	printf("%lld\n", ans);
}
