#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

bool used[10];
vector<int> nums;

void dfs(int n, int us){
	if(n == us){
		for(auto& it : nums){
			printf("%5d", it);
		}
		printf("\n");
		return;
	}

	for(int i = 1; i <= n; i++){
		if(!used[i]){
			nums.push_back(i);
			used[i] = true;
			dfs(n, us + 1);
			used[i] = false;
			nums.pop_back();
		}
	}

	return;
}

int main(){
	int n;
	scanf("%d", &n);
	memset(used, 0, sizeof(used));

	dfs(n, 0);
}
