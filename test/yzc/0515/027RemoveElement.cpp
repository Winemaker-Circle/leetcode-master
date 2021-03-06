#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static int removeElement(vector<int>& nums, int val) {
        unsigned long long size = nums.size();
//        O(n^2)
        for (int i = 0; i < size; i++) {
            if (nums[i] == val) { // 将后面的所有元素向前移动
                for (int j = i + 1; j < size; j++) {
                    nums[j - 1] = nums[j];
                }
                i--;
                size--;
            }
        }
        return size;
    }
    static int removeElementDoublePoint(vector<int>& nums, int val) {
        // 声明两个指针，快慢指针
        // 非目标值，同时前进，并将快指针赋值给慢指针
        // 是目标值的话，慢指针保持原位，快指针前进
        // 直到下一个非目标值，将快指针赋值给慢指针（此时快指针指向的是目标元素的下一个）
        int slowIndex = 0;
        for (int fastIndex = 0; fastIndex < nums.size(); fastIndex++) {
            if (val != nums[fastIndex]) {
                nums[slowIndex] = nums[fastIndex];
                slowIndex++;
            }
        }
        return slowIndex;
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 7;
    // 暴力破解 O(n^2)
    Solution::removeElement(nums,target);

    Solution::removeElementDoublePoint(nums,target);


    return 0;
}