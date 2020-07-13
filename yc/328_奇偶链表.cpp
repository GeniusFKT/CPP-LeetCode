
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        ListNode *even_list = nullptr;
        ListNode *tmp;
        ListNode *odd_list_end = nullptr;
        ListNode *even_list_end = nullptr;
        bool is_odd = true;

        for (tmp = head; tmp; tmp = tmp->next)
        {
            if (is_odd)
            {
                if (odd_list_end == nullptr)
                    odd_list_end = head;
                else
                {
                    odd_list_end->next = tmp;
                    odd_list_end = tmp;
                }
            }
            else
            {
                if (even_list_end == nullptr)
                {
                    even_list = tmp;
                    even_list_end = tmp;
                }
                else
                {
                    even_list_end->next = tmp;
                    even_list_end = tmp;
                }                
            }
            is_odd = !is_odd;
        }

        if (odd_list_end != nullptr)
            odd_list_end ->next = even_list;
        if (even_list_end != nullptr)
            even_list_end->next = nullptr;

        return head;
    }
};