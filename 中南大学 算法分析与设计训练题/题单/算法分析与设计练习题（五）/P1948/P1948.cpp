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

const int INF = 0x3f3f3f3f;

int n, p, k;
vector<pair<int, int>> g[1010];
int dis[1010];
deque<int> dq;

// 检查是否存在 1 到 n 的路径，其中长度大于 x 的边不超过 k 条
bool check(int x){
	memset(dis, 0x3f, sizeof(dis));
	dis[1] = 0;
	dq.clear();
	dq.push_back(1);
	while(!dq.empty()){
		int u = dq.front();
		dq.pop_front();
		for(int i = 0; i < (int)g[u].size(); i++){
			int v = g[u][i].first;
			int w = g[u][i].second;
			int cost = (w > x) ? 1 : 0;
			if(dis[u] + cost < dis[v]){
				dis[v] = dis[u] + cost;
				if(cost == 0){
					dq.push_front(v);
				}else{
					dq.push_back(v);
				}
			}
		}
	}
	return dis[n] <= k;
}

int main(){
	scanf("%d%d%d", &n, &p, &k);
	int maxL = 0;
	for(int i = 0; i < p; i++){
		int a, b, l;
		scanf("%d%d%d", &a, &b, &l);
		g[a].push_back(make_pair(b, l));
		g[b].push_back(make_pair(a, l));
		if(l > maxL) maxL = l;
	}

	int left = 0, right = maxL, ans = -1;
	while(left <= right){
		int mid = (left + right) / 2;
		if(check(mid)){
			ans = mid;
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}

	printf("%d\n", ans);
}
