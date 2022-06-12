#include "iostream"
#include "vector"

using namespace std;

class Solution {
public:
    static int singleNumber(vector<int>& nums) {
        QuickSort(&nums[0],0,nums.size()-1);
        Solution::printArray(nums);
        for(int i = 1;i<nums.size();i++){
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
    // quickSort
    static void swap(int *a, int *b){
        int temp = *a;
        *a = *b;
        *b = temp;
    }
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
    // PrintArray
    static void printArray(vector<int>& array){
        cout << "[";
        for(const auto &x : array){
            cout << x << " ";
        }
        cout << "]\n";
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
//    vector<int> nums = {2,2,4,4,6,6,88,88,9,9,0,0,100};
    vector<int> nums = {2,2,1};
    cout << Solution::singleNumber(nums);
    return 0;
}