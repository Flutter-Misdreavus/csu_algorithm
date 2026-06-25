// P13956 [ICPC 2023 Nanjing R] 等价重写
/*
链接：https://www.luogu.com.cn/problem/P13956
知识点：拓扑排序、构造
*/
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

int lastx[100005];

int main(){
	int T;
	scanf("%d", &T);

	while(T--){
		int n, m;
		scanf("%d%d", &n, &m);

		vector<vector<int> > caozuo(n + 1);
		for(int i = 1; i <= m; i++){
			lastx[i] = 0;
		}

		for(int i = 1; i <= n; i++){
			int p;
			scanf("%d", &p);
			caozuo[i].resize(p);
			for(int j = 0; j < p; j++){
				scanf("%d", &caozuo[i][j]);
				lastx[caozuo[i][j]] = i;
			}
		}

		int pos = -1;
		for(int i = 1; i < n; i++){
			bool you = false;
			for(int j = 0; j < (int)caozuo[i].size(); j++){
				if(lastx[caozuo[i][j]] == i + 1){
					you = true;
					break;
				}
			}
			if(!you){
				pos = i;
				break;
			}
		}

		if(pos == -1){
			printf("No\n");
			continue;
		}

		printf("Yes\n");
		for(int i = 1; i <= n; i++){
			int x;
			if(i == pos){
				x = pos + 1;
			}else if(i == pos + 1){
				x = pos;
			}else{
				x = i;
			}
			printf("%d", x);
			if(i != n){
				printf(" ");
			}
		}
		printf("\n");
	}
}
