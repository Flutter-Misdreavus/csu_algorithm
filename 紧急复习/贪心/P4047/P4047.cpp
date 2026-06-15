#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <string>
#include <stack>
#include <queue>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int bingchaji[1005];
int xy[2][1005];
vector<pair<long int, pair<int, int>>> bian;

void init_bi(int n){
	for(int i = 0; i < n; i++){
		bingchaji[i] = i;
	}
}

int find_bi(int a){
	if(a == bingchaji[a]){
		return a;
	}

	return (bingchaji[a] = find_bi(bingchaji[a]));
}

void merge_bi(int a, int b){
	a = find_bi(a);
	b = find_bi(b);
	bingchaji[b] = a;
}

bool is_bi(int a, int b){
	a = find_bi(a);
	b = find_bi(b);
	if(a == b){
		return true;
	}
	return false;
}

int main(){
	int n, k;
	int x, y;
	int a, b;
	long int c;
	long int dis2;
	double dis;
	int ge = 0;

	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d%d", &xy[0][i], &xy[1][i]);
		for(int j = 0; j < i; j++){
			x = xy[0][i] - xy[0][j];
			y = xy[1][i] - xy[1][j];
			x *= x;
			y *= y;
			dis2 = x + y;
			bian.push_back({dis2, {i, j}});
		}
	}

	init_bi(n);
	sort(bian.begin(), bian.end());

	for(auto& it : bian){
		a = it.second.first;
		b = it.second.second;
		c = it.first;

		if(is_bi(a, b)){
			continue;
		}

		if(ge == n - k){
			dis = sqrt(c);
			printf("%.2f\n", dis);
			break;
		}

		ge++;
		merge_bi(a, b);
	}
}
