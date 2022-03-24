// Bit maniuplation:    TC: O(N)        SC: O(1) 
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int element = 0;
        for(int i=0; i<nums.size(); i++){
            element = element ^ nums[i];
        }
       return element; 
    }
};