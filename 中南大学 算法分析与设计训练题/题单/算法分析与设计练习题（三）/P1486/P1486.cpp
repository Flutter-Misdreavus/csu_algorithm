// P1486 [NOI2004] 郁闷的出纳员
/*
链接：https://www.luogu.com.cn/problem/P1486
知识点：平衡树、延迟全局偏移、第 k 大查询
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
using namespace __gnu_pbds;

typedef tree<pair<long long, int>, null_type, less<pair<long long, int>>, rb_tree_tag, tree_order_statistics_node_update> OrderSet;

OrderSet s;

int main(){
    int n;
    long long minv;
    scanf("%d%lld", &n, &minv);

    long long delta = 0;
    int left = 0;
    int id = 0;

    for(int i = 0; i < n; i++){
        char op[2];
        long long k;
        scanf("%s%lld", op, &k);
        if(op[0] == 'I'){
            if(k >= minv){
                s.insert({k - delta, ++id});
            }
        }else if(op[0] == 'A'){
            delta += k;
        }else if(op[0] == 'S'){
            delta -= k;
            long long threshold = minv - delta;
            auto it = s.lower_bound({threshold, 0});
            while(it != s.begin()){
                --it;
                s.erase(it++);
                left++;
            }
        }else if(op[0] == 'F'){
            int sz = (int)s.size();
            if(k > sz){
                printf("-1\n");
            }else{
                auto it = s.find_by_order(sz - k);
                printf("%lld\n", it->first + delta);
            }
        }
    }

    printf("%d\n", left);
    return 0;
}
