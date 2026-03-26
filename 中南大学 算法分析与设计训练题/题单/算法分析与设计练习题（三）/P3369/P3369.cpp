#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;
using Pinghengshu = tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update>; //定义类型别名

int main(){
    Pinghengshu m;
    int x, n, op;
    int id = 0; // 为了区分重复元素，给每一个元素一个id

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d%d", &op, &x);
        if(op == 1){
            id++;
            m.insert({x, id});
        }else if(op == 2){
            auto it = m.lower_bound({x, 0});
            m.erase(it);
        }else if(op == 3){
            auto it = m.lower_bound({x, 0});
            printf("%d\n", (int)(m.order_of_key(*it) + 1));
        }else if(op == 4){
            printf("%d\n", (*(m.find_by_order(x - 1))).first);
        }else if(op == 5){
            printf("%d\n", (*(--m.lower_bound({x, 0}))).first);
        }else if(op == 6){
            printf("%d\n", (*(m.upper_bound({x, 99999}))).first);
        }

        // printf("\n");
        // for(auto it = m.begin(); it != m.end(); it++){
        //     printf("%d ", (*it).first);
        // }
        // printf("\n");
    }
}