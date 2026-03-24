#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main(){
    priority_queue<int, vector<int>, greater<int>> guozidui;
    int n;
    int ene = 0;
    int guo;

    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &guo);
        guozidui.push(guo);
    }

    while(guozidui.size() != 1){
        guo = guozidui.top();
        guozidui.pop();
        guo += guozidui.top();
        guozidui.pop();

        ene += guo;
        guozidui.push(guo);
    }

    printf("%d\n", ene);
}