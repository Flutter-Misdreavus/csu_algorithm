#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <iterator>

using namespace std;

int main(){
    multiset<int> m;
    int op;
    int n;
    int x;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &op);
        scanf("%d", &x);
        if(op == 1){
            m.insert(x);
        }else if(op == 2){
            // 使用迭代器，只删除一个
            auto it = m.find(x);
            if(it != m.end()){
                m.erase(it);
            }
        }else if(op == 3){
            auto it = m.lower_bound(x);
            printf("%d\n", (int)distance(m.begin(), it) + 1);
        }else if(op == 4){
            auto it = m.begin();
            for(int i = 1; i < x; i++){
                it++;
            }
            printf("%d\n", *it);
        }else if(op == 5){
            printf("%d\n", *(--m.lower_bound(x)));
        }else if(op == 6){
            printf("%d\n", *(m.upper_bound(x)));
        }

        // printf("\n");
        // for(auto it = m.begin(); it != m.end(); it++){
        //     printf("%d ", *it);
        // }
        // printf("\n");
    }
}