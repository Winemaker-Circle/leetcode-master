#include <iostream>
#include <set>
#include "vector"

using namespace std;

class Solution {
public:
    static int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        if(timeSeries.empty()) return 0;
        // 中毒总秒数
        int res = 0;
        for(int i = 1; i < timeSeries.size(); i++){
            // 前后两次攻击时间间隔 = timeSeries[i] - timeSeries[i - 1]
            if(timeSeries[i] - timeSeries[i - 1] >= duration){
                // 时间间隔 大于等于 中毒持续时间，攻击无覆盖，直接累计 duration
                res += duration;
            }else{
                // 时间间隔 小于 中毒持续时间，攻击有覆盖，只累计不覆盖的中毒时长
                res += timeSeries[i] - timeSeries[i - 1];
            }
        }
        // 加上最后一次攻击中毒持续时间
        return res + duration;
    }
};
int main(){
    vector<int> timeSeries = {1,4};
    int ans = Solution::findPoisonedDuration(timeSeries,2);
    cout << ans;
    return 0;
}