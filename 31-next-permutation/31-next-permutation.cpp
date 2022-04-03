class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size(), k , l;
        
        // Break point can be atmax at the 2nd-last index
        //  traverse from (n-2) --> 0.      
        for(k = n - 2; k >= 0; k--){
                if(nums[k] < nums[k+1])
                    break;
        }
        
        // If no breakpont simply reverse it.
        if(k<0)
            reverse(nums.begin(), nums.end());
        else{
            for(l = n-1; l > k; l--){
                if(nums[l] > nums[k])
                    break;
            }
        swap(nums[k] , nums[l]);
        reverse(nums.begin() + k+1, nums.end()); 
        } 
    }
};