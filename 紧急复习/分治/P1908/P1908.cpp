#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

long nums[500010];
long tmp[500010];
long long ans = 0;

void msort(int left, int right){
	if(left >= right){
		return;
	}

	int mid = left + right;
	mid = mid >> 1;

	msort(left, mid);
	msort(mid + 1, right);

	int tmplo = 0;
	int ll, rr;
	for(ll = left, rr = mid + 1; ll <= mid && rr <= right;){
		if(nums[ll] <= nums[rr]){
			tmp[tmplo] = nums[ll];
			ll++;
			tmplo++;
		}else{
			tmp[tmplo] = nums[rr];
			rr++;
			tmplo++;
			ans += mid - ll + 1; // 加上左边数组的数量
		}
	}
	while(ll <= mid){
		tmp[tmplo] = nums[ll];
		ll++;
		tmplo++;
	}
	while(rr <= right){
		tmp[tmplo] = nums[rr];
		rr++;
		tmplo++;
	}

	tmplo = 0;
	for(int i = left; i <= mid; i++){
		nums[i] = tmp[tmplo];
		tmplo++;
	}
	for(int j = mid + 1; j <= right; j++){
		nums[j] = tmp[tmplo];
		tmplo++;
	}

	return;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%ld", &nums[i]);
	}

	msort(0, n - 1);
	printf("%lld\n", ans);
}
