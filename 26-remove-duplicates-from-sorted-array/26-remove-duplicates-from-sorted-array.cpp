class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i = 0, j = 1, count = 1;
        
        if(nums.size() == 0)
            return 0;
        
        for(j = 1; j < nums.size(); j++){
            if(nums[j] != nums[i] ){
                i++;
                nums[i] = nums[j];
                count++;
            }
        }
        return count;           // OR return i+1 Since, i would be on the desired once j goes out of bound.
    }
};