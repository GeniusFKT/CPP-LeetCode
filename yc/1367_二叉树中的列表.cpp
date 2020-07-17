/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    bool isSubPath(ListNode* head, TreeNode* root) {
        if (!head)
            return true;
        if (!root)
            return false;
        return this->recurFunc(head, root) || this->isSubPath(head, root->left) || this->isSubPath(head, root->right);
    }

private:
    bool recurFunc(ListNode *head, TreeNode *root) {
        if (!head)
            return true;
        if (!root)
            return false;
        if (root->val != head->val)
            return false;
        return this->recurFunc(head->next, root->left) || this->recurFunc(head->next, root->right);
    }
};