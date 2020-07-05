/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode *head = new ListNode(), *cur=head, *tmp;
        priority_queue<ListNode*, vector<ListNode*>> q;
        for (int i=0;i<lists.size();++i)
        {
            if (lists[i]!=NULL)
                q.push(lists[i]);
        }
        while (!q.empty())
        {
            tmp = q.top();
            cur -> next = tmp;
            cur = cur -> next;
            q.pop();
            if (tmp->next!=NULL)
                q.push(tmp->next);
        }
        return head->next;
    }


private:
    
    bool operator<(const ListNode *a, const ListNode *b)
    {
        return (a->val > b->val);
    }
    
    /*
   struct cmp{
    bool operator() (ListNode *a, ListNode *b ){return a->val > b->val;}
    };
    */
    
};
