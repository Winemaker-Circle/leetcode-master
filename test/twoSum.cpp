#include "iostream"
#include "vector"
#include <unordered_map>

using namespace std;

class Solution {
public:
    static vector<int> twoSumForce(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums.size(); ++j) {
                if (nums[i] + nums[j] == target){
                    return vector<int>({i,j});
                }
            }:w
        }
        return {};
    }
    static vector<int> twoSumMap(vector<int>& nums, int target) {
        unordered_map<int, int> map; // 这个 Map 用于缓存数据， 其 key 为数组的值，value 为数组的索引

        for (int i = 0; i < nums.size(); i++) {
            int another = target - nums[i];
            if (map.count(another)){ // 判断是否有该 key
                // 有的话直接返回这个 key 的 value 和 i
                int target_index = map[another];
                return {target_index,i};
            }
            // 没有的话缓存这个值，key为值，value 为数组索引
            map[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    vector<int> nums = {2,7,11,15};
    int target = 9; // [0,1]
    // 暴力破解 O(n^2)
    vector<int> result0 = Solution::twoSumForce(nums, target);
    cout << "[" << result0[0] << "," << result0[1] << "]" << endl;

    // 使用 Map 进行优化 O(n)
    vector<int> result1 = Solution::twoSumMap(nums, target);
    cout << "[" << result1[0] << "," << result1[1] << "]" << endl;
    return 0;
}



