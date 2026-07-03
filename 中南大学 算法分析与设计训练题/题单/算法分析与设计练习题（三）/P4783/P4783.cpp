// P4783 【模板】矩阵求逆
/*
链接：https://www.luogu.com.cn/problem/P4783
知识点：矩阵求逆、高斯-约当消元、模意义下逆元
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

const long long MOD = 1000000007LL;

long long a[405][805];

long long fastpow(long long base, long long exp){
    long long res = 1;
    base %= MOD;
    while(exp > 0){
        if(exp &1) res = res * base % MOD;
        base = base * base % MOD;
        exp >>= 1;
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &a[i][j]);
            a[i][j] %= MOD;
        }
        a[i][n + i] = 1;
    }

    for(int i = 0; i < n; i++){
        int pivot = -1;
        for(int r = i; r < n; r++){
            if(a[r][i] != 0){
                pivot = r;
                break;
            }
        }
        if(pivot == -1){
            printf("No Solution\n");
            return 0;
        }
        if(pivot != i){
            for(int j = 0; j < 2 * n; j++){
                swap(a[i][j], a[pivot][j]);
            }
        }

        long long inv = fastpow(a[i][i], MOD - 2);
        for(int j = 0; j < 2 * n; j++){
            a[i][j] = a[i][j] * inv % MOD;
        }

        for(int r = 0; r < n; r++){
            if(r == i) continue;
            long long factor = a[r][i];
            if(factor == 0) continue;
            for(int j = 0; j < 2 * n; j++){
                a[r][j] = (a[r][j] - factor * a[i][j] % MOD + MOD) % MOD;
            }
        }
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > 0) printf(" ");
            printf("%lld", a[i][n + j]);
        }
        printf("\n");
    }
    return 0;
}
