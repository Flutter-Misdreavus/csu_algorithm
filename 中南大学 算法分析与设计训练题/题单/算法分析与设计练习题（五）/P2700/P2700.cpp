#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int bingchaji[100010];
int zhan[100010]; //被占领的城市，1表示被占领

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

void memge(int a, int b){
    if(zhan[find(a)] || zhan[find(b)]){
        zhan[find(a)] = 1;
        zhan[find(b)] = 1;
    }
    bingchaji[find(a)] = find(b);
}

void show(int n){
    printf("\nbc: ");
    for(int i = 0; i < n; i++){
        printf("%d ", bingchaji[i]);
    }
    printf("\nzhan: ");
    for(int i = 0; i < n; i++){
        printf("%d ", zhan[i]);
    }
    printf("\n");
}

vector<pair<pair<int, int>, int>> bian;

int main(){
    int n, k;
    int city;
    int a, b, c;
    long long int daijiao = 0;
    memset(zhan, 0, sizeof(zhan));

    scanf("%d%d", &n, &k);
    for(int i = 0; i < k; i++){
        scanf("%d", &city);
        zhan[city] = 1;
        //printf("%d\n", city);
    }
    for(int i = 0; i < n - 1; i++){
        scanf("%d%d%d", &a, &b, &c);
        bian.push_back({{a, b}, c});
    }

    sort(bian.begin(), bian.end(), [](auto &a, auto &b){
        return a.second > b.second;
    });

    // for(auto it = bian.begin(); it != bian.end(); it++){
    //     printf("%d %d %d\n", (*it).first.first, (*it).first.second, (*it).second);
    // }

    init(n);

    //int flag = 1;
    for(auto it = bian.begin(); it != bian.end(); it++){
        a = (*it).first.first;
        b = (*it).first.second;
        c = (*it).second;

        // if(zhan[a] && zhan[b] && find(a) == find(b)){
        //     continue;

        // }

        if(find(a) == find(b)){
            daijiao += c;
            continue;
            // 如果两个城市已经在同一个集合中，则不需要合并
        }

        if(zhan[find(a)] && zhan[find(b)]){
            daijiao += c;
            continue;
            // 如果两个城市都被占领，则不能合并
        }

        memge(a, b);
        //flag++;
        //show(n);
    }

    printf("%lld\n", daijiao);
}
