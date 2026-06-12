#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int dp[2005][2005];
char buff[2005];
string a, b;

int main(){
	int al, bl;
	memset(dp, 0, sizeof(dp));

	scanf("%s", buff);
	a = buff;
	scanf("%s", buff);
	b = buff;

	al = a.size();
	bl = b.size();

	for(int i = 0; i <= al; i++){
		dp[i][0] = i;
	}
	for(int j = 0; j <= bl; j++){
		dp[0][j] = j;
	}

	for(int i = 1; i <= al; i++){
		for(int j = 1; j <= bl; j++){
			if(a[i - 1] == b[j - 1]){
				dp[i][j] = dp[i - 1][j - 1];
			}else{
				dp[i][j] = min(min(dp[i - 1][j - 1], dp[i - 1][j]), dp[i][j - 1]) + 1;
			}
		}
	}

	printf("%d\n", dp[al][bl]);
}
