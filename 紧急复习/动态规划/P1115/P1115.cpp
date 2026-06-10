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

int nums[200010];
int dp[200010]; //0-i的最大和

int main(){
	int n;
	int maxi;

	scanf("%d", &n);
	for(int i = 0; i < n ; i++){
		scanf("%d", &nums[i]);
	}

	dp[0] = nums[0];
	maxi = dp[0];
	for(int i = 1; i < n; i++){
		dp[i] = max(dp[i - 1] + nums[i], nums[i]);
		maxi = max(maxi, dp[i]);
	}
	printf("%d\n", maxi);

}
