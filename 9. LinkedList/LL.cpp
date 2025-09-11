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

int main(){
    vector<int> a = {1,2,3,45};
    Node* y = new Node(a[0], nullptr);
    cout<< y -> next;
}