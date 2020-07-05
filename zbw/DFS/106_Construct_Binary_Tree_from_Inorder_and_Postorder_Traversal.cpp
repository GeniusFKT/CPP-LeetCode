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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return buildTree(inorder,postorder,0,inorder.size()-1,0,postorder.size()-1);
    }
private:
    TreeNode* buildTree(vector<int>& inorder,vector<int>&postorder,int in_begin,int in_end,int post_begin, int post_end){
        if (in_begin>in_end)
            return NULL;
        TreeNode *root=new TreeNode(postorder[post_end]);
        int i,left_len,right_len;
        for (i=in_begin;i<=in_end;++i)
        {
            if (root->val==inorder[i])
                break;
        }
        left_len=i-1-in_begin;
        right_len=in_end-i-1;
        root->left=buildTree(inorder,postorder,in_begin,i-1,post_begin,post_begin+left_len);
        root->right=buildTree(inorder,postorder,i+1,in_end,post_end-1-right_len,post_end-1);
        return root;
    }
        
};