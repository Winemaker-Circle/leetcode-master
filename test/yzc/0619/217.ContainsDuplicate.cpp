#include "vector"
#include "unordered_set"
#include "iostream"

using namespace std;

//# 传送门：[217. Contains Duplicate](https://leetcode.cn/problems/contains-duplicate/)
//---

class Solution {
public:
    // 哈希表 (哈希表的另一种妙用)
    // 将数组中元素依次放入哈希表(set 集合)，如果过程中发现重复 则表示存在重复元素 反之
    static bool containsDuplicateSet(vector<int> &nums) {
        unordered_set<int> set;
        for (int x: nums) {
            if (set.find(x) != set.end()) {
                return true;
            }
            set.insert(x);
        }
        return false;
    }

    // 排序
    // 排序后判断是否存在重复
    static bool containsDuplicateSort(vector<int> &nums) {
        quickSort(nums,0,nums.size());
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == nums[i+1]) return true;
        }
        return false;
    }

    // 快排
    static void quickSort(vector<int> nums, int left, int right) {
        if (left >= right) {
            return;
        }
        int target = nums[left];
        int i = left, j = right;
        while (i < j) {
            //每次先移动j,右指针
            while (i < j && nums[j] >= target) {
                j--;
            }
            while (i < j && nums[i] <= target) {
                i++;
            }
            swap(nums, i, j);
        }
        swap(nums, i, left);
        quickSort(nums, left, i - 1);
        quickSort(nums, i + 1, right);
    }

    static void swap(vector<int> nums, int left, int right) {
        int temp = nums[left];
        nums[left] = nums[right];
        nums[right] = temp;
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 1};
    vector<int> nums2 = {1, 2, 3, 4};

    cout << Solution::containsDuplicateSet(nums1) << endl;
    cout << Solution::containsDuplicateSet(nums2) << endl;
    //
    cout << "==" << endl;
    cout << Solution::containsDuplicateSort(nums1) << endl;
    cout << Solution::containsDuplicateSort(nums2) << endl;

    return 0;
}