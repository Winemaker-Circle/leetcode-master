//# 传送门：[205.IsomorphicStrings.md](https://leetcode.cn/problems/isomorphic-strings/)
#include <unordered_map>
#include "iostream"

using namespace std;

class Solution {
public:
    // ❌ 未考虑 t->s
    static bool isIsomorphic(string s, string t) {
        // 1. 定义一个 map 用于存放 s->t 的映射
        // 2. 遍历 s ，检查是否映射 (无则存，有则校验)
        unordered_map<char,char> map;
        int sLen = s.size();
        int tLen = t.size();
        // [边界检查] 两字符串长度是否相等
        if (sLen != tLen) return false;
        // [遍历,检查映射]
        for (int i = 0; i < sLen; ++i) {
            if (map.find(s[i]) == map.end()){ // 不存在
                map[s[i]] = t[i];
                continue;
            }
            // 存在则校验
            if (t[i] == map[s[i]]){
                continue;
            } else{
                return false;
            }
        }
        return true;
    }
    // 上面只考虑了 s->t 未考虑 t->s
    // 重复一遍检测 t->s
    static bool isIsomorphicDouble(string s, string t) {
        // 1. 定义一个 map1 用于存放 s->t 的映射
        // 2. 遍历 s ，检查是否映射 (无则存，有则校验)
        unordered_map<char,char> map1;
        unordered_map<char,char> map2;
        int sLen = s.size();
        int tLen = t.size();
        // [边界检查] 两字符串长度是否相等
        if (sLen != tLen) return false;
        // [遍历,检查映射] s->t
        for (int i = 0; i < sLen; ++i) {
            if (map1.find(s[i]) == map1.end()){ // 不存在
                map1[s[i]] = t[i];
                continue;
            }
            // 存在则校验
            if (t[i] == map1[s[i]]){
                continue;
            } else{
                return false;
            }
        }
        // [遍历,检查映射] t->s
        for (int i = 0; i < sLen; ++i) {
            if (map2.find(t[i]) == map2.end()){ // 不存在
                map2[t[i]] = s[i];
                continue;
            }
            // 存在则校验
            if (s[i] == map2[t[i]]){
                continue;
            } else{
                return false;
            }
        }
        return true;
    }
    // s->t  t->s
    // 只过一次loop 参考官解 (优先考虑不成功的情况)
    static bool isIsomorphicDoublePlus(string s, string t) {
        // 1. 定义一个 s2t 用于存放 s->t 的映射
        // 2. 遍历 s ，检查是否映射 (无则存，有则校验)
        unordered_map<char,char> s2t;
        unordered_map<char,char> t2s;
        int sLen = s.size();
        int tLen = t.size();
        // [边界检查] 两字符串长度是否相等
        if (sLen != tLen) return false;
        // [遍历,检查映射] s->t
        for (int i = 0; i < sLen; ++i) {
            if ((s2t.find(s[i]) != s2t.end() && t[i] != s2t[s[i]]) || t2s.find(t[i]) == t2s.end() && s[i] != t2s[t[i]]) { // 若存在 且不等
                return false;
            }
            s2t[s[i]] = t[i];
            t2s[t[i]] = s[i];
        }
        return true;
    }
};

int main(){
    string s = "paper";
    string t = "title";
    int ans = Solution::isIsomorphic(s, t); // ture
    cout << ans << endl;

    string s1 = "badc";
    string t1 = "baba";
    int ans1 = Solution::isIsomorphicDouble(s1, t1); // false
    cout << ans1 << endl;

    return 0;
}