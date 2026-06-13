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

int happy[6003];
int dpjoin[6003];
int dpunjoin[6003];
vector<int> shangsi[6003];
bool youdie[6003];

void dfs(int dian){
	dpjoin[dian] = happy[dian];

	for(auto& i : shangsi[dian]){
		dfs(i);

		dpjoin[dian] += dpunjoin[i];
		dpunjoin[dian] += max(dpjoin[i], dpunjoin[i]);
	}
}

int main(){
	int n;
	int k, l;
	int root;
	memset(dpjoin, 0, sizeof(dpjoin));
	memset(dpunjoin, 0, sizeof(dpunjoin));

	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &happy[i]);
	}
	for(int i = 1; i< n; i++){
		scanf("%d%d", &k, &l);
		shangsi[l].push_back(k);
		youdie[k] = true;
	}
	for(int i = 1; i <= n; i++){
		if(!youdie[i]){
			root = i;
			break;
		}
	}

	dfs(root);

	printf("%d\n", max(dpjoin[root], dpunjoin[root]));
}
