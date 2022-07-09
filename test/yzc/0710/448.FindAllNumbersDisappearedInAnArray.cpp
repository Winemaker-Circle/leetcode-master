#include <iostream>
#include <set>
#include "vector"

using namespace std;

//# 传送门：[448.FindAllNumbersDisappearedInAnArray](https://leetcode.cn/problems/find-all-numbers-disappeared-in-an-array/)
//---
// 给你一个含 n 个整数的数组 nums ，其中 nums[i] 在区间 [1, n] 内。请你找出所有在 [1, n] 范围内但没有出现在 nums 中的数字，并以数组的形式返回结果。
// 理解：意思就是一个长度为n 的数组，里面的值一定在 [1,n]这个范围内，要找在范围中但是不在数组中的值
// 那么这个数组必定有重复的值，占用了应该出现的值的地方，导致某个值消失了
class Solution {
public:
    // 集合法
    // 将所有值放入集合，遍历集合查找未出现的值
    static vector<int> findDisappearedNumbersSet(vector<int>& nums) {
        vector<int> ans;
        set<int> s;
        for (int i = 0; i < nums.size(); ++i) { // 加入集合
            s.insert(nums[i]);
        }
        int flag = 1;
        for (auto it = s.cbegin(); it != s.cend(); it++) { // 遍历集合
            if (*it != flag) ans.push_back(*it);
            flag ++;
        }
        return ans;

    }
    // 加权判断法
    // 原理和上一种类似，优化了处理方式，在数组原地进行操作
    static vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        // 给每个元素加权
        // 数组中的数字范围均在 [1,n] 中，我们可以利用这一范围之外的数字，来表达「是否存在」的含义。
        // 内 不存在，外 存在
        // 遍历数组，给 nums[nums[i]] 位置 加上 (nums[i] - 1)%n 必定会超出 n
        // （不是直接加 而是加 nums[nums[i]] 这个位置的） 可以想象新建一个长度为 n 的数组 这一步是在根据现有的索引加权填充 把值当索引
        for (auto& num : nums) {
            int x = (num - 1) % n;
            nums[x] += n;
        }
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            if (nums[i] <= n) {
                ret.push_back(i + 1);
            }
        }
        return ret;
    }
    // 将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字
    // 原理和上面一样
    static vector<int> findDisappearedNumbersB(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i)
            nums[abs(nums[i])-1] = -abs(nums[abs(nums[i])-1]);
        vector<int> res;
        for (int i = 0; i < nums.size(); ++i){
            if (nums[i] > 0)
                res.push_back(i+1);
        }
        return res;
    }
    // 原地哈希
    // [1,n] 将数组中的值 放到索引上。 尽可能将数值摆在对应的位置
    static vector<int> findDisappearedNumbersLocalHash(vector<int>& nums) {
        int n = nums.size();
        int index = 0;
        while (index < n){
            if (nums[index] == index+1){ // 位置正确
                index++;
            } else{
                // 重复 不处理
                int targetIndex = nums[index] - 1;
                if (nums[targetIndex] == nums[index]){
                    index++;
                    continue;
                }
                // 不相等 交换
                int temp = nums[targetIndex];
                nums[targetIndex] = nums[index];
                nums[index] = temp;
            }
        }
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1){
                ans.push_back(i+1);
            }
        }
        return ans;
    }
};
int main(){
    vector<int> nums = {4,3,2,7,8,2,3,1};

    vector<int> ans = Solution::findDisappearedNumbers(nums);
    for (int i = 0; i < ans.size(); ++i) {
        cout << ans[i] << ",";
    }
    cout << endl;

    return 0;
}