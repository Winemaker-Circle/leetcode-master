//# 传送门：[242.ValidAnagram](https://leetcode.cn/problems/valid-anagram/)
#include <unordered_map>
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    // 异位词:「两个字符串中某个字符出现的种类和次数均相等」
    // s 负责+  t 负责- 若为异位词 最后的数组肯定为0 各个元素相互抵消了
    static bool isAnagramMap(string s, string t) {
        if (s.size() != t.size()) return false;
        vector<int> alpha(26);
        for(int i = 0; i< s.length(); i++) {
            alpha[s[i] - 'a'] ++;
            alpha[t[i] - 'a'] --;
        }
        for(int i=0;i<26;i++)
            if(alpha[i] != 0)return false;
        return true;
    }
};

int main(){
    string s = "anagram";
    string t = "nagaram";
    int ans = Solution::isAnagramMap(s, t);
    cout << ans << endl;

    return 0;
}
