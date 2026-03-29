#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int mm = 10010, tt = 10000010;
long long int herbvalue[mm], herbtime[mm], dp[tt];

int main(){
    long long int t, m;
    long long int time, value;

    scanf("%lld%lld", &t, &m);
    for(int i = 0; i < m; i++){
        scanf("%lld%lld", &herbtime[i], &herbvalue[i]);
    }

    for(int i = 0; i < m; i++){
        time = herbtime[i];
        value = herbvalue[i];
        for(long long int j = time; j <= t; j++){
            dp[j] = max(dp[j - time] + value, dp[j]);
        }
    }

    printf("%lld\n", dp[t]);
}