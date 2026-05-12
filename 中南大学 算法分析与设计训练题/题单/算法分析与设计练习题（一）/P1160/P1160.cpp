#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <list>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
#include <map>
#include <set>

using namespace std;

int right[100010];
int left[100010];
int del[100010];
// 使用数组模拟双向链表

int main(){
    int n;
    int m;
    int k, p;
    int x;
    int head = 1; //记录第一个数

    memset(del, 0 ,sizeof(del));
    scanf("%d", &n);
    right[1] = 0;
    left[1] = 0;
    right[0] = 0;
    left[0] = 0;
    // 0代表到尽头了

    for(int i = 2; i <= n; i++){
        scanf("%d%d", &k, &p);
        if(p == 0){
            right[left[k]] = i;
            left[i] = left[k];
            left[k] = i;
            right[i] = k;

            if(k == head){
                head = i;
            }
        }else{
            left[right[k]] = i;
            right[i] = right[k];
            right[k] = i;
            left[i] = k;
        }
    }

    scanf("%d", &m);
    for(int i = 0; i < m; i++){
        scanf("%d", &x);
        del[x] = 1;
    }

    while (head != 0){
        if(!del[head]){
            printf("%d ", head);
        }
        head = right[head];
    }
    printf("\n");

}