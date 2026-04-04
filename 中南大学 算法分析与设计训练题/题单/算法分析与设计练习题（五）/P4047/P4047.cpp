#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int bingchaji[1010];
double dist[1010][1010];
int px[1010];
int py[1010];

void init(int n){
    for(int i = 0; i < n; i++){
        bingchaji[i] = i;
    }
}

int find(int a){
    int s = bingchaji[a];
    while(s != bingchaji[s]){
        s = bingchaji[s];
    }

    bingchaji[a] = s;
    return s;
}

void memgre(int a, int b){
    bingchaji[b] = find(a);
}

void find_min(int n, int* a, int* b){
    // 找到距离最近的两个部落
    double mind = 10e6;

        for(int i = 0; i < n; i++){
            if(find(i) != i){
                continue;
            }
            for(int j = 0; j < n; j++){
                if(dist[i][j] == 0){
                    continue;
                }
                if(dist[i][j] == 1){
                    // 距离最短就是1
                    *a = i;
                    *b = j;
                    return;
                }
                if(dist[i][j] < mind){
                    mind = dist[i][j];
                    *a = i;
                    *b = j;
                }
            }
        }

    return;
}

double find_min(int n){
    double mind = 10e6;

        for(int i = 0; i < n; i++){
            if(find(i) != i){
                continue;
            }
            for(int j = 0; j < n; j++){
                if(dist[i][j] == 0){
                    continue;
                }
                if(dist[i][j] == 1){
                    // 距离最短就是1
                    return 1;
                }
                if(dist[i][j] < mind){
                    mind = dist[i][j];
                }
            }
        }

    return mind;
}

void memgre_buluo(int n){
    // 合并两个部落
    int a, b;
    find_min(n, &a, &b);

    memgre(a, b);
    for(int i = 0; i < n ; i++){
        if(dist[a][i] > dist[b][i]){
            dist[a][i] = dist[b][i];
            dist[i][a] = dist[a][i];      
        }
    }
}

void show(int n){
    printf("\nbc: ");
    for(int i = 0; i < n; i++){
        printf("%d ", bingchaji[i]);
    }
    printf("\n");
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%lf ", dist[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main(){
    int n, k;

    scanf("%d%d", &n, &k);
    for(int i = 0; i < n; i ++){
        scanf("%d%d", &px[i], &py[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            dist[i][j] = hypot(px[i] - px[j], py[i] - py[j]); // 计算i到j的距离
        }
    }

   init(n);
    for(int i = 0 ; i < n - k; i++){
        memgre_buluo(n);
        //show(n);
    }

    printf("%.2lf\n", find_min(n));
 
}