// P2580 于是他错误的点名开始了
/*
链接：https://www.luogu.com.cn/problem/P2580
知识点：哈希表、字符串查找
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

unordered_set<string> names;
unordered_set<string> called;

int main(){
    int n, m;
    char s[55];
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%s", s);
        names.insert(s);
    }
    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%s", s);
        if(names.find(s) == names.end()){
            printf("WRONG\n");
        }else if(called.find(s) != called.end()){
            printf("REPEAT\n");
        }else{
            printf("OK\n");
            called.insert(s);
        }
    }
    return 0;
}
