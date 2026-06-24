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

int gift[30004];

int main(){
	int n, w;
	int left, right;
	int zu = 0;

	scanf("%d", &w);
	scanf("%d", &n);
	for(int i = 0; i < n; i++){
		scanf("%d", &gift[i]);
	}

	left = 0;
	right = n - 1;
	sort(gift, gift + n);

	while(left < right){
		if(gift[left] + gift[right] > w){
			right--;
			zu++;
		}else{
			left++;
			right--;
			zu++;
		}
	}

	if(left == right){
		zu++;
		// 最后一组
	}

	printf("%d\n", zu);
}
