#include "search.h"
#include <iostream>
#include <random>
#include <iomanip>

// 生成 n×n 双向严格递增的有序矩阵
Matrix generateMatrix(int n, std::mt19937& rng) {
    Matrix mat(n, std::vector<int>(n));
    std::uniform_int_distribution<int> dist(1, 5);

    mat[0][0] = dist(rng);
    for (int j = 1; j < n; ++j) mat[0][j] = mat[0][j - 1] + dist(rng);
    for (int i = 1; i < n; ++i) mat[i][0] = mat[i - 1][0] + dist(rng);
    for (int i = 1; i < n; ++i)
        for (int j = 1; j < n; ++j)
            mat[i][j] = std::max(mat[i - 1][j], mat[i][j - 1]) + dist(rng);
    return mat;
}

// 随机抽 k 个矩阵中的元素 + k 个不存在的元素，逐一检验四种算法的一致性
bool consistencyCheck(const Matrix& mat, int trials, std::mt19937& rng) {
    int m = (int)mat.size(), n = (int)mat[0].size();
    std::uniform_int_distribution<int> rowDist(0, m - 1), colDist(0, n - 1);

    int maxVal = mat[m - 1][n - 1];
    int minVal = mat[0][0];

    for (int t = 0; t < trials; ++t) {
        // 一半测试存在的目标，一半测试不存在的
        int target;
        if (t & 1) target = mat[rowDist(rng)][colDist(rng)];
        else       target = maxVal + 1 + (t / 2);  // 一定不存在

        bool r1 = bruteForceSearch(mat, target);
        bool r2 = rowBinarySearch(mat, target);
        bool r3 = stairSearch(mat, target);
        bool r4 = divideConquerSearch(mat, target);

        if (!(r1 == r2 && r2 == r3 && r3 == r4)) {
            std::cerr << "FAIL: target=" << target
                      << " brute=" << r1 << " rowBS=" << r2
                      << " stair=" << r3 << " divide=" << r4 << '\n';
            return false;
        }
    }
    (void)minVal;
    return true;
}

int main() {
    std::mt19937 rng(42);

    // 多种规模都跑一下
    int sizes[] = {1, 2, 5, 10, 50, 100, 300};
    bool allPass = true;
    for (int n : sizes) {
        Matrix mat = generateMatrix(n, rng);
        bool ok = consistencyCheck(mat, 200, rng);
        std::cout << "n = " << std::setw(4) << n
                  << "  ->  " << (ok ? "PASS" : "FAIL") << '\n';
        if (!ok) allPass = false;
    }

    std::cout << "\n" << (allPass ? "All consistency checks PASSED."
                                   : "Some checks FAILED!") << '\n';
    return allPass ? 0 : 1;
}
