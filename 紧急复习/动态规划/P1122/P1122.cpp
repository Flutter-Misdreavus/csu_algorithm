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

int flower[16005];
vector<int> bian[16005];
int dp[16005]; // dp[i]代表以i为根的最大子树
int maxflow;

void dfs(int dian, int father){
	dp[dian] = flower[dian];

	for(auto& i : bian[dian]){
		if(i == father){
			continue;
		}

		dfs(i, dian);
		dp[dian] += max(0, dp[i]);
	}

	maxflow = max(dp[dian], maxflow);
}

int main(){
	int n;
	int a, b;
	memset(dp, 0, sizeof(dp));

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &flower[i]);
	}
	for(int i = 1; i < n; i++){
		scanf("%d%d", &a, &b);
		bian[a].push_back(b);
		bian[b].push_back(a);
	}

	maxflow = flower[1];
	dfs(1, 0);

	printf("%d\n", maxflow);
}
