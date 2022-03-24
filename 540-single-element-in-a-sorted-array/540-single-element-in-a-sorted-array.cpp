//Binary Search         TC: O(logN)         SC: O(1)
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        int l=0, r=nums.size()-1, mid, num;
        
        while(l < r){
            mid = l+(r-l)/2;
            num = (mid%2 == 0) ? mid+1 : mid-1;
            if(nums[mid]==nums[num]) l = mid+1;
            else r = mid;
        }
        return nums[l];
    }
};

/*
// Bit maniuplation:    TC: O(N)            SC: O(1) 
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
*/