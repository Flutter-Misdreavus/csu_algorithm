#include <bits/stdc++.h>
using namespace std;

// 输入格式
// n l
// X1 X2 ... Xn

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    if (!(cin >> n >> l)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    int bestPos = 1; // 1-indexed
    int bestVal = a[0]; // 波谷最大值初始化为第一个窗口的最小值

    // 枚举起始位置 i（0-indexed），对应输出 i+1
    for (int i = 0; i + l <= n; ++i) {
        int curMin = a[i];
        for (int j = 1; j < l; ++j) {
            curMin = min(curMin, a[i + j]);
        }
        if (curMin > bestVal) {
            bestVal = curMin;
            bestPos = i + 1; // 转为1-indexed
        }
    }

    cout << bestPos << "\n";
    return 0;
}
