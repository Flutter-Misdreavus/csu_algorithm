// P2440 木材加工
/*
链接：https://www.luogu.com.cn/problem/P2440
知识点：二分答案
*/
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

long long yuanmu[100005];

int main(){
	int n;
	long long k;
	scanf("%d%lld", &n, &k);

	long long maxL = 0;
	for(int i = 1; i <= n; i++){
		scanf("%lld", &yuanmu[i]);
		if(yuanmu[i] > maxL){
			maxL = yuanmu[i];
		}
	}

	long long left = 1, right = maxL;
	long long ans = 0;
	while(left <= right){
		long long mid = (left + right) / 2;
		long long cnt = 0;
		for(int i = 1; i <= n; i++){
			cnt += yuanmu[i] / mid;
		}

		if(cnt >= k){
			ans = mid;
			left = mid + 1;
		}else{
			right = mid - 1;
		}
	}

	printf("%lld\n", ans);
}
