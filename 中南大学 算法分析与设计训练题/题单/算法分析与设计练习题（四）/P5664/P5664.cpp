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

const int MOD = 998244353;

int n, m;
int a[110][2010];
int rowsum[110];
int dp[220];
int ndp[220];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			scanf("%d", &a[i][j]);
			rowsum[i] = (rowsum[i] + a[i][j]) % MOD;
		}
	}

	int total = 1;
	for(int i = 0; i < n; i++){
		total = (long long)total * (1 + rowsum[i]) % MOD;
	}
	total = (total - 1 + MOD) % MOD;

	int badsum = 0;
	for(int j = 0; j < m; j++){
		memset(dp, 0, sizeof(dp));
		dp[n] = 1;
		for(int i = 0; i < n; i++){
			int c = (rowsum[i] - a[i][j] + MOD) % MOD;
			memset(ndp, 0, sizeof(ndp));
			for(int d = 0; d <= 2 * n; d++){
				if(dp[d] == 0) continue;
				// 不选
				ndp[d] = (ndp[d] + dp[d]) % MOD;
				// 选食材 j
				ndp[d + 1] = (ndp[d + 1] + (long long)dp[d] * a[i][j]) % MOD;
				// 选非 j 食材
				ndp[d - 1] = (ndp[d - 1] + (long long)dp[d] * c) % MOD;
			}
			memcpy(dp, ndp, sizeof(ndp));
		}
		for(int d = n + 1; d <= 2 * n; d++){
			badsum = (badsum + dp[d]) % MOD;
		}
	}

	int ans = (total - badsum + MOD) % MOD;
	printf("%d\n", ans);
}
