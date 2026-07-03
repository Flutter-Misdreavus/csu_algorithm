// P11615 【模板】哈希表
/*
链接：https://www.luogu.com.cn/problem/P11615
知识点：哈希表、快速读入、自然溢出
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
#include <unordered_set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

static char buf[1 << 23], *p1 = buf, *p2 = buf;

inline char gc(){
    if(p1 == p2){
        p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin);
        if(p1 == p2) return EOF;
    }
    return *p1++;
}

inline unsigned long long rd(){
    unsigned long long x = 0;
    char ch = gc();
    while(!isdigit(ch)) ch = gc();
    while(isdigit(ch)){
        x = x * 10 + (unsigned long long)(ch ^ 48);
        ch = gc();
    }
    return x;
}

const int SZ = 1 << 23;

unsigned long long keys[SZ];
unsigned long long vals[SZ];
char occ[SZ];

inline unsigned long long splitmix64(unsigned long long x){
    x += 0x9e3779b97f4a7c15ULL;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
    x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
    return x ^ (x >> 31);
}

int main(){
    int n = (int)rd();
    unsigned long long ans = 0;
    const int mask = SZ - 1;

    for(int i = 1; i <= n; i++){
        unsigned long long x = rd();
        unsigned long long y = rd();
        unsigned long long h = splitmix64(x);
        int idx = (int)(h & mask);
        while(occ[idx] && keys[idx] != x){
            idx = (idx + 1) & mask;
        }
        unsigned long long cur = occ[idx] ? vals[idx] : 0;
        ans += (unsigned long long)i * cur;
        keys[idx] = x;
        vals[idx] = y;
        occ[idx] = 1;
    }

    printf("%llu\n", ans);
    return 0;
}
