/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size()==0)
            return NULL;
        return buildTree(preorder, inorder, 0, preorder.size()-1, 0, inorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int left_p, int right_p, int left_i, int right_i) {
        TreeNode *root = new TreeNode(preorder[left_p]);
        vector<int>::iterator iter = find(inorder.begin()+left_i, inorder.begin()+right_i+1, preorder[left_p]);
        int left_len = iter - (inorder.begin()+left_i), right_len = right_i - (iter - inorder.begin());
        if (left_len > 0)
            root->left = buildTree(preorder, inorder, left_p+1, left_p+left_len, left_i, left_i+left_len-1);
        if (right_len > 0)
            root->right = buildTree(preorder, inorder, left_p+left_len+1, right_p, left_i+left_len+1, right_i);
        return root;
    }
};
