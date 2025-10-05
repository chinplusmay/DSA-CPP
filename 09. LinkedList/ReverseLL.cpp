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
//brute stack
Node* Brute(Node* head){
    stack<int> st;
    Node* temp = head;
    while(temp != NULL){
        st.push(temp->data);
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL){
        temp->data = st.top();
        temp=temp->next;
        st.pop();
    }
    return head;
}

//optimal prev front
Node* Optimal(Node* head){
    Node* prev = NULL;
    Node* temp = head;
    while(temp!=NULL){
        Node* front = temp->next;
        temp->next = prev;
        prev = temp;
        temp = front;
    }
    return prev;
}



//Optimal recursive
Node* Recursive(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    Node* newHead = Recursive(head->next);
    Node* front = head->next;
    front->next = head;
    head->next = NULL;
    return newHead;
}


int main(){
    vector<int> a = {1,2,3,4};  //3
    Node* head = Arr2LL(a);

    head = Optimal(head);
    Node* temp = head;
    while(temp != nullptr){
        cout<< temp->data <<" ";
        temp = temp->next;
    }
}