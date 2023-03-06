#include <iostream>
#include <set>
#include "vector"

using namespace std;

class Solution {
public:
    static vector<string> findWords(vector<string>& words) {

    }
    // 官解
    static vector<string> findWordsHashOfficial(vector<string>& words) {
        vector<string> ans;
        string rowIdx = "12210111011122000010020202"; // a~z 字母对应行数
        for (auto & word : words) {
            bool isValid = true;
            char idx = rowIdx[tolower(word[0]) - 'a']; // 确定该单词首字母行数，后续只需以此为基准判断
            for (int i = 1; i < word.size(); ++i) { // 后续字符找到行数与基准对比
                if(rowIdx[tolower(word[i]) - 'a'] != idx) {
                    isValid = false;
                    break;
                }
            }
            if (isValid) {
                ans.emplace_back(word);
            }
        }
        return ans;
    }
};
int main(){
    vector<string> words = {"Hello","Alaska","Dad","Peace"};
    vector<string> ans = Solution::findWordsHashOfficial(words);
    for (int i = 0; i < ans.size(); ++i) {
        cout << "\"" <<ans[i] << "\",";
    }
    return 0;
}