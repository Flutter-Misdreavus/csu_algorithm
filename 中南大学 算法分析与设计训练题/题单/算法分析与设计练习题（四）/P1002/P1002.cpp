#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

long long int ditu[22][22];

bool ismakong(int mx, int my, int x, int y){
	if(mx == x && my == y){
		return true;
	}
	if(mx - 2 == x && my - 1 == y){
		return true;
	}
	if(mx - 2 == x && my + 1 == y){
		return true;
	}
	if(mx + 2 == x && my - 1 == y){
		return true;
	}
	if(mx + 2 == x && my + 1 == y){
		return true;
	}
	if(mx - 1 == x && my - 2 == y){
		return true;
	}
	if(mx - 1 == x && my + 2 == y){
		return true;
	}
	if(mx + 1 == x && my - 2 == y){
		return true;
	}
	if(mx + 1 == x && my + 2 == y){
		return true;
	}
	return false;
}

int main(){
	int n, m;
	int mx, my;

	scanf("%d%d", &n, &m);
	scanf("%d%d", &mx, &my);
	memset(ditu, 0 ,sizeof(ditu));

	ditu[0][0] = 1;
	for(int i = 1; i <= n; i++){
		if(ismakong(mx, my, i, 0)){
			continue;
		}
		ditu[i][0] = ditu[i - 1][0];
	}
	for(int j = 1; j <= m; j++){
		if(ismakong(mx, my, 0, j)){
			continue;
		}
		ditu[0][j] = ditu[0][j - 1];
	}
	// for(int i = 0; i <= n; i++){
	// 	for(int j = 0; j <= m; j++){
	// 		printf("%d ", ditu[i][j]);
	// 	}
	// 	printf("\n");
	// }
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= m; j++){
			if(ismakong(mx, my, i, j)){
			continue;
			}
			ditu[i][j] = ditu[i - 1][j] + ditu[i][j - 1];
		}
	}

	// for(int i = 0; i <= n; i++){
	// 	for(int j = 0; j <= m; j++){
	// 		printf("%d ", ditu[i][j]);
	// 	}
	// 	printf("\n");
	// }

	printf("%lld\n", ditu[n][m]);
}
