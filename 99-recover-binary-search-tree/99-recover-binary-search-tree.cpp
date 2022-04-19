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
	TreeNode* firstMistake, *secondMistake, *prev;
	void recoverTree(TreeNode* root) {
		prev = new TreeNode(INT_MIN);
		inorder(root);
		swap(firstMistake->val, secondMistake->val);
	}

	void inorder(TreeNode* root) {
		if(root == nullptr) 
			return;

		inorder(root->left);

		if(firstMistake == nullptr && root->val < prev->val)
			firstMistake = prev;
		if(firstMistake != nullptr && root->val < prev->val)
			secondMistake = root;
		prev = root;

		inorder(root->right);
	}
};