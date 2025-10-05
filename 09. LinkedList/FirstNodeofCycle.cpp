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

//brute
bool hasCycle(Node *head){ //tc:O(N * 2 * log(N))
        Node* temp = head;
        map<Node* , int> mp;
        while(temp != NULL){
            mp[temp] += 1;
            if(mp[temp] > 1){
                return true;
            }
            temp=temp->next;
        }return false;
}

//optimal
bool hasCycle(Node *head) { //hare and tortoise //tc:O(N)
        Node* slow = head;
        Node* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }return false;
}

int main(){
    //go on leetcode
}