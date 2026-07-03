// P1226 【模板】快速幂
/*
链接：https://www.luogu.com.cn/problem/P1226
知识点：快速幂、模运算
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

long long fastpow(long long a, long long b, long long p){
    long long res = 1 % p;
    a %= p;
    while(b > 0){
        if(b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}

int main(){
    long long a, b, p;
    scanf("%lld%lld%lld", &a, &b, &p);
    long long ans = fastpow(a, b, p);
    printf("%lld^%lld mod %lld=%lld\n", a, b, p, ans);
    return 0;
}
