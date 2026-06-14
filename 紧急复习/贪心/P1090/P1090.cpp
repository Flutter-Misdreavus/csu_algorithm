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

priority_queue<int, vector<int>, greater<int>> guozi;

int main(){
	int n;
	int ene = 0;
	int apple;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &apple);
		guozi.push(apple);
	}

	for(int i = 1; i < n; i++){
		apple = guozi.top();
		guozi.pop();
		apple += guozi.top();
		guozi.pop();
		ene += apple;
		guozi.push(apple);
	}

	printf("%d\n", ene);
}
