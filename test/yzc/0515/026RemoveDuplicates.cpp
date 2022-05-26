#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:

    // 去重后，返回新长度
    static int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[j] != nums[i]){ // i j 不相等
                nums[++j] = nums[i]; // j ++
            }
        }
        return j + 1;
    }
};

int main(){
    vector<int> nums = {1,1,2,7,11,15};
    int result = Solution::removeDuplicates(nums);
    cout << result << endl;
    for (int i = 0; i < result; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}