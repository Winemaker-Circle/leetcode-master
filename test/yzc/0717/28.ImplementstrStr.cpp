#include <unordered_map>
#include "iostream"
#include "vector"

using namespace std;

// # 传送门：[28.ImplementstrStr()](https://leetcode.cn/problems/implement-strstr/)

class Solution {
public:
    // Brute-Force
    static int strStrBF(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        for(int i = 0; i <= n - m; i++){
            int j = i, k = 0;
            while(k < m and haystack[j] == needle[k]){
                j++;
                k++;
            }
            if(k == m) return i;
        }
        return -1;
    }
    // KMP
    static int strStrKMP(string haystack, string needle) {
        int n = haystack.size(), m = needle.size();
        if(m == 0) return 0;
        //设置哨兵 加空格，使其从 1 开始
        haystack.insert(haystack.begin(),' ');
        needle.insert(needle.begin(),' ');
        vector<int> next(m + 1);
        // 预处理next数组 o(m)
        // 数组长度为匹配串的长度（next 数组是和匹配串相关的）
        // i = 2;j=0
        for(int i = 2, j = 0; i <= m; i++){
            // 匹配不成功 j = next()
            while(j>0 && needle[i] != needle[j + 1]){
                j = next[j];
            }
            // 匹配成功 j++
            if(needle[i] == needle[j + 1]) {
                j++;
            }
            // 更新 next[i]
            next[i] = j;
        }
        //匹配过程
        for(int i = 1, j = 0; i <= n; i++){
            while(j>0 && haystack[i] != needle[j + 1]) {
                j = next[j];
            }
            if(haystack[i] == needle[j + 1]) {
                j++;
            }
            if(j == m) {
                return i - m;
            }
        }
        return -1;
    }
};

int main(){
//    string haystack = "tobeornottobe";
//    string needle = "ob";
    string haystack = "ABABCABCACBAB";
    string needle = "ABCAC";
    int ansBF = Solution::strStrBF(haystack,needle);
    int ansKMP = Solution::strStrKMP(haystack,needle);
    cout << "BF: " << ansBF << endl;
    cout << "KMP: " << ansKMP << endl;
    return 0;
}
