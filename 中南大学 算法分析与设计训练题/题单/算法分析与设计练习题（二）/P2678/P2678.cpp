// P2678 [NOIP 2015 提高组] 跳石头
/*
链接：https://www.luogu.com.cn/problem/P2678
知识点：二分答案、贪心
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

int shitou[50005];

int main(){
	int L, n, m;
	scanf("%d%d%d", &L, &n, &m);

	for(int i = 1; i <= n; i++){
		scanf("%d", &shitou[i]);
	}
	shitou[n + 1] = L;

	int left = 1, right = L;
	int ans = 0;
	while(left <= right){
		int mid = (left + right) / 2;

		int cnt = 0;
		int last = 0;
		for(int i = 1; i <= n + 1; i++){
			if(shitou[i] - last < mid){
				cnt++;
			}else{
				last = shitou[i];
			}
		}

		if(cnt > m){
			right = mid - 1;
		}else{
			ans = mid;
			left = mid + 1;
		}
	}

	printf("%d\n", ans);
}
