
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if (head == nullptr)
            return head;

        ListNode *recur = removeZeroSumSublists(head->next);
        head->next = recur;
        ListNode *tmp;
        int ctr = 0;

        for (tmp = head; tmp; tmp = tmp->next)
        {
            ctr += tmp->val;
            if (ctr == 0)
                return tmp->next;
        }

        return head;
    }
};