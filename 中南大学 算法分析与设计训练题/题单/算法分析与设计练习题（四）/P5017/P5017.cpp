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

const int MAXT = 4000200;

int n, m;
int tmax;
int cnt[MAXT];
int sum[MAXT];
int f[MAXT];

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		int ti;
		scanf("%d", &ti);
		if(ti > tmax) tmax = ti;
		cnt[ti]++;
		sum[ti] += ti;
	}

	for(int i = 1; i < tmax + m; i++){
		cnt[i] += cnt[i - 1];
		sum[i] += sum[i - 1];
	}

	for(int i = 0; i < tmax + m; i++){
		if(i >= m && cnt[i - m] == cnt[i]){
			f[i] = f[i - m];
			continue;
		}
		f[i] = cnt[i] * i - sum[i];
		int start = i - m - m + 1;
		if(start < 0) start = 0;
		for(int j = start; j <= i - m; j++){
			int val = f[j] + (cnt[i] - cnt[j]) * i - (sum[i] - sum[j]);
			if(val < f[i]) f[i] = val;
		}
	}

	int ans = 0x3f3f3f3f;
	for(int i = tmax; i < tmax + m; i++){
		if(f[i] < ans) ans = f[i];
	}

	printf("%d\n", ans);
}
