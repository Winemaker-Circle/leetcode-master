#include <stack>
#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static vector<int> asteroidCollision(vector<int> &asteroids) {
        // initial stack
        // stack + array
        stack<int> s;
        s.push(INT_MIN); // 放入一个默认值
        cout << s.top() << endl;

        // 栈顶： 只有为正才会炸

        // 两个角色：栈顶值 新值
        // 流程:
        // 1. 进栈操作：
        // - 01.栈为空
        // - 02.栈顶为负数(新值为负则一起向左 [<-,<-]，新值为正则各种朝向两边 [<-,->])
        // - 03.当前为正数（栈顶为正一起向右 [->,->]，栈顶为负都往中间两边 [->,<-]）
        // 2. 发生碰撞
        // - 01. 栈顶大于新值，新值爆炸
        // - 02. 栈顶等于新值，都爆炸
        // - 03. 栈顶小于新值，栈顶弹出，并与新栈顶完成上述判断

        for (auto n: asteroids) { // 遍历
            if (n < 0) { // 新值为负
                while (s.top() > 0 && s.top() < -n) { // 如果栈顶为正，并且小于新值大小（绝对值） 栈顶爆炸，重复操作
                    s.pop(); // 出栈
                }
                if (s.top() < 0) // 如果栈顶为负
                    s.push(n);
                else if (s.top() == -n) // 如果栈顶与新值大小（绝对值）相等
                    s.pop();
            } else { // 新值为正
                s.push(n); // 入栈
            }
            // 如果不满足上面，则说明新值为负且小于栈顶 新值爆炸
        }

        vector<int> res; // 结果数组
        while (s.size() != 1) {
            res.push_back(s.top()); // 将栈顶放入数组尾部
            s.pop();                // 然后出栈
        }

        return {res.rbegin(), res.rend()};
    }
};

void print_array(vector<int>& array){
    cout << "[";
    for(const auto &x : array){
        cout << x << " ";
    }
    cout << "]\n";
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    vector<int>::reverse_iterator r_iter;
    for (r_iter = nums.rbegin(); r_iter != nums.rend() ; ++r_iter) { // 反向迭代
        cout << *r_iter << " ";
    }
    cout << endl;
    cout << "=============== " << endl;


    vector<int> ast1 = {5,10,-5};
    vector<int> ast2 = {8,-8};
    vector<int> ast3 = {10,2,-5};

    vector<int> ans1 = Solution::asteroidCollision(ast1);
    print_array(ast1);
    cout << "=> ";
    print_array(ans1);

    vector<int> ans2 = Solution::asteroidCollision(ast2);
    print_array(ast2);
    cout << "=> ";
    print_array(ans2);

    vector<int> ans3 = Solution::asteroidCollision(ast3);
    print_array(ast3);
    cout << "=> ";
    print_array(ans3);

    vector<int> ast4 = {-5, 10,-5};
    vector<int> ans4 = Solution::asteroidCollision(ast4);
    print_array(ast4);
    cout << "=> ";
    print_array(ans4);

    return 0;
}