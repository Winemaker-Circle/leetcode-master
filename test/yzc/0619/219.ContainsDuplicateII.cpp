#include <iostream>
#include "vector"
#include "unordered_map"
#include "unordered_set"

using namespace std;

//# 传送门：[219. Contains Duplicate-II](https://leetcode.cn/problems/contains-duplicate-ii/)
//---
//给你一个整数数组 nums 和一个整数k ，
// 判断数组中是否存在两个 不同的索引i和j ，满足 nums[i] == nums[j]
// 且 abs(i - j) <= k 。
// 如果存在，返回 true ；否则，返回 false 。

class Solution {
public:
    // 哈希表
    // 时间复杂度 O(n)  空间复杂度 O(n)
    static bool containsNearbyDuplicateHash(vector<int>& nums, int k) {
        unordered_map<int,int> map; // key 为元素值， value 为元素 (最新)索引
        for (int i = 0; i < nums.size(); ++i) {
            // map.find(key) 如果 map 存在 key 则返回 key 对应的迭代器，如果不存在 则返回 unordered_map::end
            // count(X) 0 or 1 不存在 or 存在
            if (map.count(nums[i]) && (i-map[nums[i]]<=k)){ // map 中存在这个key，判断 i-value>=k
                return true;
            }
            // 不存在 或 存在但是不满足条件 则缓存这个值以及他的索引
//            map.emplace(nums[i],i); // 此处不能使用 emplace 如果元素已经存在，则返回指向已存在元素的迭代器 不会插入新的
            map[nums[i]] = i;
        }
        return false;
    }
    // Sliding Window Algorithm
    // 时间复杂度 O(n)  空间复杂度 O(k)
    // 面对数组，一次只能看到 k 长度的子串 例如 密码锁
    static bool containsNearbyDuplicateWindow(vector<int>& nums, int k) {
        unordered_set<int> set; // 用于缓存窗口内的数据 也就是要保证 set 中只有 k 个元素
        for (int i = 0; i < nums.size(); ++i) {
            if (i > k){ // 开始滑动窗口后 每次删除最前面的一个数据
                set.erase(nums[i-k-1]);
            }
            if (set.count(nums[i])){
                return true;
            }
            set.emplace(nums[i]);  // 加入窗口
        }
        return false;
    }
};

int main(){
//    vector<int> nums = {1,2,3,1};
//    vector<int> nums = {1,2,3,1,2,3}; // false
    vector<int> nums = {1,0,1,1};
    int k = 1;
    bool ans = Solution::containsNearbyDuplicateHash(nums, k);
    cout << ans << endl;

    return 0;
}