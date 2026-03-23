#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <stack>
#include <queue>

int gcd(int a, int b){
    if(b == 0){
        return a;
    }

    return gcd(b, a % b);
}

int main(){
    int x, y;
    int n = 0;
    int p, q;
    int top;

    scanf("%d%d", &x, &y);
    if (x == y){
        // 当x和y相等时，只有一个数n满足条件，即n = x。
        printf("1\n");
        return 0;
    }

    top = x * y;
    p = x;
    q = y;
    for(int i = 1; p <= q; i++){
        p = x * i;
        if(top % p != 0){
            // 如果p不是因数
            continue;
        }

        if(p == q){
            // 因数是对称的，当p等于q时，代表已经找了一半，直接将n乘2就可以了。
            break;
        }

        q = top / p;
        if(gcd(p, q) == x){
            n++;
        }
    }

    n = n << 1;

    printf("%d\n", n);
}