#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

struct NODE {
    long long w;
    int id;          // 叶子编号，非叶子 = -1
    NODE *l, *r;
};

struct CMP {
    bool operator()(NODE* a, NODE* b) const {
        return a->w > b->w; // 小根堆
    }
};

priority_queue<NODE*, vector<NODE*>, CMP> pq;

int n;
char s[1005][25];
char ans[1005][2005];

// 创建节点
NODE* newNode(long long w, int id, NODE* l, NODE* r) {
    NODE* p = new NODE();
    p->w = w;
    p->id = id;
    p->l = l;
    p->r = r;
    return p;
}

// DFS生成编码
void dfs(NODE* root, char path[], int depth) {
    if (!root) return;

    // 叶子节点
    if (!root->l && !root->r) {
        path[depth] = '\0';
        strcpy(ans[root->id], path);
        return;
    }

    path[depth] = '0';
    dfs(root->l, path, depth + 1);

    path[depth] = '1';
    dfs(root->r, path, depth + 1);
}

int main() {
    scanf("%d", &n);

    // ⭐ 特判 n = 1（必须）
    if (n == 1) {
        long long w;
        scanf("%s %lld", s[0], &w);
        printf("%s 0\n", s[0]);
        return 0;
    }

    // 读入 + 建叶子节点
    for (int i = 0; i < n; i++) {
        long long w;
        scanf("%s %lld", s[i], &w);
        pq.push(newNode(w, i, NULL, NULL));
    }

    // Huffman建树
    while (pq.size() > 1) {
        NODE* a = pq.top(); pq.pop();
        NODE* b = pq.top(); pq.pop();

        pq.push(newNode(a->w + b->w, -1, a, b));
    }

    NODE* root = pq.top();

    char path[2005];
    dfs(root, path, 0);

    // 按输入顺序输出
    for (int i = 0; i < n; i++) {
        printf("%s %s\n", s[i], ans[i]);
    }

    return 0;
}
