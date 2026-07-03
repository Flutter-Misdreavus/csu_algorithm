// P3390 【模板】矩阵快速幂
/*
链接：https://www.luogu.com.cn/problem/P3390
知识点：矩阵快速幂、矩阵乘法
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

struct Matrix{
    long long a[105][105];
    int n;
};

Matrix multiply(const Matrix& x, const Matrix& y){
    Matrix res;
    res.n = x.n;
    for(int i = 0; i < x.n; i++){
        for(int j = 0; j < x.n; j++){
            res.a[i][j] = 0;
        }
    }
    for(int i = 0; i < x.n; i++){
        for(int k = 0; k < x.n; k++){
            if(x.a[i][k] == 0) continue;
            for(int j = 0; j < x.n; j++){
                res.a[i][j] = (res.a[i][j] + x.a[i][k] * y.a[k][j]) % MOD;
            }
        }
    }
    return res;
}

Matrix fastpow(Matrix base, long long exp){
    Matrix res;
    res.n = base.n;
    for(int i = 0; i < base.n; i++){
        for(int j = 0; j < base.n; j++){
            res.a[i][j] = (i == j) ? 1 : 0;
        }
    }
    while(exp > 0){
        if(exp & 1) res = multiply(res, base);
        base = multiply(base, base);
        exp >>= 1;
    }
    return res;
}

int main(){
    int n;
    long long k;
    scanf("%d%lld", &n, &k);
    Matrix A;
    A.n = n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &A.a[i][j]);
            A.a[i][j] %= MOD;
            if(A.a[i][j] < 0) A.a[i][j] += MOD;
        }
    }

    Matrix ans = fastpow(A, k);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(j > 0) printf(" ");
            printf("%lld", ans.a[i][j]);
        }
        printf("\n");
    }
    return 0;
}
