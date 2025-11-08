#include <bits/stdc++.h>
using namespace std;

int priority(char ch){
    if(ch == '^') return 3;
    else if(ch == '*' || ch == '/') return 2;
    else if(ch == '+' || ch == '-') return 1;
    else return 0;
}

string Infix2Postfix(string s){
    int i = 0;
    int n = s.size();
    stack<char> st;
    string ans;

    while(i<n){
        // for operands (Aa to Zz or 1 to 9)
        if(
            (s[i]>='A' && s[i]<='Z') ||
            (s[i] >= 'a' && s[i]<='z') ||
            (s[i]>='1' && s[i]<='9')
        ){
            ans = ans+s[i];
        }
        
        // for parenthesis
        else if(s[i] == '('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop(); // top pop out the (
        }

        // for operators
        else{
            while (!st.empty() && 
                ((priority(s[i]) < priority(st.top())) || 
                (priority(s[i]) == priority(st.top()) && s[i] != '^'))){

                    ans += st.top();
                    st.pop();
            }
            st.push(s[i]);
        }
        i++; 
    }
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    return ans;
}

string Infix2Prefix(string s){   // reverse s -> in to post -> reverse ans
    int i = 0;
    int n = s.size();
    stack<char> st;
    string ans;

    reverse(s.begin(), s.end());

    while(i<n){
        if(s[i] >= 'A' && s[i] <= 'Z' ||
            s[i] >= 'a' && s[i] <= 'z' ||
            s[i] >= '1' && s[i] <= '9'){
                ans += s[i];
        }

        else if(s[i] == '('){
            st.push(s[i]);
        }

        else if(s[i] == ')'){
            while(!st.empty() && st.top() != '('){
                ans += st.top();
                st.pop();
            }
            st.pop();
        }

        else{
            while(!st.empty() &&
                (
                    (priority(s[i]) < priority(st.top() )) ||
                    (priority(s[i]) == priority(st.top() && st.top() != '^'))
                )
            ){
                ans += st.top();
                st.pop();
            }
            st.push(s[i]);
        }
        i++;
    }

    while(!st.empty()){
        ans += st.top();
        st.pop();
    }

    reverse(ans.begin(), ans.end());
    return ans;
}


string Postfix2Infix(string s) {
    stack<string> st;
    int i = 0;

    while(i<s.size()){
        // Operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        else { // Operator

            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res = "(" + t2 + s[i] + t1 + ")";
            st.push(res);
        }
        i++;
    }
    return st.top();
}

string Prefix2Infix(string s) {
    stack<string> st;
    int i = s.size()-1;
    // Must process prefix from RIGHT → LEFT
    while(i>=0){
        // Operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        else { // Operator

            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res = "(" + t1 + s[i] + t2 + ")";
            st.push(res);
        }
        i--;
    }
    return st.top();
}

string Postfix2Prefix(string s) {
    stack<string> st;
    int i = 0;

    while(i<s.size()){
        // Operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        else { // Operator

            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res =  s[i] + t2 + t1 ;
            st.push(res);
        }
        i++;
    }
    return st.top();
}

string Prefix2Postfix(string s) {
    stack<string> st;
    int i = s.size()-1;
    // Must process prefix from RIGHT → LEFT
    while(i>=0){
        // Operand
        if ((s[i] >= 'A' && s[i] <= 'Z') ||
            (s[i] >= 'a' && s[i] <= 'z') ||
            (s[i] >= '0' && s[i] <= '9')) {
            st.push(string(1, s[i]));
        }
        else { // Operator

            string t1 = st.top(); st.pop();
            string t2 = st.top(); st.pop();

            string res =  t1 + t2 + s[i];
            st.push(res);
        }
        i--;
    }
    return st.top();
}




int main(){
    string s = "a^b^c";
    string spost = "ab+c*";
    string spre = "*+AB-CD";

    cout<<Infix2Postfix(s)<<endl;
    cout<<Infix2Prefix(s)<<endl;

    cout<<Postfix2Infix(spost)<<endl;
    cout<<Prefix2Infix(spre)<<endl;

    cout<<Postfix2Prefix(spost)<<endl;
    cout<<Prefix2Postfix(spre)<<endl;


}