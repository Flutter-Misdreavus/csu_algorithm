// P3370 【模板】字符串哈希
/*
链接：https://www.luogu.com.cn/problem/P3370
知识点：字符串哈希、滚动哈希
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

unsigned long long getHash(const char* s){
    unsigned long long h = 0;
    while(*s){
        h = h * 131 + (unsigned long long)(*s);
        s++;
    }
    return h;
}

int main(){
    int n;
    scanf("%d", &n);
    unordered_set<unsigned long long> st;
    char str[2005];
    for(int i = 0; i < n; i++){
        scanf("%s", str);
        st.insert(getHash(str));
    }
    printf("%lu\n", st.size());
    return 0;
}
