class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        if(nums.size() == 0)    return 0;
        
        int currCount = 0 , maxCount = 0;
        for(int i=0; i< nums.size(); i++){
            if(nums[i] == 1)
                currCount++;
            else
                currCount = 0;
            maxCount = max(currCount, maxCount);
        }
        return maxCount;
    }
};