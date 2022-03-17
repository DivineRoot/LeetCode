//  1. Bitwise Solution
/*  For array [1,2,3] 
    
    Bits        Subsets
    0 0 0       []          - Choose no item
    0 0 1       [3]         - Choose only last item
    0 1 0       [2]         - Choose only second last item
    0 1 1       [2,3]       - Choose last and second last item
    1 0 0       [1]         - Choose only first item
    1 0 1       [1,3]       - Choose first and last item
    1 1 0       [1,2]       - Choose first and second last
    1 1 1       [1,2,3]     - Choose all
*/
/*
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
                                               // As the subset will have pow(2,n) elements, we multiply it by 2.
        for(int i=0; i<(1<<n); ++i) {          // (1<<n) --> total number of possible subsets. i.e, pow(2,n)
            vector<int> sub;
            
            for(int j=0; j<n; ++j)
                if(i & (1<<j))
                    sub.push_back(nums[j]);
            ans.push_back(sub);
        }
        
        return ans;
    }
};

*/

//2. Recursive Solution
class Solution {
private:
    vector<vector<int>> ans;
    int n;
    
    void permute(vector<int>& nums, vector<int> cur, int s) {
        ans.push_back(cur);
        
        for(int i=s; i<n; ++i) {
            while(cur.size() && nums[i] == cur.back()) ++i;
            cur.push_back(nums[i]);
            permute(nums, cur, i+1);
            cur.pop_back();
        }
    }
    
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> arr = {vector<int>()};
        n = nums.size();
        permute(nums, arr, 0);
        
        return ans;
    }
};