// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        // construct adjacent node
        Node *iter = head;
        Node *tmp;
        Node *ans;

        if (!head)
            return head;

        while (iter)
        {
            tmp = iter->next;
            iter->next = new Node(iter->val);
            iter->next->next = tmp;
            iter = iter->next->next;
        }

        // construct random ptr
        iter = head;
        while (iter)
        {
            if (iter->random)
            {
                iter->next->random = iter->random->next;
            }
            else
            {
                iter->next->random = nullptr;
            }
            
            iter = iter->next->next;
        }

        // split the list
        iter = head;
        ans = head->next;

        while (iter->next->next)
        {
            tmp = iter->next;
            iter->next = tmp->next;
            iter = tmp;
        }
        iter->next = nullptr;
        return ans;
    }
};