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

int n;
int r[210][210];
int dp[210];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n - 1; i++){
		for(int j = i + 1; j <= n; j++){
			scanf("%d", &r[i][j]);
		}
	}

	dp[1] = 0;
	for(int j = 2; j <= n; j++){
		dp[j] = r[1][j];
		for(int i = 2; i < j; i++){
			if(dp[i] + r[i][j] < dp[j]){
				dp[j] = dp[i] + r[i][j];
			}
		}
	}

	printf("%d\n", dp[n]);
}
