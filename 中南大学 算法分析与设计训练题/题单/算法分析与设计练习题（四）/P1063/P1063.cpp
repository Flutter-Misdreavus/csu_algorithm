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

int conme[205];
int dp[205][205];

int main(){
	int n;
	int e = 0;
	memset(dp, 0, sizeof(dp));

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &conme[i]);
		conme[i + n] = conme[i];
	}
	conme[2*n + 1] = conme[1];

	for(int i = 2; i <= 2*n; i++){
		for(int j = i - 1; j >= 1 && i - j < n; j--){
			for(int k = j; k < i; k++){
				dp[j][i] = max(dp[j][i], dp[j][k] + dp[k + 1][i] + conme[j] * conme[k + 1] * conme[i + 1]);
			}
		}
	}

	for(int i = 1; i < 2 * n; i++){
		e = max(dp[i][i + n - 1], e);
	}

	printf("%d\n", e);
}
