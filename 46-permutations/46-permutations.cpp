/*        Recursion without extra DS i.e, saving space complexity  
TC: n!*n  - For generating n! perms & 'n' length loop 
SC: O(n)+O(n!)  - For the recursion depth & 'n!' for returning the ans */

class Solution {
public:
    void helper(int index, vector<int> &nums, vector<vector<int>> &ans){
        if(index == nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int i=index; i<nums.size(); i++){
            swap(nums[index], nums[i]);
            helper(index+1, nums, ans);
            swap(nums[index], nums[i]);         // Restoring the previous array
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        helper(0, nums, ans);
        return ans;
    }
};

/*      Recursion with extra DS i.e, increased space complexity

class Solution {
public:
    void helper (vector<int> &arr, vector<vector<int>> &ans, vector<int> &ds, int freq[]){
        // if our DS gets completely filled, we have one of ur permutations.
        if(ds.size() == arr.size()){ 
            ans.push_back(ds);
            return;
        }
        
        for(int i = 0; i < arr.size(); i++){
            // If the curr ele has been picked or not
            if(!freq[i]){
                freq[i] = 1;
                ds.push_back(arr[i]);
                helper(arr, ans, ds, freq);
                freq[i] = 0;
                ds.pop_back();
            }
        }
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        int freq[nums.size()];              // Freq array to keep track of which ele have been picked
        for(int i=0; i<nums.size(); i++)
            freq[i] = 0;
        helper(nums, ans, ds, freq);
        return ans;
    }
};
*/