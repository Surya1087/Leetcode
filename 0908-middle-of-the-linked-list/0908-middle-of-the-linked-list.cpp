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
    ListNode* middleNode(ListNode* head) {
       
        int count = 0;
        ListNode* temp = head;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        
       
        int midIndex = count / 2;
        
        
        temp = head;
        for (int i = 0; i < midIndex; i++) {
            temp = temp->next;
        }
        
        return temp; 
    }
};
/*
class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;       // Move 1 step
            fast = fast->next->next; // Move 2 steps
        }
        
        return slow; // When fast reaches end, slow is at middle
    }
};
*/
