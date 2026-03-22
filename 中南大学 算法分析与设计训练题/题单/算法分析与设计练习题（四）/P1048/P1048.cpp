#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>

using namespace std;

struct HERB{
    int time;
    int value;
};

int maxvalue[1010][110]; //最大总价值
HERB herbs[110];

int main(){
    int t, m;
    int time, value;
    memset(maxvalue, 0, sizeof(maxvalue));
    memset(herbs, 0, sizeof(herbs));

    scanf("%d%d", &t, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &(herbs[i].time), &(herbs[i].value));
    }

    sort(herbs, herbs + m, [](const HERB& a, const HERB& b){
        if(a.time != b.time){
            return a.time < b.time;
        }
        return a.value > b.value;
    });

    for(int i = 1; i <= t; i++){
        for(int j = 0; j < m; j++){
            time = herbs[j].time;
            value = herbs[j].value;
            if(i >= time){
                // 如果可以采
                if(j == 0){
                    // 如果是第一株药材
                    maxvalue[i][j] = value;
                }else{
                    maxvalue[i][j] = max(maxvalue[i][j-1], maxvalue[i - time][j-1] + value);
                }
            }else{
                maxvalue[i][j] = maxvalue[i][j-1];
            }
        }
    }

    printf("%d\n", maxvalue[t][m-1]);

}