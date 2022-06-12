#include "vector"
#include "iostream"

using namespace std;

class Solution {
public:
    //[
    // [1],
    // [1,1],
    // [1,2,1],
    // [1,3,3,1],
    // [1,4,6,4,1]]
    // 错位相加:第i行的第j个数=第i-1行的j-1个数 + 第i-1行的第j个数。注意下，左右边界都是1
    // 例: 3,1 => [(i-1),(1-1)+(i-1),j] => (2,0)+(2,1)
    // O(n^2)
    static vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans(numRows);
        for (int i = 0; i < numRows; ++i) {
            vector<int> item(i+1);
            for (int j = 0; j < item.size(); ++j) { // 设定每一个 item
                if (j == 0 || j == item.size()-1){
                    item[j] = 1; // 头尾置1
                    continue;
                }
                // 行内情况
                item[j] = ans[i-1][j-1] + ans[i-1][j];
            }
            ans[i] = item;
        }
        return ans;
    }
};

int printTwoArray(vector<vector<int>> ans){
    cout << "[";
    for (auto & an : ans) {
        cout << "[";
        for (int j = 0; j < an.size(); ++j) {
            if (j != 0){
                cout << "," << an[j] ;
            } else{
                cout << an[j] ;
            }
        }
        cout << "]";
    }
    cout << "]";
    return 0;
}

int main(){
    int numRows = 5;
    vector<vector<int>> ans = Solution::generate(numRows);
    printTwoArray(ans);
    return 0;
}