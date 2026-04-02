#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int ditu[110][110];
int smalltree[110];

int find_small(int n){
    int dp = 0;
    int min = 0x7FFFFFFF;

    for(int i = 0; i<n; i++){
        if(smalltree[i] == 0){
            continue;
        }
        if(smalltree[i] < min){
            min = smalltree[i];
            dp = i;
        }
    }

    return dp;
}

int main(){
    memset(smalltree, 0x7F, sizeof(smalltree));

    int n;
    int chang = 0;
    int nextpo;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &ditu[i][j]);
        }
    }
    for(int i = 0; i<n; i++){
        smalltree[i] = ditu[0][i];
    }

    for(int j = 1; j < n; j++){
        nextpo = find_small(n);
        chang += smalltree[nextpo];
        smalltree[nextpo] = 0;
        for(int i = 0; i < n; i++){
            if(smalltree[i] > ditu[nextpo][i]){
                smalltree[i] = ditu[nextpo][i];
            }
        }    
    }


    printf("%d\n", chang);
    
}