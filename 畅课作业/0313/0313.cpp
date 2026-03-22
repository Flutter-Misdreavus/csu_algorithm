#include <iostream>
#include <vector>
using namespace std;

int ternarySearch(const vector<int>& arr, int target) {
    int left = 0;
    int right = (int)arr.size() - 1;

    while (left <= right) {
        // 计算两个分割点
        int m1 = left + (right - left) / 3;
        int m2 = right - (right - left) / 3;

        // 找到目标值
        if (arr[m1] == target) return m1;
        if (arr[m2] == target) return m2;

        // 目标值在左侧区间
        if (target < arr[m1]) {
            right = m1 - 1;
        }
        // 目标值在右侧区间
        else if (target > arr[m2]) {
            left = m2 + 1;
        }
        // 目标值在中间区间
        else {
            left = m1 + 1;
            right = m2 - 1;
        }
    }

    return -1;  // 未找到
}

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};

    int target = 11;
    int result = ternarySearch(arr, target);

    if (result != -1) {
        cout << "元素 " << target << " 在索引 " << result << " 处找到" << endl;
    } else {
        cout << "元素 " << target << " 未找到" << endl;
    }

    return 0;
}
