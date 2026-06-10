#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int tim[104];
int value[104];
int dp[1004];

int main(){
	int t, m;
	memset(dp, 0, sizeof(dp));
	scanf("%d%d", &t, &m);

	for(int i = 0; i < m; i++){
		scanf("%d%d", &tim[i], &value[i]);
	}

	for(int i = 0; i < m; i++){
		for(int j = t; j >= tim[i]; j--){
			dp[j] = max(dp[j], dp[j - tim[i]] + value[i]);
		}
	}

	printf("%d\n", dp[t]);
}
