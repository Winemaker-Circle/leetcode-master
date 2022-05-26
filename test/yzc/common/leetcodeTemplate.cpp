#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static vector<int> twoSumForce(vector<int>& nums, int target) {
        return {};
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9; // [0,1]
    // 暴力破解 O(n^2)
    vector<int> result0 = Solution::twoSumForce(nums, target);
    cout << "[" << result0[0] << "," << result0[1] << "]" << endl;

    return 0;
}