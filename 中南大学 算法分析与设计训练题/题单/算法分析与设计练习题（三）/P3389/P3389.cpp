// P3389 【模板】高斯消元法
/*
链接：https://www.luogu.com.cn/problem/P3389
知识点：高斯消元
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stack>
#include <string>
#include <queue>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

const double EPS = 1e-7;

double a[105][106];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <= n; j++){
            scanf("%lf", &a[i][j]);
        }
    }

    for(int i = 0; i < n; i++){
        int pivot = i;
        for(int r = i + 1; r < n; r++){
            if(fabs(a[r][i]) > fabs(a[pivot][i])){
                pivot = r;
            }
        }
        if(fabs(a[pivot][i]) < EPS){
            printf("No Solution\n");
            return 0;
        }
        if(pivot != i){
            for(int j = i; j <= n; j++){
                swap(a[i][j], a[pivot][j]);
            }
        }

        double div = a[i][i];
        for(int j = i; j <= n; j++){
            a[i][j] /= div;
        }

        for(int r = 0; r < n; r++){
            if(r == i) continue;
            double factor = a[r][i];
            if(fabs(factor) < EPS) continue;
            for(int j = i; j <= n; j++){
                a[r][j] -= factor * a[i][j];
            }
        }
    }

    for(int i = 0; i < n; i++){
        printf("%.2f\n", a[i][n]);
    }
    return 0;
}
