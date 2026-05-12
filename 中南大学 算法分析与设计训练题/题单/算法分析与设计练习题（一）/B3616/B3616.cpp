#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

queue<int> num;

int main(){
    int op;
    int x;
    int n;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &op);

        if(op == 1){
            scanf("%d", &x);
            num.push(x);
        }else if(op == 2){
            if(num.empty()){
                printf("ERR_CANNOT_POP\n");
                continue;
            }
            num.pop();
        }else if(op == 3){
            if(num.empty()){
                printf("ERR_CANNOT_QUERY\n");
                continue;
            }
            printf("%d\n", num.front());
        }else{
            printf("%d\n", num.size());
        }

    }


}