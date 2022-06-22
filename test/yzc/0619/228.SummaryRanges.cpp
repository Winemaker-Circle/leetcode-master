#include <string>
#include <iostream>
#include "vector"

using namespace std;

//# 传送门：[228.Summary Ranges](https://leetcode.cn/problems/summary-ranges/)
//---
// 其实就是找到连续的分区

class Solution {
public:

    static vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        if(nums.empty()) return result;
        int start = nums[0];
        for(int i = 0; i < nums.size(); i++) {
            // 连续
            if(i != nums.size() - 1 && nums[i] + 1 == nums[i+1]) { //
                continue;
            }
            // 不连续
            if(nums[i] != start) {
                result.push_back((to_string(start) + "->" + to_string(nums[i])));
            } else {
                result.push_back(to_string(start));
            }
            // 不是最后元素才重置a
            if(i != nums.size() - 1) {
                start = nums[i + 1];
            }
        }
        return result;
    }
    static vector<string> summaryRangesyy(vector<int>& nums) {
        vector<string> ans;
        int n = nums.size();
        if (n==0) return ans;
        int a = nums[0];
        for (int i = 0; i < n; ++i) {
            if (i==n-1 || nums[i]+1 != nums[i+1]){
                if (nums[i] !=a) ans.push_back(to_string(a) + "->" + to_string(nums[i]));
                else ans.push_back(to_string(a));
                if (i != n-1) a = nums[i+1];
            }
        }
        return ans;
    }

    static vector<string> summaryRangesRecall(vector<int>& nums) {
        vector<string> ans;
        int start = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (i != nums.size()-1 && nums[i] == nums[i-1]+1){ // 连续 判断下一个元素是否符合预期
                continue;
            } else{ // 不连续
                // 只有一个元素
                if (nums[i-1] == start && nums[i]!=start+1) {
                    ans.push_back(to_string(start));
                } else{
                    string temp = to_string(start);
                    temp.append("->");
                    temp.append(to_string(nums[i-1]));
                    ans.push_back(temp);
                }
                start = nums[i]; //重置 start
            }
        }
        return ans;
    }
    static vector<string> summaryRangesOld(vector<int>& nums) {
        vector<string> ans;
        int start = nums[0];
        for (int i = 0; i < nums.size(); ++i) {
            if (i<nums.size()-1 && nums[i+1] == nums[i]+1){ // 连续 判断下一个元素是否符合预期
                continue;
            } else{ // 不连续
                // 只有一个元素
                if (nums[i] == start) {
                    ans.push_back(to_string(nums[i]));
                } else{
                    string temp = to_string(start);
                    temp.append("->");
                    temp.append(to_string(nums[i]));
                    ans.push_back(temp);
                }
                if (i<nums.size()-1)start = nums[i+1]; //重置 start
            }
        }
        return ans;
    }
};

int main(){
//    vector<int> nums = {0,1,2,4,5,7};
    vector<int> nums = {0,2,3,4,6,8,9};
    vector<string> ans = Solution::summaryRangesOld(nums);
    cout << "[";
    for (auto & an : ans) {
        cout << "'" << an << "',";
    }
    cout << "]";
    return 0;
}