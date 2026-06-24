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

char buff[205];
string x, y;
int dp[205][205];

int main(){
	int xl, yl;
	memset(dp, 0, sizeof(dp));

	scanf("%s", buff);
	x = buff;
	scanf("%s", buff);
	y = buff;
	xl = x.size();
	yl = y.size();

	for(int i = 1; i <= xl; i++){
		for(int j = 1; j <= yl; j++){
			if(x[i - 1] == y[j - 1]){
				dp[i][j] = dp[i - 1][j - 1] + 1;
			}else{
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
			}
		}
	}

	printf("%d\n", dp[xl][yl]);
}
