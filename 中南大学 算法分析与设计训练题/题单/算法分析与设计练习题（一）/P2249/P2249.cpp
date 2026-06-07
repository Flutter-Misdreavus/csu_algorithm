#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>


using namespace std;

int nums[1000010];
vector<int> numv;

int find_bi(int x, int n){
	int left = 0, right = n;
	int mid;

	while(left <= right){
		mid = left + right;
		mid = mid >> 1;

		if(nums[mid] >= x){
			right = mid - 1;
			continue;
		}
		if(nums[mid] < x){
			left = mid + 1;
			continue;
		}

		int flag = mid - 1;
		while(flag >= 0){
			if(nums[flag] == x){
				flag--;
			}else{
				return flag + 2;
			}
		}
		return flag + 2;
	}

	return -1;
}

int main(){
	int n, m;
	int x;

	scanf("%d%d", &n, &m);
	// for(int i = 0; i < n; i++){
	// 	scanf("%d", &nums[i]);
	// }
	// for(int i = 0; i < m; i++){
	// 	scanf("%d", &x);
	// 	printf("%d ", find_bi(x, n));
	// }
	// printf("\n");

	for(int i = 0; i < n; i++){
		scanf("%d", &x);
		numv.push_back(x);
	}
	for(int i = 0; i < m; i++){
		scanf("%d", &x);
		auto it = lower_bound(numv.begin(), numv.end(), x);
		if(it != numv.end() && *it == x){
			x = it - numv.begin() + 1;
			printf("%d ", x);
		}else{
			printf("-1 ");
		}
	}
	printf("\n");
}
