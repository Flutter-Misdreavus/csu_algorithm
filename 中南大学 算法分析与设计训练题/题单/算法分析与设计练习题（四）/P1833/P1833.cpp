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

int treet[10010];
int treec[10010];
int treep[10010];
int dp[1010];

int main(){
	int nowt1, nowt2;
	int schoolt1, schoolt2;
	int n;
	int tim;
	memset(dp, 0, sizeof(dp));

	scanf("%d:%d%d:%d%d", &nowt1, &nowt2, &schoolt1, &schoolt2, &n);
	tim = 60 * (schoolt1 - nowt1) + (schoolt2 - nowt2);

	for(int i = 0; i < n; i++){
		scanf("%d%d%d", &treet[i], &treec[i], &treep[i]);
	}

	for(int i = 0; i < n; i++){
		if(treep[i] == 0){
			// 完全背包
			for(int j = treet[i]; j <= tim; j++){
				dp[j] = max(dp[j], dp[j - treet[i]] + treec[i]);
			}
		}else{
			int trp = treep[i];
			for(int k = 1, trt, trc; k <= trp; k <<= 1){
				trt = k * treet[i];
				trc = k * treec[i];
				for(int j = tim; j >= trt; j--){
					dp[j] = max(dp[j], dp[j - trt] + trc);
				}
				trp -= k;
			}

			if(trp != 0){
				int trt = trp * treet[i];
				int trc = trp * treec[i];
				for(int j = tim; j >= trt; j--){
					dp[j] = max(dp[j], dp[j - trt] + trc);
				}
			}
		}
	}

	printf("%d\n", dp[tim]);
}
