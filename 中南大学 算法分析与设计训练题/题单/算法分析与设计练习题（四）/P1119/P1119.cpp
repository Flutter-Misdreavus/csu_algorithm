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

int n, m, Q;
int tim[210];
int dis[210][210];
const int INF = 0x3f3f3f3f;

int main(){
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &tim[i]);
	}
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 0; i < n; i++){
		dis[i][i] = 0;
	}
	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		dis[u][v] = w;
		dis[v][u] = w;
	}

	int k = 0;
	scanf("%d", &Q);
	for(int q = 0; q < Q; q++){
		int x, y, t;
		scanf("%d%d%d", &x, &y, &t);
		while(k < n && tim[k] <= t){
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(dis[i][k] + dis[k][j] < dis[i][j]){
						dis[i][j] = dis[i][k] + dis[k][j];
					}
				}
			}
			k++;
		}
		if(tim[x] > t || tim[y] > t){
			printf("-1\n");
		}else if(dis[x][y] == INF){
			printf("-1\n");
		}else{
			printf("%d\n", dis[x][y]);
		}
	}
}
