#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <vector>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

vector<int> maxpos;
vector<vector<int>> bian;

void dfs(int kaishi, int hai){
	for(auto it = bian[kaishi].begin(); it != bian[kaishi].end(); it++){
		if(maxpos[*it] == 0){
			maxpos[*it] = hai;
			dfs(*it, hai);
		}
	}
}

int main(){
	int n, m;
	int a, b;

	scanf("%d%d", &n, &m);
	maxpos.resize(n + 1, 0);
	bian.resize(n + 1);

	for(int i = 1; i <= m; i++){
		scanf("%d%d", &a, &b);
		bian[b].push_back(a);
	}

	for(int i = n; i != 0; i--){
		if(maxpos[i] == 0){
			maxpos[i] = i;
			dfs(i, i);
		}

		// for(auto it = ((maxpos.begin())++); it != maxpos.end(); it++){
		// 	printf("%d ", (*it));
		// }
		// printf("\n");
	}

	for(auto it = (maxpos.begin()); it != maxpos.end(); it++){
		if(it == maxpos.begin()){
			continue;
		}
		printf("%d ", (*it));
	}
	printf("\n");

}
