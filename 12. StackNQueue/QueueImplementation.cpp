#include <bits/stdc++.h>
using namespace std;
// using array
class Queue{
    int * arr;
    int size;
    int currsize;
    int start, end;

    public:

    Queue(int n){
        size = n;
        arr = new int[size];
        start = -1;
        end = -1;
        currsize=0;
    }

    void push(int x){
        if(currsize == size){
            cout << "Queue overflow\n";
            return;
        }
        if(currsize == 0){
            start++;
            end++;
            arr[end] = x;
            currsize++;
        }
        else{
            end = (end+1) % size;
            arr[end] = x;
            currsize++;
        }
    }

    int pop(){
        if(currsize == 0){
            cout << "Queue underflow\n";
            return -1;
        }
        int ele = arr[start];

        if(currsize == 1){
            start = -1;
            end = -1;
            currsize = 0;
        }
        else{
            start = (start+1) % size;
            currsize--;
        }
        return ele;
    }
};

// using LL
class Node{
    public:
    int data;
    Node* next;
    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
    Node(int data1){
        data = data1;
        next = nullptr;
    }
};
class QueueLL{
    Node *start, *end;
    int size;
    public:
    QueueLL(){
        start = nullptr;
        end = nullptr;
        size = 0;
    }

    void push(int x){
        Node *temp = new Node(x);
        if(start == nullptr){
            start = end = temp;
        }
        else{
            end->next = temp;
        }
        size++;
    }

    int pop(){
        if(start == nullptr){
            cout<<"Stack Underflow";
            return -1;
        }
        else{
            Node *temp = start;
            int rmdata = temp->data;
            start = start->next;
            delete temp;
            return rmdata;
        }
    }

};

//using Stack

class QueueS{
    public:

    stack<int> st1, st2;
    int s = 0;

    void push(int x){
        
        while(st1.size()){
            st2.push(st1.top());
        }

        st1.push(x);

        while(st2.size()){
            st1.push(st2.top());
        }
    }

    int pop(){
        if(!st1.size()){
            cout<<"Queue Underflow";
            return -1;
            exit(0);
        }
        int rmdata = st1.top();
        st1.pop();
        return rmdata;
    }


};


int main(){
    // Queue q(4);
    // q.push(2);
    // q.push(3);
    // q.pop();
    // q.pop();
    // q.push(6);
    // cout<<q.pop();
    // cout<<q.pop();

    // QueueLL q;
    // q.push(3);
    // cout<<q.pop();
    // cout<<q.pop();

    QueueS q;
    q.push(3);
    cout<<q.pop();

}