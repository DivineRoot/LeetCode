class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> ans;
        for(int i=0; i<nums.size(); i++){
            if(ans.find(target - nums[i])!= ans.end())
                return {ans[target - nums[i]], i};
            ans[nums[i]] = i;
        }
        return { };
    }
};
/* 
class Solution {
public:    
    // Brute Force: TC: O(N^2)  SC: O(N)
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans;
        for(int i=0; i<nums.size(); i++){
            for(int j=i+1; j<nums.size(); j++){
                if(nums[i] + nums[j] == target){
                    return {i, j};
                        OR
                    ans.push_back(i);
                    ans.push_back(j);
                    break;
                }
            }
        }
        return { } OR return ans;
    }
};*/