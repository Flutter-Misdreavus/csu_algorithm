// P2742 【模板】二维凸包 / [USACO5.1] 圈奶牛Fencing the Cows
/*
链接：https://www.luogu.com.cn/problem/P2742
知识点：凸包、Andrew 算法
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
	double x, y;
};

Point p[100005];
Point lower[100005], upper[100005];

bool cmp(Point a, Point b){
	if(a.x != b.x) return a.x < b.x;
	return a.y < b.y;
}

double cross(Point a, Point b, Point c){
	return (b.x - a.x) * (c.y - a.y) - (b.y - a.y) * (c.x - a.x);
}

double dist(Point a, Point b){
	double dx = a.x - b.x;
	double dy = a.y - b.y;
	return sqrt(dx * dx + dy * dy);
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%lf%lf", &p[i].x, &p[i].y);
	}

	sort(p, p + n, cmp);

	int lcnt = 0, ucnt = 0;
	for(int i = 0; i < n; i++){
		while(lcnt >= 2 && cross(lower[lcnt - 2], lower[lcnt - 1], p[i]) <= 0){
			lcnt--;
		}
		lower[lcnt++] = p[i];
	}
	for(int i = n - 1; i >= 0; i--){
		while(ucnt >= 2 && cross(upper[ucnt - 2], upper[ucnt - 1], p[i]) <= 0){
			ucnt--;
		}
		upper[ucnt++] = p[i];
	}

	// 去掉首尾重复的端点
	lcnt--;
	ucnt--;

	vector<Point> hull;
	for(int i = 0; i < lcnt; i++){
		hull.push_back(lower[i]);
	}
	for(int i = 0; i < ucnt; i++){
		hull.push_back(upper[i]);
	}

	double ans = 0;
	int m = hull.size();
	if(m == 2){
		ans = 2 * dist(hull[0], hull[1]);
	}else{
		for(int i = 0; i < m; i++){
			ans += dist(hull[i], hull[(i + 1) % m]);
		}
	}

	printf("%.2f\n", ans);
}
