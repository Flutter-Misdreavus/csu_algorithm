#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int bi[1010];
int dp[10010]; //dp[i] 凑到i元所需要的最少纸币数量

int main(){
	int n, w;
	int co;
	memset(dp, 0X7F, sizeof(dp));
	scanf("%d%d", &n, &w);

	for(int i = 0; i < n; i++){
		scanf("%d", &bi[i]);
	}
	dp[0] = 0;

	for(int i = 0; i < n; i++){
		co = bi[i];
		for(int j = co; j <= w; j++){
			dp[j] = min(dp[j - co] + 1, dp[j]);
		}
	}

	printf("%d\n", dp[w]);
}
