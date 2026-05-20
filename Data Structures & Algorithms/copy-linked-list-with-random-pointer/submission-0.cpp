/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> mp;

        Node* curr = head;

        while (curr) {
            mp[curr] = new Node(curr->val);
            curr = curr->next;
        }

        curr = head;
        while (curr != nullptr) {
            if (curr->next != nullptr) {
                mp[curr]->next = mp[curr->next];
            } else {
                mp[curr]->next = nullptr;
            }

            if (curr->random != nullptr) {
                mp[curr]->random = mp[curr->random];
            } else {
                mp[curr]->random = nullptr;
            }

            curr = curr->next;
        }

        return mp[head];
    }
};
