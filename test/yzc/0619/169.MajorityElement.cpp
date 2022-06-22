#include <unordered_map>
#include <iostream>
#include "vector"

using namespace std;

// 169. 多数元素

class Solution {
public:
    // 使用哈希表实现 O(n)
    static int majorityElementHash(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(int num:nums){ // 计算频次
            freq[num]++;
        }
        int ans,maxOcc = 0;
        for(auto [num,occ]:freq){ // 查找答案
            if(occ>nums.size()/2 && occ > maxOcc){ // 关于 maxOcc在本题中可以省略
                ans = num;
            }
        }

        return ans;
    }
    // 如果存在某一个多数元素，数组中一半元素都是它（>n/2），
    // 因此将这个数组排序后，他们肯定会形成一个连续的子串，
    // 其中这个值肯定会落在数组中的中间元素上 N/2
    static int majorityElementSort(vector<int>& nums){
        // QuickSort
        QuickSort(&nums[0],0,nums.size()-1);
        return nums[nums.size()/2];
    }
    // 投票法
    // 遍历一遍
    // 候选人 candidate(cand_num)初始化为nums[0]，票数count初始化为1。
    // 当遇到与cand_num相同的数，则票数count = count + 1，否则票数count = count - 1。
    // 当票数count为0时，更换候选人，并将票数count重置为1。
    // 遍历完数组后，cand_num即为最终答案
    static int majorityElementVote(vector<int>& nums){
        int cand_num = nums[0],count = 1;
        for (int i = 0; i < nums.size(); ++i) {
            nums[i] == cand_num ? count+=1:count-=1;
            if (count == 0){
                cand_num = nums[i];
                count = 1;
            }
        }
        return cand_num;
    }
    // =====================================================
    // quickSort
    static int Partition(int *arr, int front, int end){
        int pivot = arr[end];
        int i = front -1;
        for (int j = front; j < end; j++) {
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
            }
        }
        i++;
        swap(&arr[i], &arr[end]);
        return i;
    }
    static void QuickSort(int *arr, int front, int end){
        if (front < end) {
            int pivot = Partition(arr, front, end);
            QuickSort(arr, front, pivot - 1);
            QuickSort(arr, pivot + 1, end);
        }
    }
    static void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
};

int main(){
    vector<int> nums = {3,2,3,2,2};

    // 哈希表
    int ans = Solution::majorityElementHash(nums);
    cout << ans << endl;

    // 排序法
    int ans1 = Solution::majorityElementSort(nums);
    cout << ans1 << endl;

    // 投票法
    int ans2 = Solution::majorityElementVote(nums);
    cout << ans2 << endl;



    return 0;
}