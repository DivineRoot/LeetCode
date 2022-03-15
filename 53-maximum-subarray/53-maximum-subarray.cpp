class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSubarr = INT_MIN , sum = 0;
        for(auto it: nums){
            sum += it;
            maxSubarr = max(maxSubarr, sum);
            if ( sum < 0) sum =0;
        }
        return maxSubarr;
    }
};