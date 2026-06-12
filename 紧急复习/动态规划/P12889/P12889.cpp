#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int meme[200005];
long long int dp[200005];

int main(){
	int n, k;
	long long int maxk = 0;
	long long int he = 0;
	memset(dp, 0, sizeof(dp));

	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i ++){
		scanf("%d", &meme[i]);
		he += meme[i];
	}

	dp[0] = meme[0];
	maxk = dp[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(dp[i - 1] + meme[i], (long long int)meme[i]);
		maxk = max(maxk, dp[i]);
	}

	maxk *= k - 1;
	he += maxk;

	printf("%lld\n", he);
}
