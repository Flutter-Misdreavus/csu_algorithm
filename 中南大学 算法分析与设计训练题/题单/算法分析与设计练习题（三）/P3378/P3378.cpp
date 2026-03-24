#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> xiaogendui; // 创建一个小根堆
    int n;
    int op;
    int x;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &op);
        if(op == 1){
            scanf("%d", &x);
            xiaogendui.push(x);
        }else if(op == 2){
            printf("%d\n", xiaogendui.top());
        }else{
            xiaogendui.pop();
        }
    }
}