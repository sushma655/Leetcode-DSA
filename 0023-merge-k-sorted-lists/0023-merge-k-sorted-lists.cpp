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

        // Min heap: smallest node first
        priority_queue<ListNode*, vector<ListNode*>,
            decltype([](ListNode* a, ListNode* b) {
                return a->val > b->val;
            })> pq;

        // Har list ka first node heap mein daalo
        for (ListNode* node : lists) {
            if (node != nullptr) {
                pq.push(node);
            }
        }

        ListNode dummy(0);
        ListNode* tail = &dummy;

        while (!pq.empty()) {

            // Smallest node nikalo
            ListNode* smallest = pq.top();
            pq.pop();

            // Result list mein jodo
            tail->next = smallest;
            tail = tail->next;

            // Us list ka next node heap mein daalo
            if (smallest->next != nullptr) {
                pq.push(smallest->next);
            }
        }

        return dummy.next;
    }
};