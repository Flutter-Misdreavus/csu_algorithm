#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <string>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

vector<int> nums;

int main(){
	int n;
	int a;

	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		nums.push_back(a);
	}

	sort(nums.begin(), nums.end());

	for(auto& it : nums){
		printf("%d ", it);
	}
	printf("\n");
}
