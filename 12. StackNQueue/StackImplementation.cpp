#include <bits/stdc++.h>
using namespace std;
// using arrays
class Stack{
    int top;
    int size;
    int *st;
    
    public:
        Stack(int n){
            size = n;
            top = -1;
            st = new int[size];
        }

        int topEle(){
            if(top == -1) return -1;
            return st[top];
        }

        void push(int x){
            if(top == size-1){
                cout << "Stack overflow\n";
                return;
            }
            st[++top] = x;
        }

        int pop(){
            if(top == -1){
                cout << "Stack underflow\n";
                return -1;
            }
            return st[top--];
        }

        int getSize(){
            return top+1;
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

class StackLL{
    Node* top;
    int size;
    
    public:

    StackLL() {
    top = nullptr; 
    size = 0;
    }

    void push(int x){
        Node* temp = new Node(x);
        temp->next = top;
        top = temp;
        size++;
    }

    int pop(){
        if(top == nullptr){  // or size==0
            cout<<"Stack Underflow";
            return -1;
        }
        Node* temp = top;
        int rmdata = temp->data;
        top = top->next;
        delete temp;
        size--;
        return rmdata;
    }
    
};

// using queue

class StackQ{

    public:

    queue<int> q;
    int s = 0;

    void push(int x){
        int s = q.size();
        q.push(x);
        for(int i = 1; i<=s; i++){
            q.push(q.front());
            q.pop();
        }
    }

    int pop(){
        if(q.empty()){
            cout<< "Stack Underflow" << endl;
            return -1;
        }
        
        int a = q.front();
        q.pop();           
        return a; 
    }
    int top(){
        return q.front();
    }
   
};

int main(){
    // array
    // Stack st(3);
    // st.push(1);
    // st.push(2);
    // cout<<st.pop();
    // cout<<st.topEle();

    // LL
    StackLL st;
    st.push(2);
    cout << st.pop() << endl;   
    cout << st.pop() << endl;
    
}