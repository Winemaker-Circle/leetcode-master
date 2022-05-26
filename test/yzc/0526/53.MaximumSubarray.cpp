#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    // 找出数组中具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。

    // Solution1: 一次遍历法 O(n)
    static int maxSubArray(vector<int>& nums) {
        int max = nums[0]; // 记录上一阶段最大总和 （若有负数会减小）
        int sum = 0; // 记录当前总和
        for (int i = 0; i < nums.size(); ++i) {
           sum += nums[i]; // 累加
           sum = nums[i] > sum ? nums[i]:sum; // 遇到大于总和的值，则将总和改为该值
           max = max > sum ? max:sum; // 重置 max。该阶段的 sum 与 上一阶段 max 比较
        }
        return max;
    }
    // 一次遍历变体，使用 C++ 的 forEach方法来遍历
    static int maxSubArrayForEach(vector<int>& nums){
        int max = nums[0];
        int sum = 0;
        for (const auto &x:nums) {
            sum = std::max(sum+x,x);
            max = std::max(max,sum);
        }
        return max;
    }
    // Solution 2 : Dynamic Programming,DP
    // DP 5 step:
    // 1. 确定dp数组（dp table）以及下标的含义
    // 2. 确定递推公式
    // 3. dp数组如何初始化
    // 4. 确定遍历顺序
    // 5. 举例推导dp数组
    // TODO: 53.DP
    static int maxSubArrayDP(vector<int>& nums){

    }
};

int main(){
    vector<int> nums = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = Solution::maxSubArray(nums);
    cout << "[maxSubArraySum]: " << ans << endl;
    int ans1 = Solution::maxSubArrayForEach(nums);
    cout << "[maxSubArrayForEachSum]: " << ans1 << endl;

    return 0;
}