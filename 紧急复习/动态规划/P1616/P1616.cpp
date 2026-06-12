#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int timem[10010];
int value[10010];
long int dp[10000010];

int main(){
	int t, m;
	scanf("%d%d", &t, &m);
	memset(dp, 0, sizeof(dp));

	for(int i = 0; i < m; i++){
		scanf("%d%d", &timem[i], &value[i]);
	}

	for(int i = 0; i < m; i++){
		for(int j = timem[i]; j <= t; j++){
			dp[j] = max(dp[j], dp[j - timem[i]] + value[i]);
		}
	}

	printf("%ld\n", dp[t]);
}
