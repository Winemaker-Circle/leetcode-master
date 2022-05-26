#include "iostream"
#include <vector>

using namespace std;

class BinarySearch{
public:
    // binary search 1:
    static int binarySearch1(vector<int>& nums,int target){
        int length = nums.size();
        int left = 0,right = length - 1;
        // 处理4种情况
        while (left <= right){ //[left,right]
            int middle = left + ((right - left)/2); // 防止溢出 等同于 (right-left)/2
            if (nums[middle] > target){ // 如果中值大于目标，说明目标在左边，右边没用，缩右区间
                right = middle -1; // 因为 [left,right]
            } else if (nums[middle] < target){ // 如果中值小于目标，说明目标在右边，左边没用，缩左区间
                left = middle + 1;
            } else{ // middle == target
                return middle;
            }
        }
        return -1; // 未找到目标
    }
    static int binarySearch2(vector<int>&nums,int target){
        int length = nums.size();
        int left = 0,right = length;
        while (left<right){  // [left,right) 因此当 left==right 时无意义 所以用 <
            int middle = left + ((right-left) >> 1); // 左移一位相当于乘二，右移一位相当于除二
            if (nums[middle]>target){
                right = middle;
            } else if (nums[middle] < target){
                left = middle + 1;
            } else{
                return middle;
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    int target = 2;
    int ans1 = BinarySearch::binarySearch1(nums,target);
    int ans2 = BinarySearch::binarySearch2(nums,target);
    cout << "binarySearch1 - ans1: " << ans1 << endl;
    cout << "binarySearch2 - ans2: " << ans2 << endl;
    return 0;
}