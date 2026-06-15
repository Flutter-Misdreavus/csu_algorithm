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

int bingchaji[5005];
vector<pair<int, pair<int, int>>> bian;

void init_bi(int n){
	for(int i = 1; i <= n; i++){
		bingchaji[i] = i;
	}
}

int find_bi(int a){
	if(a == bingchaji[a]){
		return a;
	}
	return find_bi(bingchaji[a]);
}

void merge_bi(int a, int b){
	a = find_bi(a);
	b = find_bi(b);
	bingchaji[b] = a;
	return;
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
	int n, m;
	int a, b, c;
	int ge = 0;
	int he = 0;

	scanf("%d%d", &n, &m);
	for(int i = 0; i < m; i++){
		scanf("%d%d%d", &a, &b, &c);
		bian.push_back({c, {a, b}});
	}

	init_bi(n);
	sort(bian.begin(), bian.end());

	for(auto& it : bian){
		c = it.first;
		a = it.second.first;
		b = it.second.second;

		if(is_bi(a, b)){
			continue;
		}

		he += c;
		ge++;
		merge_bi(a, b);
	}

	if(ge == n - 1){
		printf("%d\n", he);
	}else{
		printf("orz\n");
	}

}
