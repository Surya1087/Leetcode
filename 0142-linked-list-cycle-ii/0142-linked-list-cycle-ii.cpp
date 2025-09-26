/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> seen;

        while (head) {
            if (seen.find(head) != seen.end()) {
                return head;
            }
            seen.insert(head);
            head = head->next;
        }

        return nullptr;
    }
};
/*
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) break;
        }

        if (!fast || !fast->next) return nullptr;

        fast = head;
        while (fast != slow) {
            fast = fast->next;
            slow = slow->next;
        }

        return slow;        
    }
};
*/
