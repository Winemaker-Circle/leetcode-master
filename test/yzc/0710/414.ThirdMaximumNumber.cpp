#include <iostream>
#include <algorithm>
#include <set>
#include "vector"

using namespace std;

//# 传送门：[414.ThirdMaximumNumber](https://leetcode.cn/problems/third-maximum-number/)
//---

// 类似题目 1796. 字符串中第二大的数字

class Solution {
public:
    // 排序法 从大到小排序
    // T: O(nlogn) 主要花费在排序上了
    // S: O(logn) 排序所需空间
    static int thirdMaxSort(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<>()); // 排序
        int diff = 1;
        for (int i = 1; i < nums.size(); ++i) { // 从 1 开始
            if (nums[i] != nums[i - 1]) { // 是否和前一个相等 主要是为了去掉重复元素的影响,
                ++diff;
                if (diff == 3){ // diff 用于设置条件: 输出第几大的数
                    return nums[i];
                }
            }
        }
        return nums[0];
    }
    // Set 法
    // T:O(n)
    // S:O(1) 固定为3，常数阶
    static int thirdMaxSet(vector<int> &nums) {
        set<int> s;  // 有序集合（从小到大），限制大小为 3，大于三时将最新小值删除 [保证集合中每轮只保存最大的三个值]
        for (int num : nums) {
            s.insert(num);
            if (s.size() > 3) { // 移出最小值，也就是 set 中第四大的（我们不需要这玩意了）
                s.erase(s.begin());
            }
        }
        return s.size() == 3 ? *s.begin() : *s.rbegin(); // 没有3个就返回当前最大的
    }
    // 变量缓存法 （和上一种类似，只是手动去实现值的保存，可以将这3个变量视为set）
    // T S 和上面一样
    // 重点时3个变量的逻辑处理以及边界条件考虑
    static int thirdMaxVar(vector<int> &nums) {
        int *a = nullptr, *b = nullptr, *c = nullptr; // 初始为空指针
        for (int &num : nums) {  // 难点是这里的3个数的逻辑处理 （先把3兄弟填满）
            if (a == nullptr || num > *a) { // a为空或者新值大于a (大哥来了，移出最小值)
                c = b;
                b = a;
                a = &num;
            } else if (*a > num && (b == nullptr || num > *b)) { // 如果新值小于大哥 并且 新值大于二哥 （也就是新二哥）
                c = b; // 老三出局，老二变老三
                b = &num; // 新老二入局
            } else if (b != nullptr && *b > num && (c == nullptr || num > *c)) {  // 新值小于老二 且 大于老三 (新老三)
                c = &num;
            }
        }
        return c == nullptr ? *a : *c; // 反正没有3兄弟的情况，若出现则返回老大
    }
    // 谭浩强魔法
    static int thirdMaxTan(vector<int>& nums) {
        set<int> s(nums.begin(),nums.end()); // 将所有数放入有序集合（从小到大）
        // C++ stl的set自带排序，但是set不支持下标访问，迭代器也不支持双目加减，只能使用自增或自减
        // 六个减号就是自减三次，就是从end()迭代器倒数第三个值。
        return s.size() >= 3 ? *(------s.end()) : *(--s.end());
    }
};
int main(){
    vector<int> nums = {2, 2, 3 ,4 ,5 ,6 , 1};

    // 排序法
//    int ans = Solution::thirdMaxSort(nums);
//    cout << ans << endl;

    // 集合法
//    int ans1 = Solution::thirdMaxSet(nums);
//    cout << ans1 << endl;

    // 变量法
//    int ans1 = Solution::thirdMaxVar(nums);
//    cout << ans1 << endl;
    // Tan 法
    int ans1 = Solution::thirdMaxTan(nums);
    cout << ans1 << endl;

    return 0;
}
