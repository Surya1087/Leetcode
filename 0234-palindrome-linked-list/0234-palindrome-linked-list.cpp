class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if (!head || !head->next) return true;

        ListNode *slow = head, *fast = head;

        // finding middle of LL
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // reverse the second half of LL
        ListNode* prev = NULL;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // comparing 
        ListNode* left = head;
        ListNode* right = prev;

        while (right) {
            if (left->val != right->val) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};