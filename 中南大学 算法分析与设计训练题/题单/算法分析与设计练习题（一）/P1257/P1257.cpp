#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
vector<pair<int, int>> points;

long int getdis(pair<int, int> a, pair<int, int> b){
	int x1 = a.first - b.first;
	int y1 = a.second - b.second;
	x1 *= x1;
	y1 *= y1;
	return x1 + y1; //先使用平方距离
}

bool cmpy(const pair<int, int>& a, const pair<int, int>& b){
	return a.second < b.second;
}

long int zuiduan(int left, int right){
	if(left == right){
		return 0XFFFFFFFFFFFFFFF;
	}

	if(left + 1 == right){
		return getdis(points[left], points[right]);
	}

	int mid = left + right;
	mid = mid >> 1;
	long int d;
	d = min(zuiduan(left, mid), zuiduan(mid, right));

	// 扫描
	vector<pair<int, int>> tmp;
	for(int i = left; i <= right; i++){
		long int ab = points[mid].first - points[i].first;
		ab *= ab; //当前点与中间点的x坐标之差的平方

		if(ab <= d){
			tmp.push_back({points[i].first, points[i].second});
		}
	}

	sort(tmp.begin(), tmp.end(), cmpy);

	for(int i = 0; i < tmp.size() - 1; i++){
		for(int j = i + 1; j < tmp.size() && j <= i + 6; j++){
			d = min(d, getdis(tmp[i], tmp[j]));
		}
	}

	return d;
}

int main(){
	int n;
	int x, y;
	double dis;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &x, &y);
		points.push_back({x, y});
	}
	sort(points.begin(), points.end());

	dis = sqrt(zuiduan(0, n - 1));
	printf("%.4lf\n", dis);
}
