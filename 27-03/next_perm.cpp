class Solution {
public:
    void reverse(vector<int> & arr, int i, int j){
        for(;i < j;){
            swap(arr[i++], arr[j--]);
        }
    }
    void nextPermutation(vector<int>& nums){
        int n = nums.size();
        int i, j;
        for(i = n-2; i >= 0; i--)
            if(nums[i] < nums[i+1])
                break;
        for(j = n-1; j > i and i != -1; j--){
            if(nums[j] > nums[i]){
                swap(nums[i], nums[j]);
                break;
            }
        }
        reverse(nums, i+1, n-1);
    }
};