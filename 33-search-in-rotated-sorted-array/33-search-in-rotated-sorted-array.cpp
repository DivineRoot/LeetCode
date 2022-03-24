class Solution {
public:
    int search(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;
        while(low <= high){
            int mid = low + (high - low) /2;
            if(nums[mid] == target) return mid;
            
            // If the left half is sorted
            if(nums[low] <= nums[mid]){
                if( nums[low] <= target  && target <= nums[mid])
                    high = mid - 1;             // if the target lies in the sorted left half
                else
                    low = mid + 1;              // if the target doesn't lie in the sorted left half
            }
            // If the right half is sorted
            else{
                if(nums[mid] <= target && target <= nums[high])
                    low = mid + 1;
                else
                    high = mid - 1;
            }
        }
        return -1;
    }
};