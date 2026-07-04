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
#include <math.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

const int MAXN = 500010;

long long m[MAXN];
long long x[MAXN];
long long n, k;

// 检查威力为 p 时，k 发子弹是否足够
bool check(long long p){
	if(p <= 0) return false;
	// 最大溅射距离：满足 d^2 < p 的最大 d
	long long R = (long long)sqrt((long double)(p - 1));
	while((R + 1) * (R + 1) < p) R++;
	while(R * R >= p) R--;

	memset(x, 0, sizeof(long long) * (n + 2));
	long long S0 = 0, S1 = 0, S2 = 0; // 窗口内 x_j, x_j*j, x_j*j*j
	long long total = 0;

	for(long long i = n; i >= 1; i--){
		// 当前窗口为 [i+1, min(n, i+R)]，已包含所有能溅射到 i 的右侧子弹
		long long splash = p * S0 - S2 + 2LL * i * S1 - i * i * S0;
		if(splash <= m[i]){
			long long need = m[i] - splash;
			x[i] = need / p + 1;
			total += x[i];
			if(total > k) return false;
		}
		// 把第 i 个怪物处的子弹加入窗口，供左侧怪物计算溅射
		S0 += x[i];
		S1 += x[i] * i;
		S2 += x[i] * i * i;
		// 窗口右边界收缩：对于下一个 i-1，窗口上界为 i-1+R，需去掉 i+R
		if(i + R <= n){
			long long j = i + R;
			S0 -= x[j];
			S1 -= x[j] * j;
			S2 -= x[j] * j * j;
		}
	}
	return total <= k;
}

int main(){
	scanf("%lld%lld", &n, &k);
	long long maxM = 0;
	for(long long i = 1; i <= n; i++){
		scanf("%lld", &m[i]);
		if(m[i] > maxM) maxM = m[i];
	}

	long long left = 1;
	long long right = maxM + (n - 1) * (n - 1) + 1;
	while(left < right){
		long long mid = left + (right - left) / 2;
		if(check(mid)){
			right = mid;
		}else{
			left = mid + 1;
		}
	}

	printf("%lld\n", left);
}
