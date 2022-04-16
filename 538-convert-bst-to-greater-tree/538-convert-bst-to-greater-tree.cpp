/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, int& total){
        if(!root) return;
        solve(root->right, total);      // Traverse to the right to find no. greater than root
        total += root->val;             // Add the value to a 'total'
        root->val = total;              // Assign 'total' to the root's val
        solve(root->left, total);       // Repeat the same with left side.
    }
    
    TreeNode* convertBST(TreeNode* root) {
        int total=0;
        solve(root,total);
        return root; 
    }
};
/* TC: O(N)    SC: O(N) (recursion)
INTUITION:
1. First traverse right sub tree(having greater value then node) and then left sub tree(having lesser value then node)
2. Take a variable named as total which store sum of node values up to which we traverse
3. And assign total value to root value.    */