class Solution {
public:
    bool isValidBST(TreeNode* root) {
        if (root==NULL)
            return true;
        return isValid(root, LONG_MAX, LONG_MIN);
    }
private:
    bool isValid(TreeNode* root, long upper, long lower)
    {
        if (root == NULL)
            return true;
        if (root->val >= upper || root->val<=lower)
            return false;
        if (!isValid(root->left, root->val, lower))
            return false;
        if (!isValid(root->right, upper, root->val))
            return false;
        return true;
    }
};