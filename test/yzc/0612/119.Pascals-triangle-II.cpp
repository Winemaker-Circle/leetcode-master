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
    // *此题从0行开始
    // 暴力: 使用上一题的成果,直接返回对应的行 O(n^2)
    static vector<int> getRow(int rowIndex) {
        vector<vector<int>> ans(rowIndex+1);
        for (int i = 0; i < rowIndex+1; ++i) {
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
        return ans[rowIndex];
    }
    // 滚动数组优化 使用两个数组 一个记录当前行一个记录前一行
    static vector<int> getRowOneArray(int rowIndex){
//        vector<int> ans(rowIndex+1); // 第 n 行有 n+1 个元素
//        for (int i = 0; i < rowIndex + 1; ++i) {
//            if (i == 0 || i == rowIndex){ // 两端
//                ans[i] = 1;
//            }
//            // 行内
//            ans[i] = 0;
//        }
        vector<int> pre, cur;
        for (int i = 0; i <= rowIndex; ++i) {
            cur.resize(i + 1);
            cur[0] = cur[i] = 1;
            for (int j = 1; j < i; ++j) {
                cur[j] = pre[j - 1] + pre[j];
            }
            pre = cur;
        }
        return pre;
    }
    static vector<int> getRow01(int rowIndex){
        vector<int> row(rowIndex + 1);
        row[0] = 1;
        for (int i = 1; i <= rowIndex; ++i) {
            for (int j = i; j > 0; --j) {
                row[j] += row[j - 1];
            }
        }
        return row;
    }
};
int printArray(vector<int> ans){
    cout << "[";
    for (int i = 0; i < ans.size(); ++i) {
        if (i != 0){
            cout << "," << ans[i];
        } else{
            cout << ans[i];
        }
    }
    cout << "]";
    return 0;
}

int main(){
    int rowIndex = 3;
    vector<int> ans = Solution::getRow01(rowIndex);
    printArray(ans);

    return 0;
}