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

int n, m;
int dis[110][110];
const int INF = 0x3f3f3f3f;

int main(){
	scanf("%d%d", &n, &m);
	memset(dis, 0x3f, sizeof(dis));
	for(int i = 1; i <= n; i++){
		dis[i][i] = 0;
	}

	for(int i = 0; i < m; i++){
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		if(w < dis[u][v]){
			dis[u][v] = w;
			dis[v][u] = w;
		}
	}

	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				if(dis[i][k] + dis[k][j] < dis[i][j]){
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			printf("%d ", dis[i][j]);
		}
		printf("\n");
	}
}
