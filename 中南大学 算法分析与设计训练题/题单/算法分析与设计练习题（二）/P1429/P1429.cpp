#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

struct Point
{
	int x;
	int y;
};

Point p[200005];
Point tmp[200005];

bool cmpx(Point a, Point b) {
    return a.x < b.x;
}
bool cmpy(Point a, Point b){
	return a.y < b.y;
}

double dist(Point a, Point b){
	long long int x = a.x - b.x;
	long long int y = a.y - b.y;
	x *= x;
	y *= y;
	return sqrt(x + y);
}

double guibing(int left, int right){
	if(left >= right){
		return 1e100;
	}

	double d = 1e100;
	if(right - left <= 3){
		for(int i = left; i < right; i++){
			for(int j = i + 1; j <= right; j++){
				d = min(d, dist(p[i], p[j]));
			}
		}
		sort(p + left, p + right + 1, cmpy);
		return d;
	}

	int mid = left + right;
	mid >>= 1;
	int midx = p[mid].x;
	d = min(guibing(left, mid), guibing(mid + 1, right));

	merge(p + left, p + mid + 1, p + mid + 1, p + right + 1, tmp, cmpy);
	for(int i = left; i <= right; i++){
		p[i] = tmp[i - left];
	}

	int count = 0;
	for(int i = left; i <= right; i++){
		if(fabs(midx - p[i].x) < d){
			tmp[count] = p[i];
			count++;
		}
	}

	for(int i = 0; i < count; i++){
		for(int j = i + 1; j < count; j++){
			if(tmp[j].y - tmp[i].y > d){
				break;
			}
			d = min(d, dist(tmp[i], tmp[j]));
		}
	}

	return d;
}

int main(){
	int n;
	double d;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &p[i].x, &p[i].y);
	}
	sort(p, p + n, cmpx);
	d = guibing(0, n - 1);
	printf("%.4lf\n", d);
}
