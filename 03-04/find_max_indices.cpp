class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = n/2;
        int ans = 0;
        int k = j;
        while(i < k and j < n){
            if(nums[i] * 2 <= nums[j]){
                i++;
                ans += 2;
            }
            j++;
        }
        return ans;
    }
};