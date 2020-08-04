
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *small_list = nullptr;
        ListNode *small_ptr;
        ListNode *big_list = nullptr;
        ListNode *big_ptr;
        ListNode *iter = head;

        while (iter)
        {
            if (iter->val >= x)
            {
                if (big_list)
                {
                    big_ptr->next = iter;
                    big_ptr = big_ptr->next;
                }
                else
                {
                    big_list = big_ptr = iter;
                }
            }
            else
            {
                if (small_list)
                {
                    small_ptr->next = iter;
                    small_ptr = small_ptr->next;
                }
                else
                {
                    small_list = small_ptr = iter;
                }
            }

            iter = iter->next;
        }

        // 没有这四行的话可能会成环！
        if (small_list)
            small_ptr->next = nullptr;
        if (big_list)
            big_ptr->next = nullptr;

        if (!small_list)
            return big_list;
        else
        {
            small_ptr->next = big_list;
            return small_list;
        }
    }
};