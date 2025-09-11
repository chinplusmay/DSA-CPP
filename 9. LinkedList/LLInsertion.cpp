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

Node* InsertAtBeginning(Node* head,int data){
    Node* temp = new Node(data, head);
    return temp;
}

Node* InsertAtEnd(Node* head,int data){
    if(head == NULL) return new Node(data);
    Node* tempNode = new Node(data, head);
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = tempNode;
    tempNode->next = nullptr;
    return head;
}

Node* InsertAtK(Node* head,int data, int k){
    if(head == NULL){
        if(k==1) return new Node(data);
    }
    else{
        return head;
    }

    if(k==1){
        Node* newHead = new Node(data, head);
        return newHead;
    }
    int cnt = 0;
    Node* temp = head;
    while(temp != NULL){
        cnt++;
        if(cnt == k-1){
            Node* x = new Node(data, temp->next);
            temp->next = x;
            break;
        }
        temp=temp->next;
    }return head;

}


int main(){
    vector<int> a = {1,2,3,45,22,11,34};
    Node* head = Arr2LL(a);

    head = InsertAtBeginning(head, 5);
    head = InsertAtEnd(head, 55);

    // traverse through the ll
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
    cout<<endl;
}