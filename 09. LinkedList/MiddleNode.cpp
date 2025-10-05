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

//brute
Node* middleNode1(Node* head){ //tc: O(N)
    if(head == NULL || head->next == NULL) return head;
    Node* temp = head;  
    int cnt = 0;
    while(temp != NULL){ //O(N)
        cnt++;
        temp = temp->next;
    }
    int k = (cnt/2 + 1); //middle index
    temp = head;
    for(int i = 1; i<k; i++){ //O(N/2)
        temp = temp->next;
    }
    return temp;
}

//optimal hare and tortoise
Node* middleNode2(Node* head){ //tc: O(N/2)
    if(head == NULL || head->next == NULL) return head;
    Node* fast = head;
    Node* slow = head;
    while(fast != NULL && fast->next != NULL){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main(){
    vector<int> a = {1,2,3,4};  //3
    Node* head = Arr2LL(a);

    head = middleNode2(head);
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}