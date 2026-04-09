#include <bits/stdc++.h>
using namespace std;

// 输入格式
// n l
// X1 X2 ... Xn

// RMQ (Range Minimum Query) — Sparse Table 实现
// 预处理：O(n log n)
// 查询：O(1) — 利用 ST[i][k] 表示以i为起点、长度为2^k的区间的最小值

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    if (!(cin >> n >> l)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    // ---- 预处理：构建稀疏表 ----
    int LOG = 0;
    while ((1 << LOG) <= n) ++LOG;
    vector<vector<int>> st(n, vector<int>(LOG));

    // 第一层：长度为1的区间，最小值就是元素本身
    for (int i = 0; i < n; ++i) st[i][0] = a[i];

    // 递推：长度为2^k的区间 = min(前2^{k-1}, 后2^{k-1})
    for (int k = 1; (1 << k) <= n; ++k) {
        for (int i = 0; i + (1 << k) <= n; ++i) {
            st[i][k] = min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
        }
    }

    // ---- 查询：返回区间[l, r]（0-indexed，含端点）的最小值 ----
    auto rmq = [&](int lq, int rq) -> int {
        int len = rq - lq + 1;
        int k = 0;
        while ((1 << (k + 1)) <= len) ++k;
        return min(st[lq][k], st[rq - (1 << k) + 1][k]);
    };

    // ---- 枚举所有长度为l的窗口，找波谷最大者 ----
    int bestPos = 1;
    int bestVal = a[0];

    for (int i = 0; i + l <= n; ++i) {
        int curMin = rmq(i, i + l - 1);
        if (curMin > bestVal) {
            bestVal = curMin;
            bestPos = i + 1; // 转为1-indexed
        }
    }

    cout << bestPos << "\n";
    return 0;
}
