#include <bits/stdc++.h>
using namespace std;

// 策略：二分查找
// 旋转后的数组可分成两个升序段，前段所有元素 >= 后段所有元素
// 旋转点 k 即最小元素的下标
// 比较 nums[mid] 与 nums[right]：
//   - nums[mid] > nums[right]：最小值在右半，left = mid + 1
//   - nums[mid] < nums[right]：最小值在左半（含 mid），right = mid
//   - 相等时：right--（处理重复元素）
// 时间复杂度 O(log n)，空间复杂度 O(1)

int findRotatePoint(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return -1;
    if (n == 1) return 0;

    int left = 0, right = n - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else {
            right--;
        }
    }
    return left;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;
    vector<int> nums(n);
    for (int i = 0; i < n; ++i) {
        cin >> nums[i];
    }

    int k = findRotatePoint(nums);
    cout << k << endl;

    return 0;
}
