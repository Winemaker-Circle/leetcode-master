#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static int solution(vector<int>& nums, int target) {
        return {};
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
    vector<int> nums = {2,7,11,15};
    int target = 9; // [0,1]
    int ans = Solution::solution(nums, target);
    cout << ans << endl;

    return 0;
}