//# 传送门：[257.Binary Tree Paths](https://leetcode.cn/problems/binary-tree-paths/)

#include <unordered_map>
#include "iostream"

using namespace std;

class Solution {
public:
    static int wordPattern(string pattern, string s) {
        int pLen=pattern.length(),sLen=s.length();
        if (pLen!=sLen) return false;
        unordered_map<string, char> str2ch;
        unordered_map<char, string> ch2str;
        int i = 0;
        for (auto ch : pattern) {
            int j = i;
            while (j < sLen && s[j] != ' ') {
                j++;
            }
            const string &tmp = s.substr(i, j - i);
            if ((str2ch.count(tmp) && str2ch[tmp] != ch) || ch2str.count(ch) && ch2str[ch] != tmp) {
                return false;
            }
            str2ch[tmp] = ch;
            ch2str[ch] = tmp;
            i = j + 1;
        }
        return i >= sLen;
    }
};

int main(){
    string pattern = "abba";
    string s = "dog cat cat dog";
    int ans = Solution::wordPattern(pattern, s);
    cout << ans << endl;

    return 0;
}