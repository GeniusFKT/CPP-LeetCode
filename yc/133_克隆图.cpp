#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};


class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (node == nullptr) 
            return nullptr;
        
        Node *ans = new Node;
        ans->val = node->val;

        queue<Node*> qOrigin;
        queue<Node*> qNew;
        map<int, Node*> nodeList;
        map<int, Node*> newNodeList;
        qOrigin.push(node);
        qNew.push(ans);
        nodeList[node->val] = node;
        newNodeList[ans->val] = ans;

        while (!qOrigin.empty()) {
            Node *n = qOrigin.front();
            Node *m = qNew.front();
            qOrigin.pop();
            qNew.pop();

            for (int i = 0; i < n->neighbors.size(); ++i) {
                if (nodeList.find(n->neighbors[i]->val) == nodeList.end()) {
                    nodeList[n->neighbors[i]->val] = n->neighbors[i];
                    qOrigin.push(n->neighbors[i]);

                    Node *tmp = new Node;
                    tmp->val = n->neighbors[i]->val;
                    newNodeList[tmp->val] = tmp;
                    qNew.push(tmp);

                    m->neighbors.push_back(tmp);
                }
                else {
                    m->neighbors.push_back(newNodeList[n->neighbors[i]->val]);
                }
            }
        }

        return ans;
    }
};