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

struct Edge{
	int u, v, w;
}edge[50010];

struct Node{
	int to;
	int w;
};

bool cmp(Edge a, Edge b){
	return a.w > b.w;
}

int n, m, q;
int fa[10010];
int depth[10010];
int parent[20][10010];
int minw[20][10010];
vector<Node> tree[10010];

int find(int x){
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}

void dfs(int u, int p){
	parent[0][u] = p;
	for(int i = 0; i < (int)tree[u].size(); i++){
		int v = tree[u][i].to;
		int w = tree[u][i].w;
		if(v == p) continue;
		depth[v] = depth[u] + 1;
		minw[0][v] = w;
		dfs(v, u);
	}
}

int lca(int u, int v){
	int ans = 1000000000;
	if(depth[u] < depth[v]){
		int t = u; u = v; v = t;
	}
	for(int k = 15; k >= 0; k--){
		if(depth[parent[k][u]] >= depth[v]){
			if(minw[k][u] < ans) ans = minw[k][u];
			u = parent[k][u];
		}
	}
	if(u == v) return ans;
	for(int k = 15; k >= 0; k--){
		if(parent[k][u] != parent[k][v]){
			if(minw[k][u] < ans) ans = minw[k][u];
			if(minw[k][v] < ans) ans = minw[k][v];
			u = parent[k][u];
			v = parent[k][v];
		}
	}
	if(minw[0][u] < ans) ans = minw[0][u];
	if(minw[0][v] < ans) ans = minw[0][v];
	return ans;
}

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &edge[i].u, &edge[i].v, &edge[i].w);
	}

	sort(edge, edge + m, cmp);
	for(int i = 1; i <= n; i++) fa[i] = i;
	for(int i = 0; i < m; i++){
		int fu = find(edge[i].u);
		int fv = find(edge[i].v);
		if(fu != fv){
			fa[fu] = fv;
			tree[edge[i].u].push_back((Node){edge[i].v, edge[i].w});
			tree[edge[i].v].push_back((Node){edge[i].u, edge[i].w});
		}
	}

	memset(minw, 0x3f, sizeof(minw));
	for(int i = 1; i <= n; i++){
		if(fa[i] == i){
			depth[i] = 1;
			minw[0][i] = 1000000000;
			dfs(i, i);
		}
	}

	for(int k = 1; k <= 15; k++){
		for(int i = 1; i <= n; i++){
			parent[k][i] = parent[k-1][parent[k-1][i]];
			minw[k][i] = min(minw[k-1][i], minw[k-1][parent[k-1][i]]);
		}
	}

	scanf("%d", &q);
	for(int i = 0; i < q; i++){
		int u, v;
		scanf("%d%d", &u, &v);
		if(find(u) != find(v)){
			printf("-1\n");
		}else{
			printf("%d\n", lca(u, v));
		}
	}
}
