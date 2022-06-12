#include <unordered_map>
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    // 哈希表
    static int singleNumber(vector<int>& nums) {
        unordered_map<int, int> freq;
        for (int num: nums) {
            ++freq[num];
        }
        int ans = 0;
        for (auto [num, occ]: freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
    // 利用二进制位进行判断
    static int singleNumber01(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; ++i) {
            int total = 0;
            for (int num: nums) {
                total += ((num >> i) & 1);
            }
            if (total % 3) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
};

int main(){
    vector<int> nums = {2,2,3,2};
    int ans = Solution::singleNumber(nums);
    cout << ans;

    return 0;
}