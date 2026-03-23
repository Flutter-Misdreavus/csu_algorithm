#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

int main(){
    int humen[1000];
    memset(humen, 0, sizeof(humen));
    int n, m;
    int a;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &a);
        humen[a] += 1;
    }

    for(int i = 1; i <= n; i++){
        a = humen[i];
        for(int j = 0; j < a; j++){
            printf("%d ", i);
        }
    }
    printf("\n");
}