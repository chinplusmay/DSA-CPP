// leetcode https://leetcode.com/problems/palindrome-linked-list/

ListNode* RecursiveReverse(ListNode* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    ListNode* newHead = RecursiveReverse(head->next);
    ListNode* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}
    bool isPalindrome(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode* newHead = RecursiveReverse(slow->next);
        ListNode* first = head;
        ListNode* second = newHead;
        while(second != NULL){
            if(first->val != second->val){
                RecursiveReverse(newHead);
                return false;
            }
            first = first->next;
            second = second->next;
        }return true;
    }