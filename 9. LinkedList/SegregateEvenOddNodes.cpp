//brute
ListNode* oddEvenList(ListNode* head) {// tc:O(2N) sc:O(N)
        ListNode* temp = head;
        if(head == NULL || head->next == NULL) return head;
        vector<int> list;
        while(temp!=NULL && temp->next!=NULL){
            list.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) list.push_back(temp->val);
        temp = head->next;
        while(temp!=NULL && temp->next!=NULL){
            list.push_back(temp->val);
            temp = temp->next->next;
        }
        if(temp) list.push_back(temp->val);
        temp = head;
        int i = 0;
        while(temp!=NULL){
            temp->val = list[i];
            temp = temp->next;
            i++;
        }
        return head;

    }


//optimal
ListNode* oddEvenList(ListNode* head) {// tc:O(N)
        if(head == NULL || head->next == NULL) return head;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* evenHead = head->next; //save point for first even node

        while(even != NULL && even->next != NULL){
            odd->next = odd->next->next;
            even->next = even->next->next;

            odd = odd->next;    // move odd to its next
            even = even->next;
        }
        odd->next = evenHead;
        return head;
    ]
    }