#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int menu[110][2010];

int dp1[110][110]; //不考虑列限制的dp, 最多能做n个菜 dp1[前i行][选了j个菜]
int dp2[110][110][110]; //不合法的 dp2[前i行][第j列][在第j列选了k个菜][在其他列选了s个菜] 不合法即 k > s

int main(){
    int n, m;
    int sum; //每一行的总数
    int illegal = 0;
    int cai;

    scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        sum = 0;
        for(int j = 1; j <= m; j ++){
            scanf("%d", &menu[i][j]);
            sum += menu[i][j];
        }
        menu[i][0] = sum;
    }

    for(int i = 0; i <= n; i++){
        dp1[i][0] = 1;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= i; j++){
            dp1[i][j] = dp1[i - 1][j] + dp1[i - 1][j - 1] * menu[i][0];
            printf("%d ", dp1[i][j]);
        }
        printf("\n");
    }

    for(int j = 1; j <= m; j++){
        printf("%d\n", j);
        for(int i = 0; i <= n; i++){
            printf("{\n");
            for(int k = 0; k <= i; k++){
                printf("[");
                for(int s = 0; s <= i; s++){
                    if(s + k > i){
                        break;
                    }

                    if(k == 0 && s == 0){
                        dp2[i][k][s] = 1;
                        printf("%d ", dp2[i][k][s]);
                        continue;
                    }

                    if(k == 0){
                        dp2[i][k][s] = dp2[i - 1][k][s] + dp2[i - 1][k][s - 1] * (menu[i][0] - menu[i][j]);
                    }else if(s == 0){
                        dp2[i][k][s] = dp2[i - 1][k][s] + dp2[i - 1][k - 1][s] * menu[i][j];
                    }else{
                        dp2[i][k][s] = dp2[i - 1][k][s] + dp2[i - 1][k - 1][s] * menu[i][j] + dp2[i - 1][k][s - 1] * (menu[i][0] - menu[i][j]);
                    }
                    printf("%d ", dp2[i][k][s]);
                }
                printf("]\n");
            }
            printf("}\n\n");
        }
        printf("\n\n");

        for(int k = 0; k <= n; k++){
            for(int s = 0; s <= n; s++){
                if (s + k > n){
                    break;
                }

                if(k > s){
                    // 不合法
                    illegal += dp2[n][s][k];
                }
            }
        }
    }

    cai = dp1[n][n] - illegal;
    printf("%d\n", cai);
}