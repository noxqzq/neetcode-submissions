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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Dummy node handles the "remove head" case cleanly
        ListNode dummy(0, head);
        ListNode* fast = &dummy;
        ListNode* slow = &dummy;

        // Move fast n steps ahead
        for (int i = 0; i < n; i++) {
            fast = fast->next; // n is valid per problem constraints
        }

        // Move both until fast is at the last node
        while (fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }

        // slow->next is the node to remove
        ListNode* del = slow->next;
        slow->next = del->next;
        del->next = nullptr; // optional (clean unlink)
        // delete del; // optional on LeetCode (they usually don't require manual delete)

        return dummy.next;
    }
};
