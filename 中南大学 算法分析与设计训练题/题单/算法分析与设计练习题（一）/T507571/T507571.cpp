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

int color[100010];

int shua(int cl, int k, int n){
	int ci = 0;
	int su = 0;

	while(su < n){
		if(color[su] == cl){
			su++;
			continue;
		}

		su += k;
		ci++;
	}

	return ci;
}

int main(){
	int t;
	int n, k;
	int clorn; //颜色种类数
	int ci; //刷的次数

	scanf("%d", &t);
	for(int i = 0; i < t; i++){
		ci = 0X7FFFFFFF;
		clorn = 0;
		scanf("%d%d", &n, &k);
		for(int j = 0; j < n; j++){
			scanf("%d", &color[j]);
			clorn = max(clorn, color[j]);
		}
		for(int j = 1; j <= clorn; j++){
			ci = min(ci, shua(j, k, n));
		}

		printf("%d\n", ci);
	}
}
