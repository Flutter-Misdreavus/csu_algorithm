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
auto cmp = [](auto &a, auto &b){
        if(a.second == b.second){
            return a.first > b.first;
        }else{
            return a.second > b.second;
        }
    };
priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, decltype(cmp)> building(cmp);
auto cmp2 = [](auto &a, auto &b){
        return a.first < b.first;
    };
priority_queue<pair<long long int, long long int>, vector<pair<long long int, long long int>>, decltype(cmp2)> built(cmp2);

int main(){
    long long int n;
    long long int s = 0;
    long long int t1, t2;
    long long int time = 0;

    scanf("%lld", &n);
    for(long long int i = 0; i < n; i++){
        scanf("%lld%lld", &t1, &t2);
        building.push({t1, t2});
    }

    while(!building.empty()){
        t1 = building.top().first;
        t2 = building.top().second;
        building.pop();

        //prlong long intf("t1: %d, t2: %d\n", t1, t2);

        if(time + t1 <= t2){
            // 可以建造
            s++;
            time += t1;
            built.push({t1, t2});
        }else{
            // 不可以建造
            if(t1 < built.top().first){
                time -= built.top().first;
                time += t1;
                building.push(built.top());
                built.pop();
                built.push({t1, t2});
                
            }
        }
    }

    printf("%lld\n", s);
}
