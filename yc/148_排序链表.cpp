
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        ListNode *middle;
        ListNode *left;
        ListNode *right;

        if (!head)
            return head;
        if (!head->next)
            return head;
        
        middle = this->findMiddle(head);
        left = this->sortList(head);
        right = this->sortList(middle);

        return this->mergeLists(left, right);
    }

private:
    ListNode *findMiddle(ListNode *head) {
        int counter = 0;
        ListNode *iter = head;
        ListNode *middle;

        while (iter)
        {
            counter++;
            iter = iter->next;
        }

        iter = head;
        for (int _ = 0; _ < int(counter / 2) - 1; ++_)
            iter = iter->next;

        middle = iter->next;
        iter->next = nullptr;

        return middle;
    }

    ListNode *mergeLists(ListNode *left, ListNode *right) {
        ListNode *merged;
        ListNode *leftptr = left;
        ListNode *rightptr = right;
        ListNode *iter;

        if (leftptr->val < rightptr->val)
        {
            iter = merged = leftptr;
            leftptr = leftptr->next;
        }
        else
        {
            iter = merged = rightptr;
            rightptr = rightptr->next;
        }

        while (leftptr && rightptr)
        {
            if (leftptr->val < rightptr->val)
            {
                iter->next = leftptr;
                leftptr = leftptr->next;
            }
            else
            {
                iter->next = rightptr;
                rightptr = rightptr->next;
            }
            iter = iter->next;
        }

        if (!leftptr)
            iter->next = rightptr;
        else
            iter->next = leftptr; 

        return merged;       
    }
};