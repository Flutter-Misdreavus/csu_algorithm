// 四种行列有序矩阵查找算法的性能实验

#include "search.h"
#include <iostream>
#include <chrono>
#include <random>
#include <functional>
#include <string>

// 生成 n×n 行列严格递增的矩阵
// 设计：mat[i][j] = i*n + j，行内步长 1，列内步长 n，无重复值
Matrix generateMatrix(int n) {
    Matrix mat(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            mat[i][j] = i * n + j;
    return mat;
}

// 测量某算法 repeats 次的平均耗时，并返回查找结果
template <typename Fn>
double timeOne(Fn fn, const Matrix& mat, int target, int repeats, bool& result) {
    using Clock = std::chrono::high_resolution_clock;
    auto t0 = Clock::now();
    bool found = false;
    for (int k = 0; k < repeats; ++k) {
        // volatile 避免被优化器删掉
        bool r = fn(mat, target);
        found = found || r;
    }
    auto t1 = Clock::now();
    result = found;
    double us = std::chrono::duration<double, std::micro>(t1 - t0).count();
    return us / repeats;
}

int main() {
    // CSV 表头
    std::cout << "n,scenario,algorithm,time_us\n";

    std::vector<int> sizes = {100, 500, 1000, 1500, 2000, 2500, 3000};

    // 算法清单
    struct Algo { std::string name; std::function<bool(const Matrix&, int)> fn; };
    std::vector<Algo> algos = {
        {"brute",  bruteForceSearch},
        {"rowBS",  rowBinarySearch},
        {"stair",  stairSearch},
        {"divide", divideConquerSearch},
    };

    for (int n : sizes) {
        Matrix mat = generateMatrix(n);

        // 四个测试场景：
        // best   - 右上角（阶梯法立即排除一行/列的最优情形）
        // middle - 中部
        // worst  - 左下角（阶梯法走完整 m+n 步）
        // miss   - 不存在
        struct Scenario { std::string name; int target; };
        std::vector<Scenario> scenarios = {
            {"best",   mat[0][n - 1]},
            {"middle", mat[n / 2][n / 2]},
            {"worst",  mat[n - 1][0]},
            {"miss",   mat[n - 1][n - 1] + 1},
        };

        // 重复次数：暴力法在大 n 下耗时极长，按规模分级
        // 其他算法快很多，需要更多重复以稳定计时
        for (const auto& sc : scenarios) {
            for (const auto& algo : algos) {
                int repeats;
                if (algo.name == "brute") {
                    // 暴力法：n 越大重复越少
                    if      (n <= 500)  repeats = 200;
                    else if (n <= 1500) repeats = 50;
                    else                repeats = 20;
                } else {
                    // 其他算法很快，尽量多重复
                    if      (n <= 500)  repeats = 20000;
                    else if (n <= 1500) repeats = 5000;
                    else                repeats = 2000;
                }

                bool result;
                double avg_us = timeOne(algo.fn, mat, sc.target, repeats, result);

                std::cout << n << ',' << sc.name << ',' << algo.name
                          << ',' << avg_us << '\n';

                std::cerr << "n=" << n << " " << sc.name
                          << " " << algo.name << " => "
                          << avg_us << " us  (found=" << result << ")\n";
            }
        }
    }

    return 0;
}
