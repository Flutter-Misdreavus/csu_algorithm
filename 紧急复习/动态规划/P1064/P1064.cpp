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

int vqp[3][62];
long long int que[4][62];
long long int value[4][62]; // 价格乘重要度
// 0: 主件
// 1: 主件+附1
// 2: 主件+附2
// 3: 主件+附12
long long int dp[32010];

void show(int m){
	for(int i = 1; i <= m; i++){
		printf("%lld|%lld|%lld|%lld\n", que[0][i], que[1][i], que[2][i], que[3][i]);
	}
	printf("\n\n");
	for(int i = 1; i <= m; i++){
		printf("%lld|%lld|%lld|%lld\n", value[0][i], value[1][i], value[2][i], value[3][i]);
	}
	printf("\n\n");
}

int main(){
	int n, m;
	int v, q, p;
	memset(que, 0, sizeof(que));
	memset(value, 0, sizeof(value));
	memset(dp, 0, sizeof(dp));

	scanf("%d%d", &n, &m);
	for(int i = 1; i <= m; i++){
		scanf("%d%d%d", &vqp[0][i], &vqp[1][i], &vqp[2][i]);
		if(vqp[2][i] == 0){
			// 主件
			que[0][i] = vqp[0][i];
			value[0][i] = vqp[0][i] * vqp[1][i];
			continue;
		}
	}
	for(int i = 1; i <= m; i++){
		v = vqp[0][i];
		q = vqp[1][i];
		p = vqp[2][i];


		// 附件
		if(que[1][p] == 0){
			// 附件1
			que[1][p] = que[0][p] + v;
			value[1][p] = value[0][p] + v * q;
		}else{
			que[2][p] = que[0][p] + v;
			value[2][p] = value[0][p] + v * q;
			que[3][p] = que[1][p] + v;
			value[3][p] = value[1][p] + v * q;
		}
	}

	for(int i = 1; i <= m; i++){
		for(int j = n; j >= 0; j--){
			for(int sl = 0; sl < 4; sl++){
				q = que[sl][i];
				if(q == 0 || j < q){
					continue;
				}
				v = value[sl][i];

				dp[j] = max(dp[j], dp[j - q] + v);
			}
		}
	}

	//show(m);

	printf("%lld\n", dp[n]);
}
