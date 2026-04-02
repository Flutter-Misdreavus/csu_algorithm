#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

int dp[2010][2010];
char a[2010];
char b[2010];

int main(){
    int a_size, b_size;
    memset(dp, 0, sizeof(dp));

    scanf("%s", a);
    scanf("%s", b);

    a_size = strlen(a);
    b_size = strlen(b);

    for(int i = 0; i <= a_size; i++){
        dp[i][0] = i;
    }
    for(int j = 0; j <= b_size; j++){
        dp[0][j] = j;
    }

    for(int i = 1; i <= a_size; i++){
        for(int j = 1; j <= b_size; j++){
            if(a[i - 1] == b[j - 1]){
                // 不用修改
                dp[i][j] = dp[i - 1][j - 1];
            }else{
                dp[i][j] = min(min(dp[i][j - 1] + 1, dp[i - 1][j] + 1), dp[i - 1][j - 1] + 1);
                // dp[i][j - 1] + 1：在a中插入一个字符
                // dp[i - 1][j] + 1：在a中删除一个
                // dp[i - 1][j - 1] + 1：在a中修改一个字符
            }
        }
    }

    // for(int i = 0; i <= a_size; i++){
    //     for(int j = 0; j <= b_size; j++){
    //         printf("%d ", dp[i][j]);
    //     }
    //     printf("\n");
    // }

    printf("%d\n", dp[a_size][b_size]);
}