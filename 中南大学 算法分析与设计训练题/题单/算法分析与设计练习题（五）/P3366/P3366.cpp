#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

int bingchaji[5010];
vector<pair<pair<int, int>, int>> bian; //起点 终点 长度

void add_bing(int a, int b){
    // 将a,b合并到一个并查集里
    int s = bingchaji[b];

    while(s != bingchaji[s]){
        s = bingchaji[s];
    }

    bingchaji[s] = a;

    return;
}

int is_bing(int a, int b){
    int s1 = bingchaji[a];
    int s2 = bingchaji[b];

    while (s1 != bingchaji[s1]){
        s1 = bingchaji[s1];
    }
    while(s2 != bingchaji[s2]){
        s2 = bingchaji[s2];
    }

    bingchaji[a] = s1;
    bingchaji[b] = s2;

    if(s1 == s2){
        return 1;
    }else{
        return 0;
    }
    
    return 0;
}

int main(){
    int n, m;
    int a, b ,c;
    int chang = 0;

    scanf("%d%d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d%d%d", &a, &b, &c);
        bian.push_back({{a, b}, c});
    }
    for(int i = 1; i <= n; i++){
        bingchaji[i] = i;
    }

    sort(bian.begin(), bian.end(), [](auto &a, auto &b){
        return a.second < b.second;
    });


    int flag = 0; //已经选取的边的数量，小于等于n-1
    for(auto it = bian.begin(); it != bian.end() && flag < n; it++){
        a = (*it).first.first;
        b = (*it).first.second;
        c = (*it).second;

        if(!is_bing(a, b)){
            flag++;
            chang += c;
            add_bing(a, b);
        }
    }

    if(flag == n - 1){
        printf("%d\n", chang);
    }else{
        printf("orz\n");
    }
}