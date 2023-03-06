#include <iostream>
#include <set>
#include <unordered_map>
#include <stack>
#include "vector"

using namespace std;

class Solution {
public:
    // 暴力破解
    static vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<int> res(m);
        for (int i = 0; i < m; ++i) {
            int j = 0;
            while (j < n && nums2[j] != nums1[i]) {  // 确定起始位置
                ++j;
            }
            int k = j + 1;
            while (k < n && nums2[k] < nums2[j]) {
                ++k;
            }
            res[i] = k < n ? nums2[k] : -1;
        }
        return res;
    }
    // 单调栈+哈希表
    static vector<int> nextGreaterElementStack(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        stack<int> st;
        // 直接遍历 num2 找每个元素中的下一个最大值。然后保存到 hashmap
        for (int i = nums2.size() - 1; i >= 0; --i) { // 遍历 num2
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) { // 栈空或者 当前元素大于栈顶
                st.pop();
            }
            hashmap[num] = st.empty() ? -1 : st.top(); // 栈空 则为 -1 否则为栈顶
            st.push(num); // 当前元素入栈
        }

        vector<int> res(nums1.size());
        for (int i = 0; i < nums1.size(); ++i) { // 遍历 num1 取hashmap
            res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};
int main(){
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {1,3,4,2};

    return 0;
}
