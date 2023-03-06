
#include "iostream"
#include "vector"

using namespace std;

// # 传送门：[67.AddBinary](https://leetcode.cn/problems/add-binary/)

class Solution {
public:
    static int lengthOfLastWord(string s) {
        int index = s.size() - 1;
        while (s[index] == ' ') {
            index--;
        }
        int wordLength = 0;
        while (index >= 0 && s[index] != ' ') {
            wordLength++;
            index--;
        }
        return wordLength;
    }
};

int main() {
    string s = "   fly me   to   the moon  ";
    int ans = Solution::lengthOfLastWord(s);
    cout << "[ans] = " << ans << endl;

    return 0;
}