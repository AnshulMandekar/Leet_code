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
private:

    ListNode* mid(ListNode* head){
        if (head == NULL || head->next == NULL){
            return head;
        }

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }

    ListNode* reverse(ListNode* head){
        if(head == NULL || head->next == NULL) {
            return head;
        }

        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* next = NULL;

        while(curr != NULL){
            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }
        return prev;
    }
public:
    bool isPalindrome(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return true;
        }
        ListNode* middle = mid(head);
        ListNode* secondHalf = reverse(middle);

        ListNode* firstHalf = head;
        ListNode* secondHalfCopy = secondHalf;

        while(secondHalfCopy  != NULL){
            if (firstHalf->val != secondHalfCopy->val){
                return 0;
            }
            firstHalf = firstHalf ->  next;
            secondHalfCopy = secondHalfCopy ->  next;
        }
        return 1;
    }
};
