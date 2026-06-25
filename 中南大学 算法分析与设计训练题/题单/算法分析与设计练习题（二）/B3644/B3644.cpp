// B3644 【模板】拓扑排序 / 家谱树
/*
链接：https://www.luogu.com.cn/problem/B3644
知识点：拓扑排序、Kahn 算法
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

vector<int> bian[105];
int rudu[105];

int main(){
	int n;
	int x;

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		while(scanf("%d", &x) && x != 0){
			bian[i].push_back(x);
			rudu[x]++;
		}
	}

	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(rudu[i] == 0){
			q.push(i);
		}
	}

	vector<int> ans;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		ans.push_back(u);

		for(auto &v : bian[u]){
			rudu[v]--;
			if(rudu[v] == 0){
				q.push(v);
			}
		}
	}

	for(int i = 0; i < ans.size(); i++){
		printf("%d", ans[i]);
		if(i != ans.size() - 1){
			printf(" ");
		}
	}
	printf("\n");
}
