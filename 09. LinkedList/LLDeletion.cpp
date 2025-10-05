#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* next;

        Node(int data1, Node* next1){
            data = data1;
            next = next1;
        }

        Node(int data1){ // when next value not given next->nullptr
            data = data1;
            next = nullptr;
        }
};

Node* Arr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i = 1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}

Node* removeHead(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    head = head->next;
    delete temp;
    return head;
}

Node* removeTail(Node* head){
    if(head == nullptr) return head;
    Node* temp = head;
    while(temp->next->next != nullptr){
        temp = temp->next;
    }
    delete temp->next;
    temp->next = nullptr;
    return head;
}

Node* removeK(Node* head, int k){ 
    if(head == NULL) return head;
    if(k==1){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    int cnt = 0;
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        cnt++;
        if(cnt == k){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }return head;
}

Node* removeEl(Node* head, int El){ 
    if(head == NULL) return head;
    if(head->data == El){
        Node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    Node* temp = head;
    Node* prev = NULL;
    while(temp != NULL){
        if(temp->data == El){
            prev->next = prev->next->next;
            delete temp;
            break;
        }
        prev = temp;
        temp = temp->next;
    }return head;
}





int main(){
    vector<int> a = {1,2,3,45,22,11,34};
    Node* head = Arr2LL(a);
    // cout<< head -> next;

    // traverse through the ll
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;

    // rmov from beginning
    // head = removeHead(head);
    // cout<<head->data<<endl;

    // rmov from end
    // head = removeTail(head);
    // Node* ptr = head;
    // while(ptr->next != nullptr){
    //     ptr = ptr->next;
    // }
    // cout<<ptr->data<<endl;

    // rmov kth element
    // head = removeK(head, 3);
    // Node* temp = head
    // while(temp != nullptr){
    //     cout<< temp->data <<" ";
    //     temp = temp->next;
    // }
    // cout<<endl;

    // rmov Elemnt element
    head = removeEl(head, 45);
    Node* temp1 = head;
    while(temp1 != NULL){
        cout<< temp1->data <<" ";
        temp1 = temp1->next;
    }
    cout<<endl;



}