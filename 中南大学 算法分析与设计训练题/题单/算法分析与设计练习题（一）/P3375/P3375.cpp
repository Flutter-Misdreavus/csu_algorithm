#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;

const int MAXN = 1000005;
char s1[MAXN], s2[MAXN];
int nxt[MAXN];

int main() {
    scanf("%s%s", s1, s2);
    int n = strlen(s1), m = strlen(s2);

    nxt[0] = nxt[1] = 0;
    for (int i = 1, j = 0; i < m; i++) {
        while (j > 0 && s2[i] != s2[j]) j = nxt[j];
        if (s2[i] == s2[j]) j++;
        nxt[i + 1] = j;  
    }

    for (int i = 0, j = 0; i < n; i++) {
        while (j > 0 && s1[i] != s2[j]) j = nxt[j];
        if (s1[i] == s2[j]) j++;
        if (j == m) {
            printf("%d\n", i - m + 2);  
            j = nxt[j];  // 继续匹配下一个
        }
    }

    for (int i = 1; i <= m; i++) {
        printf("%d%c", nxt[i], i == m ? '\n' : ' ');
    }

    return 0;
}