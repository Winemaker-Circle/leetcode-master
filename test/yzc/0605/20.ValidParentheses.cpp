#include <stack>
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static bool isValid(string s) {
        stack<char> stk;
        for(auto c : s) {
            // 左括号 ({[ 则入栈
            if (c == '(' || c == '{' || c == '[')
                stk.push(c);
                // 如果c是右括号 并且栈不为空 则 判断栈顶是否为与之对应的左括号 是则出栈，不是则返回 false
            else if (c == ')' && !stk.empty() && stk.top() == '(') {
                stk.pop();
            } else if (c == '}' && !stk.empty() && stk.top() == '{') {
                stk.pop();
            } else if (c == ']' && !stk.empty() && stk.top() == '[') {
                stk.pop();
            } else {
                // 如果c是 )}] 栈为空 那么返回false
                // 如果c是 )}] 栈不为空， 但是 栈顶不是与c对应的左括号 那么返回false
                return false;
            }
        }
        // 如果最后栈不为空，表示有多余的左括号
        return stk.empty();
    }
};

int main(){

    string s = "()[]{}";
    cout << Solution::isValid(s) <<endl;
    return 0;
}