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

int bingchaji[100005];
bool enemy[100005]; // enemy[i]只判断以i为根的集合是否有敌军
vector<pair<int, pair<int, int>>> bian;

int find_bi(int a){
	if(a == bingchaji[a]){
		return a;
	}else{
		return bingchaji[a] = find_bi(bingchaji[a]);
	}
}

void merge_bi(int a, int b){
	a = find_bi(a);
	b = find_bi(b);

	bingchaji[b] = a;
	if(enemy[b]){
		enemy[a] = true;
	}
}

int main(){
	int n, k;
	int a, b, c;
	int ene;
	long int daijia = 0;
	long int zong = 0;

	memset(enemy, 0, sizeof(enemy));

	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		bingchaji[i] = i;
	}
	for(int i = 0; i < k; i++){
		scanf("%d", &ene);
		enemy[ene] = true;
	}
	for(int i = 0; i < n - 1; i++){
		scanf("%d%d%d", &a, &b, &c);
		bian.push_back({c, {a, b}});
		zong += c;
	}

	sort(bian.begin(), bian.end(), greater<pair<int, pair<int, int>>>());

	for(auto& it : bian){
		c = it.first;
		a = it.second.first;
		b = it.second.second;

		if(find_bi(a) != find_bi(b) && enemy[find_bi(a)] == true && enemy[find_bi(b)] == true){
			// 如果两个点不在同一集合且都有敌军，则不能合并
			continue;
		}else{
			merge_bi(a, b);
			daijia += c;
		}
	}

	daijia = zong - daijia;
	printf("%ld\n", daijia);
}
