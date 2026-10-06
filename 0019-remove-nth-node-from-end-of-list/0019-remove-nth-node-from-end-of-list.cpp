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

        // Dummy node
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* slow = dummy;
        ListNode* fast = dummy;

        // Fast ko n steps aage le jao
        for (int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // Dono pointers ko saath move karo
        while (fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }

        // Slow ke next node ko delete karo
        ListNode* temp = slow->next;
        slow->next = slow->next->next;

        delete temp;

        return dummy->next;
    }
};