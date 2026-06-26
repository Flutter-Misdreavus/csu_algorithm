// P7883 平面最近点对（加强加强版）
/*
链接：https://www.luogu.com.cn/problem/P7883
知识点：分治、平面最近点对
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
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

struct Point{
	int x, y;
};

Point p[400005];
Point tmp[400005];
Point t2[400005];

bool cmpx(Point a, Point b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

bool cmpy(Point a, Point b){
	if(a.y != b.y) return a.y < b.y;
	return a.x < b.x;
}

inline long long dist2(Point a, Point b){
	long long dx = (long long)a.x - b.x;
	long long dy = (long long)a.y - b.y;
	return dx * dx + dy * dy;
}

long long guibing(int left, int right){
	if(left >= right){
		return (1LL << 62);
	}

	if(right - left <= 3){
		long long d = (1LL << 62);
		for(int i = left; i <= right; i++){
			for(int j = i + 1; j <= right; j++){
				d = min(d, dist2(p[i], p[j]));
			}
		}
		sort(p + left, p + right + 1, cmpy);
		return d;
	}

	int mid = (left + right) >> 1;
	int midx = p[mid].x;
	long long d = min(guibing(left, mid), guibing(mid + 1, right));

	merge(p + left, p + mid + 1, p + mid + 1, p + right + 1, tmp, cmpy);
	for(int i = left; i <= right; i++){
		p[i] = tmp[i - left];
	}

	int cnt = 0;
	for(int i = left; i <= right; i++){
		long long dx = (long long)p[i].x - midx;
		if(dx * dx < d){
			t2[cnt++] = p[i];
		}
	}

	for(int i = 0; i < cnt; i++){
		for(int j = i + 1; j < cnt; j++){
			long long dy = (long long)t2[j].y - t2[i].y;
			if(dy * dy >= d){
				break;
			}
			d = min(d, dist2(t2[i], t2[j]));
		}
	}

	return d;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
	}

	sort(p, p + n, cmpx);
	long long ans = guibing(0, n - 1);
	printf("%lld\n", ans);
}
