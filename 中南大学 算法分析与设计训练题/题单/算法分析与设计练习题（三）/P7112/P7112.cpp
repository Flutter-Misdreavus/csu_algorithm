// P7112 【模板】行列式求值
/*
链接：https://www.luogu.com.cn/problem/P7112
知识点：行列式、高斯消元、辗转相除
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

long long a[605][605];

int main(){
    int n;
    long long p;
    scanf("%d%lld", &n, &p);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &a[i][j]);
            a[i][j] %= p;
            if(a[i][j] < 0) a[i][j] += p;
        }
    }

    bool neg = false;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(a[i][i] == 0 && a[j][i] != 0){
                for(int k = 0; k < n; k++){
                    swap(a[i][k], a[j][k]);
                }
                neg = !neg;
            }
            while(a[j][i] != 0){
                if(a[i][i] > a[j][i]){
                    for(int k = 0; k < n; k++){
                        swap(a[i][k], a[j][k]);
                    }
                    neg = !neg;
                }
                long long t = a[j][i] / a[i][i];
                for(int k = i; k < n; k++){
                    a[j][k] = (a[j][k] - (__int128)t * a[i][k] % p + p) % p;
                }
            }
        }
    }

    long long ans = 1 % p;
    for(int i = 0; i < n; i++){
        ans = ans * a[i][i] % p;
    }
    if(neg){
        ans = (p - ans) % p;
    }
    printf("%lld\n", ans);
    return 0;
}
