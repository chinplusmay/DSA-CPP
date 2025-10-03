//https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
class Solution {
public:
    ListNode* reverseLL(ListNode* head){
        ListNode* temp = head;
        ListNode* prev = NULL;
        ListNode* front = NULL;
        while(temp != NULL){
            ListNode* front = temp->next;
            temp->next = prev;
            prev = temp;
            temp = front;
        }return prev;
    }

    ListNode* FindKthNode(ListNode* temp, int k){
        while(temp!=NULL){
            if(k == 1) break;
            k--;
            temp = temp->next;
        }return temp;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = head;
        ListNode* prevNode = NULL;

        while(temp != NULL){
            ListNode* Kth = FindKthNode(temp, k);
            if(Kth == NULL){
                if(prevNode) prevNode->next = temp;
                break;
            }
            else{
                nextNode = Kth->next;
                Kth->next = NULL;
                reverseLL(temp);
                if(temp == head){ // first kGroup
                    head = Kth;
                }
                else{
                    prevNode->next = Kth;
                }
                prevNode = temp;
                temp = nextNode;
            }
        }return head;
    }
};