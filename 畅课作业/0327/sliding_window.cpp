#include <bits/stdc++.h>
using namespace std;

// 输入格式
// n l
// X1 X2 ... Xn

// 单调队列：维护窗口内最小值的下标
// 队列中下标对应的值在窗口内保持单调递增
// 队头始终是当前窗口最小值的下标

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, l;
    if (!(cin >> n >> l)) return 0;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) cin >> a[i];

    deque<int> q; // 存放下标，保证a[q.front()]是当前窗口最小值

    int bestPos = 1;
    int bestVal = a[0];

    for (int i = 0; i < n; ++i) {
        while (!q.empty() && a[q.back()] >= a[i]) {
            q.pop_back();
        }
        q.push_back(i);

        while (!q.empty() && q.front() < i - l + 1) {
            q.pop_front();
        }

        if (i >= l - 1) {
            int curMin = a[q.front()];
            int startPos = i - l + 1 + 1; // 起始位置，1-indexed
            if (curMin > bestVal) {
                bestVal = curMin;
                bestPos = startPos;
            }
        }
    }

    cout << bestPos << "\n";
    return 0;
}
