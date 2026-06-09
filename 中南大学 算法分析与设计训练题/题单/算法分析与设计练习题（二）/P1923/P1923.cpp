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

priority_queue<int, vector<int>, greater<int>> pd;

int main(){
	int n, k;
	int x;
	scanf("%d%d", &n, &k);
	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		pd.push(x);
	}

	for(int i = 0; i < k; i++){
		pd.pop();
	}

	printf("%d\n", pd.top());
}
