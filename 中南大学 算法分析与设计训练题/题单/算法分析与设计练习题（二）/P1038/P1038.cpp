// P1038 [NOIP 2003 提高组] 神经网络
/*
链接：https://www.luogu.com.cn/problem/P1038
知识点：拓扑排序、模拟
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

struct EDGE{
	int to;
	int w;
};

vector<EDGE> bian[105];
int rudu[105];
int chudu[105];
int zhuangtai[105];
int yuzhi[105];
int jia[105]; // 累加来自前驱的贡献
bool shuru[105]; // 是否为输入层

int main(){
	int n, p;
	int a, b, c;

	scanf("%d%d", &n, &p);
	for(int i = 1; i <= n; i++){
		scanf("%d%d", &zhuangtai[i], &yuzhi[i]);
	}

	for(int i = 0; i < p; i++){
		scanf("%d%d%d", &a, &b, &c);
		bian[a].push_back({b, c});
		rudu[b]++;
		chudu[a]++;
	}

	queue<int> q;
	for(int i = 1; i <= n; i++){
		if(rudu[i] == 0){
			shuru[i] = true;
			q.push(i);
		}
	}

	vector<int> topo;
	while(!q.empty()){
		int u = q.front();
		q.pop();
		topo.push_back(u);

		for(auto &e : bian[u]){
			rudu[e.to]--;
			if(rudu[e.to] == 0){
				q.push(e.to);
			}
		}
	}

	for(auto &u : topo){
		if(!shuru[u]){
			// 非输入层节点，状态由前驱贡献与阈值决定
			zhuangtai[u] = jia[u] - yuzhi[u];
		}

		if(zhuangtai[u] > 0){
			for(auto &e : bian[u]){
				jia[e.to] += e.w * zhuangtai[u];
			}
		}
	}

	bool you = false;
	for(int i = 1; i <= n; i++){
		if(chudu[i] == 0 && zhuangtai[i] > 0){
			printf("%d %d\n", i, zhuangtai[i]);
			you = true;
		}
	}

	if(!you){
		printf("NULL\n");
	}
}
