#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    // 假设除了整数 0 之外，这个整数不会以零开头。
    // 共有以下几种情况：
    // 1. 末尾不为9 加一后没有进位，直接加即可 [1,2,3] => [1,2,4]
    // 2. 末尾有多个9 加一后发生进位，不扩容。从后往前找到不是9 的元素将其+1，并将后续置为0， [1,2,9] => [1,3,0]
    // 3. 全是9，扩容并将首位置1，其余全0。例如 [9,9] => [1,0,0]
    static vector<int> plusOne(vector<int>& digits) {
        int length = digits.size();

        for (int i = length-1; i >= 0; --i) { // 从后往前遍历
            if (digits[i] !=9 ){ // 如果末尾不为9 直接相加即可; 如果为9 判断前一个，并且让后续的全部改为0
                digits[i]++; // 当前元素自增1
                for (int j = i+1; j < length; ++j) { // 遍历后续元素都改为 0
                    digits[j] = 0;
                }
                return digits;
            }
        }
        // 所有元素都为9
        vector<int> ans(length+1);
        ans[0] = 1;
        return ans;

//        int origin_sum = digits[length-1] + 1;
//        if (origin_sum < 10){ // 未发生进位，直接加
//            digits[length-1] +=1;
//            return digits;
//        } else{ // 发生进位
//            // 发生进位的话 放入新数组
//            vector<int> ans(length + 1);
//            for (int i = length-1; i >= 0; --i) {
//                ans[i] = origin_sum % 10;
//                ans[i-1] = digits[i-2] + 1;
//            }
//            return ans;
//        }

//        for (int i = 0; i <length; ++i) {
//            int origin_sum = digits[i] + 1;
//            digits[i] = origin_sum > 10 ? origin_sum:origin_sum%10;
//            digits[i-1] = origin_sum > 10 ? digits[i-1]:digits[i-1]+1;
//        }
        return digits;
    }
    // 另一种思路，不用去在乎几个9 遇到9则处理
    static vector<int> plusOneSimple(vector<int> digits){
        int length = digits.size();
        for (int i = length - 1; i >= 0; --i) { // 从后往前遍历
            digits[i] = (digits[i] + 1) % 10;   // 判断元素加一后是否为 10 (也就是判断9)
            if (digits[i] != 0){ // 不为9（若加一后不为10）则直接结束
                return digits;
            }
        }
        // 元素全为 9
        vector<int> ans(length+1);
        ans[0] = 1;
        return ans;
    }
    // 一种比较精简的实现
    static vector<int> plusOneCompress(vector<int> digits){
        int length = digits.size();
        while (length && ++digits[--length] == 10){ // 这种写法与上面原理一致，遇到9则置为0
            digits[length] = 0;
        }
        if (digits[0] == 0){
            digits.insert(begin(digits),1);
        }
        return digits;
    }
};
void print_array(vector<int>& array){
    cout << "[";
    for(const auto &x : array){
        cout << x << " ";
    }
    cout << "]\n";
}
int main(){
//    vector<int> digits = {1,2,3,4,5,6,7,8};
    vector<int> digits = {1,9,9};
    cout << "origin digits is: ";
    print_array(digits);
    cout << "added digits is: ";
    vector<int> added_digits = Solution::plusOne(digits);
    print_array(added_digits);

    vector<int> digits1 = {1,9,9};
    cout << "origin digits1 is: ";
    print_array(digits1);
    cout << "added digits1 is: ";
    vector<int> added_digits1 = Solution::plusOneSimple(digits1);
    print_array(added_digits1);

    return 0;
}