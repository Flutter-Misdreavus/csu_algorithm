#ifndef SEARCH_H
#define SEARCH_H

#include <vector>
#include <algorithm>

using Matrix = std::vector<std::vector<int>>;

// 暴力遍历  O(m*n)
inline bool bruteForceSearch(const Matrix& mat, int target) {
    int m = (int)mat.size();
    if (m == 0) return false;
    int n = (int)mat[0].size();
    for (int i = 0; i < m; ++i)
        for (int j = 0; j < n; ++j)
            if (mat[i][j] == target) return true;
    return false;
}

// 逐行二分查找  O(m*log n)
inline bool rowBinarySearch(const Matrix& mat, int target) {
    int m = (int)mat.size();
    if (m == 0) return false;
    int n = (int)mat[0].size();
    for (int i = 0; i < m; ++i) {
        // 行内剪枝：target 不在 [mat[i][0], mat[i][n-1]] 范围内可跳过
        if (target < mat[i][0] || target > mat[i][n-1]) continue;
        auto it = std::lower_bound(mat[i].begin(), mat[i].end(), target);
        if (it != mat[i].end() && *it == target) return true;
    }
    return false;
}

// 阶梯查找  O(m+n)
inline bool stairSearch(const Matrix& mat, int target) {
    int m = (int)mat.size();
    if (m == 0) return false;
    int n = (int)mat[0].size();
    int i = 0, j = n - 1;
    while (i < m && j >= 0) {
        if (mat[i][j] == target) return true;
        if (mat[i][j] > target) --j;   // 排除整列
        else                   ++i;    // 排除整行
    }
    return false;
}

// 分治四分搜索  O(N^log_4(3))
inline bool divideConquerSearchImpl(const Matrix& mat, int target,
                                    int r1, int r2, int c1, int c2) {
    if (r1 > r2 || c1 > c2) return false;
    if (target < mat[r1][c1] || target > mat[r2][c2]) return false;  // 区间剪枝

    int mid_r = (r1 + r2) / 2;
    int mid_c = (c1 + c2) / 2;

    if (mat[mid_r][mid_c] == target) return true;

    if (mat[mid_r][mid_c] > target) {
        // 排除右下象限
        return divideConquerSearchImpl(mat, target, r1, mid_r - 1, c1, mid_c - 1) ||
               divideConquerSearchImpl(mat, target, r1, mid_r - 1, mid_c, c2) ||
               divideConquerSearchImpl(mat, target, mid_r, r2, c1, mid_c - 1);
    } else {
        // 排除左上象限
        return divideConquerSearchImpl(mat, target, r1, mid_r, mid_c + 1, c2) ||
               divideConquerSearchImpl(mat, target, mid_r + 1, r2, c1, mid_c) ||
               divideConquerSearchImpl(mat, target, mid_r + 1, r2, mid_c + 1, c2);
    }
}

inline bool divideConquerSearch(const Matrix& mat, int target) {
    int m = (int)mat.size();
    if (m == 0) return false;
    int n = (int)mat[0].size();
    return divideConquerSearchImpl(mat, target, 0, m - 1, 0, n - 1);
}

#endif
