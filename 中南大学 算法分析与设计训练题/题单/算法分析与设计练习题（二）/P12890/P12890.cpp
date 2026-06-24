#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int box[100005];
int tmp[100005];
long long int inx = 0;

void msort(int left, int right){
	if(left >= right){
		return;
	}

	int mid = left + right;
	mid >>= 1;

	msort(left, mid);
	msort(mid + 1, right);

	int tmpf = 0;
	int ll = left, rr = mid + 1;
	while(ll <= mid && rr <= right){
		if(box[ll] <= box[rr]){
			tmp[tmpf] = box[ll];
			tmpf++;
			ll++;
		}else{
			tmp[tmpf] = box[rr];
			inx += mid - ll + 1;
			tmpf++;
			rr++;
		}
	}

	while(ll <= mid){
		tmp[tmpf] = box[ll];
		tmpf++;
		ll++;
	}
	while(rr <= right){
		tmp[tmpf] = box[rr];
		tmpf++;
		rr++;
	}

	for(int i = left; i <= right; i++){
		box[i] = tmp[i - left];
	}

	return;
}

int main(){
	int n, m;
	long long int ans;

	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &box[i]);
	}

	msort(0, n - 1);

	if(inx == 0){
		printf("0\n");
	}else if((inx & 1) == 0){
		if((m & 1) != 0){
			m <<= 1;
		}
		ans = m;
		while(ans < inx){
			ans += m;
		}
		printf("%lld\n", ans);
	}else if(((inx & 1 )!= 0) && ((m & 1) == 0)){
		printf("-1\n");
	}else{
		ans = m;
		m <<= 1;
		while(ans < inx){
			ans += m;
		}
		printf("%lld\n", ans);
	}
}
