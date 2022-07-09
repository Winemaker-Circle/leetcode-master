#include <iostream>
#include <set>
#include "vector"

using namespace std;
class Solution {
public:
    static int findMaxConsecutiveOnes(vector<int>& nums) {
        int maxCount = 0, count = 0; // 最大连续和当前连续
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
            } else {
                maxCount = max(maxCount, count); // 发生中断 比较最大连续
                count = 0; // 重置当前连续
            }
        }
        maxCount = max(maxCount, count);
        return maxCount;
    }
};

int main(){
    vector<int> nums = {1,1,0,1,1,1};
    int ans = Solution::findMaxConsecutiveOnes(nums);
    cout << ans;
    return 0;
}