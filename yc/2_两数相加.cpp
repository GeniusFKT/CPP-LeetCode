
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        // reverse two lists
        ListNode *l1_rev = this->reverseList(l1);
        ListNode *l2_rev = this->reverseList(l2);
        ListNode *l1_ptr = l1_rev;
        ListNode *l2_ptr = l2_rev;
        ListNode *tmp;
        ListNode *right_most_left = nullptr;

        bool isCarry = false;

        while (l1_ptr && l2_ptr)
        {
            if (isCarry)
            {
                tmp = new ListNode((l1_ptr->val + l2_ptr->val + 1) % 10);
                if (l1_ptr->val + l2_ptr->val + 1 >= 10)
                    isCarry = true;
                else
                    isCarry = false;
            }
            else
            {
                tmp = new ListNode((l1_ptr->val + l2_ptr->val) % 10);
                if (l1_ptr->val + l2_ptr->val >= 10)
                    isCarry = true;
                else
                    isCarry = false;
            }

            if (!right_most_left)
                right_most_left = tmp;
            else
            {
                tmp->next = right_most_left;
                right_most_left = tmp;
            }

            l1_ptr = l1_ptr->next;
            l2_ptr = l2_ptr->next;
        }

        while (l1_ptr)
        {
            if (isCarry)
            {
                tmp = new ListNode((l1_ptr->val + 1) % 10);
                if (l1_ptr->val + 1 >= 10)
                    isCarry = true;
                else
                    isCarry = false;
            }
            else
            {
                tmp = new ListNode(l1_ptr->val);
                isCarry = false;
            }

            tmp->next = right_most_left;
            right_most_left = tmp;
            l1_ptr = l1_ptr->next;
        }

        while (l2_ptr)
        {
            if (isCarry)
            {
                tmp = new ListNode((l2_ptr->val + 1) % 10);
                if (l2_ptr->val + 1 >= 10)
                    isCarry = true;
                else
                    isCarry = false;
            }
            else
            {
                tmp = new ListNode(l2_ptr->val);
                isCarry = false;
            }

            tmp->next = right_most_left;
            right_most_left = tmp;
            l2_ptr = l2_ptr->next;
        }

        if (isCarry)
        {
            tmp = new ListNode(1);
            tmp->next = right_most_left;
            right_most_left = tmp;
        }

        return right_most_left;
    }

private:
    ListNode *reverseList(ListNode *l) {
        ListNode *iter = l->next;
        ListNode *tmp;
        ListNode *left_most_right_ptr = l;

        if (!l->next)
            return l;

        while (iter)
        {
            tmp = iter->next;
            iter->next = left_most_right_ptr;
            left_most_right_ptr = iter;

            iter = tmp;
        }

        l->next = nullptr;

        return left_most_right_ptr;
    }
};