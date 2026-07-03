// P3391 【模板】文艺平衡树
/*
链接：https://www.luogu.com.cn/problem/P3391
知识点：隐式 Treap、区间翻转、懒标记
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
#include <random>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;

struct Node{
    int val;
    int pri;
    int sz;
    int rev;
    Node *l, *r;
};

Node pool[100005];
int poolcnt = 0;

Node* newNode(int v){
    Node* p = &pool[++poolcnt];
    p->val = v;
    p->pri = rand();
    p->sz = 1;
    p->rev = 0;
    p->l = p->r = NULL;
    return p;
}

int getSize(Node* p){
    return p ? p->sz : 0;
}

void pushup(Node* p){
    if(p) p->sz = getSize(p->l) + getSize(p->r) + 1;
}

void pushdown(Node* p){
    if(p && p->rev){
        swap(p->l, p->r);
        if(p->l) p->l->rev ^= 1;
        if(p->r) p->r->rev ^= 1;
        p->rev = 0;
    }
}

void split(Node* root, int k, Node*& left, Node*& right){
    if(!root){
        left = right = NULL;
        return;
    }
    pushdown(root);
    if(getSize(root->l) >= k){
        split(root->l, k, left, root->l);
        right = root;
        pushup(right);
    }else{
        split(root->r, k - getSize(root->l) - 1, root->r, right);
        left = root;
        pushup(left);
    }
}

Node* merge(Node* left, Node* right){
    if(!left || !right) return left ? left : right;
    if(left->pri > right->pri){
        pushdown(left);
        left->r = merge(left->r, right);
        pushup(left);
        return left;
    }else{
        pushdown(right);
        right->l = merge(left, right->l);
        pushup(right);
        return right;
    }
}

void reverseRange(Node*& root, int l, int r){
    Node *a, *b, *c;
    split(root, l - 1, a, b);
    split(b, r - l + 1, b, c);
    if(b) b->rev ^= 1;
    root = merge(a, merge(b, c));
}

void inorder(Node* p, vector<int>& res){
    if(!p) return;
    pushdown(p);
    inorder(p->l, res);
    res.push_back(p->val);
    inorder(p->r, res);
}

int main(){
    srand(19260817);
    int n, m;
    scanf("%d%d", &n, &m);
    Node* root = NULL;
    for(int i = 1; i <= n; i++){
        root = merge(root, newNode(i));
    }

    for(int i = 0; i < m; i++){
        int l, r;
        scanf("%d%d", &l, &r);
        reverseRange(root, l, r);
    }

    vector<int> ans;
    ans.reserve(n);
    inorder(root, ans);
    for(int i = 0; i < n; i++){
        if(i > 0) printf(" ");
        printf("%d", ans[i]);
    }
    printf("\n");
    return 0;
}
